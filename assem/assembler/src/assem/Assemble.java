package assem;

import java.util.*;
import java.awt.image.BufferedImage;
import java.io.*;

public class Assemble {
	
	/*
	|--------------------------------------------------------------------------
	| CONSTANTS
	|--------------------------------------------------------------------------
	|
	| These constants are used to set the assembly code formatting, such as
	| comments, label format, etc. as well as the output machine code
	| format such as bit widths.
	|
	*/
	
	// memory size constants
	private static final int SCREEN_MEM_SIZE 	  	= 8 * 1024;
	private static final int GLYPH_MEM_SIZE			= 1024;
	private static final int TEXT_MEM_SIZE 	  		= 8 * 1024;
	private static final int DATA_MEM_SIZE			= 2* 1024;
	private static final int INPUT_MEM_SIZE 	  	= 512;
	private static final int OUTPUT_MEM_SIZE		= 512;
	private static final int STACK_MEM_SIZE 	  	= 8 * 1024;
	
	// memory address constants
	private static final int SCREEN_MEM_ADDR 	  	= 0;
	private static final int GLYPH_MEM_ADDR			= SCREEN_MEM_ADDR + SCREEN_MEM_SIZE;
	private static final int TEXT_MEM_ADDR			= GLYPH_MEM_ADDR + GLYPH_MEM_SIZE;
	private static final int DATA_MEM_ADDR			= TEXT_MEM_ADDR + TEXT_MEM_SIZE;
	
	// lines list position constants
	private static final int LINE_NUMBER_POSITION 	= 0; // position in lines list (source line number)
	private static final int LABEL_POSITION 	  	= 1; // position in lines list
	private static final int FUNCTION_POSITION 	  	= 2; // position in lines list
	
	private static final int RTYPE_DST_REG_POSITION = 3;
	private static final int RTYPE_SRC_REG_POSITION = 4;
	
	private static final int ITYPE_DST_REG_POSITION = RTYPE_DST_REG_POSITION;
	private static final int ITYPE_IMM_POSITION		= RTYPE_SRC_REG_POSITION;
	
	private static final int MTYPE_DST_REG_POSITION = RTYPE_DST_REG_POSITION;
	private static final int MTYPE_MEM_REG_POSITION = RTYPE_SRC_REG_POSITION;
	private static final int MTYPE_BANK_POSITION 	= 5;
	
	private static final int JTYPE_ADDR_POSITION 	= RTYPE_DST_REG_POSITION;
	
	// regex patterns
	private static final String LABEL_FORMAT 		= "^\\D.*"; // labels cannot start with a digit
	private static final String WHITE_SPACE_PATTERN = "[ \t]"; // spaces and tabs
	private static final String LABEL_DELIMITER 	= ":"; // colon
	private static final String DELIMITER_PATTERN 	= "[ |\t|,]"; // spaces, tabs, and commas
	private static final String SPECIAL_FUNC_PREFIX = "."; // period
	private static final String COMMENT 			= "#"; // slash slash
	private static final String HEX_PREFIX 			= "0x";
	private static final String REG_PREFIX	    	= "$";
	private static final String REG_PREFIX_CHAR 	= "r";
	private static final String REG_PATTERN    		= REG_PREFIX_CHAR + "[0-9]+";
	private static final String ZERO_REG			= "zero";
	private static final String SP_REG				= "sp";
	private static final String RET_REG				= "ret";
	private static final String RA_REG				= "ra";
	private static final String AT_REG 				= "at";
	
	// encoding bit widths
	private static final int OPCODE_BIT_WIDTH		= 2;
	private static final int REG_BIT_WIDTH			= 4;
	
	// bit widths (use for max value error checking)
	private static final int JUMP_ADDRESS_BIT_WIDTH = 11; // max jump address = 2^11
	private static final int IMMEDIATE_BIT_WIDTH    =  7; // max immediate value = 2^7
	private static final int IMMEDIATE_MAX_VALUE    =  127; // max immediate value = 2^7
	private static final int BANK_BIT_WIDTH 		=  5; // max bank size = 2^5
	private static final int MAX_VALUE				= 65535; // max register size = 2^16
	
	
	// instruction mappings include opcode and instruction code
	private static final int RTYPE_OPCODE 			= 0;
	private static final int ITYPE_OPCODE 			= 1;
	private static final int MTYPE_OPCODE 			= 2;
	private static final int JTYPE_OPCODE 			= 3;
	
	private static final int OP_CODE_POSITION 		= 0;
	private static final int INSTR_CODE_POSITION 	= 1;
	private static final Map<String, Integer[]> InstructionOpCodes = new HashMap<>();
	
	static {		
		// rType instructions
		InstructionOpCodes.put("add",   new Integer[] {RTYPE_OPCODE, 0});
		InstructionOpCodes.put("sub",   new Integer[] {RTYPE_OPCODE, 1});
		InstructionOpCodes.put("comp",  new Integer[] {RTYPE_OPCODE, 1});
		InstructionOpCodes.put("and",   new Integer[] {RTYPE_OPCODE, 2});
		InstructionOpCodes.put("or",    new Integer[] {RTYPE_OPCODE, 3});
		InstructionOpCodes.put("xor",   new Integer[] {RTYPE_OPCODE, 4});
		InstructionOpCodes.put("sll",   new Integer[] {RTYPE_OPCODE, 5});
		InstructionOpCodes.put("srl",   new Integer[] {RTYPE_OPCODE, 6});
		InstructionOpCodes.put("sra",   new Integer[] {RTYPE_OPCODE, 7});

		// iType instructions
		InstructionOpCodes.put("addi",  new Integer[] {ITYPE_OPCODE, 0});
		InstructionOpCodes.put("subi",  new Integer[] {ITYPE_OPCODE, 1});
		InstructionOpCodes.put("compi", new Integer[] {ITYPE_OPCODE, 1});
		InstructionOpCodes.put("andi",  new Integer[] {ITYPE_OPCODE, 2});
		InstructionOpCodes.put("ori",   new Integer[] {ITYPE_OPCODE, 3});
		InstructionOpCodes.put("xori",  new Integer[] {ITYPE_OPCODE, 4});
		InstructionOpCodes.put("slli",  new Integer[] {ITYPE_OPCODE, 5});
		InstructionOpCodes.put("lui",   new Integer[] {ITYPE_OPCODE, 6});
		InstructionOpCodes.put("lli",   new Integer[] {ITYPE_OPCODE, 7});
		
		// mType instructions
		InstructionOpCodes.put("read",  new Integer[] {MTYPE_OPCODE, 0});
		InstructionOpCodes.put("write", new Integer[] {MTYPE_OPCODE, 1});
		
		// jType instructions
		InstructionOpCodes.put("jl",    new Integer[] {JTYPE_OPCODE, 0});
		InstructionOpCodes.put("jeq",   new Integer[] {JTYPE_OPCODE, 1});
		InstructionOpCodes.put("jne",   new Integer[] {JTYPE_OPCODE, 2});
		InstructionOpCodes.put("jal",   new Integer[] {JTYPE_OPCODE, 3});
		InstructionOpCodes.put("jr",    new Integer[] {JTYPE_OPCODE, 4});
		InstructionOpCodes.put("jlt",   new Integer[] {JTYPE_OPCODE, 5});
		InstructionOpCodes.put("jleq",  new Integer[] {JTYPE_OPCODE, 6});
	}
	
	private static final Map<String, String> PseudoInstructions = new HashMap<>();
	
	static {
		PseudoInstructions.put("li", "li");
		PseudoInstructions.put("mov", "mov");
		PseudoInstructions.put("push", "push");
		PseudoInstructions.put("pop", "pop");
		
		PseudoInstructions.put("beq", "beq");
		PseudoInstructions.put("bne", "bne");
		PseudoInstructions.put("blt", "blt");
		PseudoInstructions.put("bleq", "bleq");
		
		PseudoInstructions.put("bgt", "bgt");
		PseudoInstructions.put("bgeq", "bgeq");
		
		PseudoInstructions.put("beqi", "beqi");
		PseudoInstructions.put("bnei", "bne");
		PseudoInstructions.put("blti", "blti");
		PseudoInstructions.put("bleqi", "bleqi");
	}
	
	// assembler variables
	// list of lines stored in this format: <line#>, <label>?, <instruction>, <arguments>
	private static List<List<String>> lines = new ArrayList<>(); 
    //private static List<String> output = new ArrayList<>(); // list of final bits to output
	private static List<String> screenMem = new ArrayList<>(); // list of final bits to output
	private static List<String> glyphMem = new ArrayList<>(); // list of final bits to output
	private static List<String> textMem = new ArrayList<>(); // list of final bits to output
	private static List<String> dataMem = new ArrayList<>(); // list of final bits to output
	private static Map<String, Integer> labels = new HashMap<>(); // labels mapped to line address
	private static Map<String, Integer> globals = new HashMap<>(); // globals mapped to memory address
	private static boolean processingDataSection = false;
	private static int globalPointer = DATA_MEM_ADDR;
	private static boolean error = false;
	
	// help description
	private static final String HELP = "Assemble - TEAK assembler v0.1 \n\n"
									 + "usage: Assemble <.teak file> <.coe output file>? <output radix>? \n\n"
									 + "arguments: \n"
									 + "\t <.teak file> \t\t the name of a .teak assembly file to assemble into machine code (bits) \n"
									 + "\t <.coe output file> \t (optional) the name of a .coe file to write machine code to (defaults to 'mem.coe') \n"
									 + "\t <output radix> \t (optional) bit radix to use, 2 (binary) or 16 (hexadecimal, default) \n";

	/*
	|--------------------------------------------------------------------------
	| MAIN
	|--------------------------------------------------------------------------
	|
	| Assembler entry point
	| Arg options:
	|	arg0 = assembly file input (required)
	| 	arg1 = output memory file (optional, default = mem.coe)
	|	arg2 = output memory radix (optional, default = 2 [binary])
	|
	*/
	
	public static void main(String[] args) {
		
		String assemblyFile = null;
		String outputFile = "mem.coe"; // default
		int outputRadix = 16; // default
		
		// set parameters based on input arguments
		switch(args.length) {
			case 0:
				System.out.println(HELP); // print help description
				return;
			case 3:
				outputRadix = Integer.parseInt(args[2]);
			case 2:
				outputFile = args[1];
			case 1:
				assemblyFile = args[0];
				break;
		}
		
		//assemblyFile = "branch-beq.teak";
		//assemblyFile = "pseudo-test.teak";
		
		System.out.format("Assembling '%s' into '%s' (using radix %d) \n", assemblyFile, outputFile, outputRadix);
		long start = System.currentTimeMillis(); // time execution time and report
		
		// work
		tokenize(assemblyFile); // split each line into tokens (labels, functions, registers, etc.)	
		initialize(); // run any special .initializers before anything else
		map(); // map labels to a corresponding label address
		encode(); // encode instructions and operators into machine code (bits)
		
		if (!error) {
			int size = generateMemory(outputFile, outputRadix); // write resulting machine code to .coe file
			
			// prints out instructions
			String repeated = new String(new char[62]).replace("\0", "-");
			System.out.format("\nInstructions found: %d\n", lines.size());
			System.out.println(repeated);
			System.out.format("%-10s %-10s %-10s %-10s %-10s %-10s\n", "Line #", "Label", "Instr", "Oper1", "Oper2", "Oper3");
			System.out.println(repeated);
			for (List<String> l : lines) {
				for (String s : l)
					System.out.format("%-11s", s);
				System.out.println();
			}
			System.out.println();
			
			if (labels.size() != 0) { // prints our labels
				System.out.format("Labels found: %d\n", labels.size());
				System.out.println(repeated);
				System.out.format("%-20s %-20s\n", "Label", "Label Addr");
				System.out.println(repeated);
				labels.forEach((k,v)->System.out.format("%-20s %-20d\n", k, v));
				System.out.println();
			}
			
			if (globals.size() != 0) { // prints out global variables
				System.out.format("Global variables found: %d\n", globals.size());
				System.out.println(repeated);
				System.out.format("%-20s %-20s\n", "Variable", "Mem Addr");
				System.out.println(repeated);
				globals.forEach((k,v)->System.out.format("%-20s %-20d\n", k, v));
				System.out.println();
			}
			
			long end = System.currentTimeMillis();
			double time = (end-start)/1000d; // display execution time in seconds
			System.out.format("Done \nWrote %d words to '%s' in %.3fs \n", size, outputFile, time);
		}
		
		
		return;
	}
	
	/*
	|--------------------------------------------------------------------------
	| ASSEMBLY FUNCTIONS
	|--------------------------------------------------------------------------
	|
	| These functions are generally helper functions when parsing the assembly
	| source code including tokenizers, label mapping, etc.
	|
	*/

	/**
	 * Tokenizes each line by storing each parameter into a list
	 * Most of this work is done in parseLine
	 * @param assemblyFile
	 */
	private static void tokenize(String assemblyFile) {
		// open file and parse
		try {
			// open file
			FileReader fileReader = new FileReader(assemblyFile);
			BufferedReader reader = new BufferedReader(fileReader);
			
			String line = null;
			
			// loop through lines and parse
			int lineNumber = 1; // keep track of lines for debugging
			while( (line = reader.readLine()) != null) {
				line = format(line); // cleans line of whitespace and comments
				if (!line.isEmpty()) { // only operate on lines with text
					parseLine(line, lineNumber++);
				}
				else
					lineNumber++;
			}
			
			reader.close();
			
		} catch (FileNotFoundException e) {
			System.out.println("Unable to open " + assemblyFile + ": " + e);
		} catch (IOException e) {
			System.out.println("I/O exception while reading line in  " + assemblyFile + ": " + e);
		}
		
		return;
	}
	
	/**
	 * Parses the given line and stores each parameter into a list which
	 * is subsequently stored in the lines list. Note that the first
	 * element of a line is a label. If no label is given then the first
	 * element will be a blank string
	 * @param line
	 */
	private static void parseLine(String line, int lineNumber) {
		// split by labels (keep : delimiter)
		ArrayList<String> tokens = new ArrayList<>(Arrays.asList(line.split("(?<=" + LABEL_DELIMITER + ")")));
		
		List<String> lineList = new ArrayList<>(); // list of parameters on line
		lineList.add(String.format("%d", lineNumber));
		
		boolean addLine = true; // for use if instruction is a psuedo instruction
		
		// first element in line is defined as a label
		// if no label exist, a blank string is stored in the first element
		if (tokens.get(0).endsWith(LABEL_DELIMITER) || tokens.get(0).startsWith(SPECIAL_FUNC_PREFIX)) {
			
			if (tokens.get(0).equals(".teak"))
				processingDataSection = false;
			
			if (!processingDataSection) {
				lineList.add(clean(tokens.get(0).replaceAll(LABEL_DELIMITER, "").trim().toLowerCase()));
				tokens.remove(0); // remove label from tokens to make parsing args easier
			}
			else {
				lineList.add(clean(tokens.get(0).replaceAll(LABEL_DELIMITER, "").trim().toLowerCase()));
				lineList.add(tokens.get(1).trim());
				tokens.remove(0); // remove label from tokens to make parsing args easier
				tokens.remove(0);
				processGlobalVar(lineList);
				return;
			}
			
			if (lineList.get(1).matches(".data")) {
				processingDataSection = true;
				return;
			}
		}
		else // if there is no label, add blank string
			lineList.add("");
		
		// parse and store args into lineList
		if (tokens.size() > 0) {
			
			// args can be space, comma, or tab delimited
			String[] args = tokens.get(0).split(DELIMITER_PATTERN);
			
			for (String a : args) {
				if (!a.isEmpty()) {
					// if token is a global label, replace with memory address
					if (globals.containsKey(a)) {
						a = String.format("%d", globals.get(a));
					}
					lineList.add(clean(a.toLowerCase())); // add all parameters
				}
			}
			
			// if instruction is a psuedo instruction, replace with corresponding instruction(s) and
			// don't add line to lies (it will be added in the expandPsuedoInstructions method)
			if (PseudoInstructions.containsKey(lineList.get(FUNCTION_POSITION))) {
				addLine = expandPsuedoInstruction(lineList, lineNumber);
			}
		}
		
		if (addLine)
			lines.add(lineList); // add this line the the lines list
		
		return;
	}
	
	/**
	 * Parses .data global section for string variables and maps them to a memory address
	 * @param lineList to find gloab variable in (will be one line)
	 */
	private static void processGlobalVar(List<String> lineList) {
		
		if (lineList.get(FUNCTION_POSITION).matches("^\".*\"$")) { // string match
			globals.put(lineList.get(LABEL_POSITION), globalPointer);
			String str = lineList.get(FUNCTION_POSITION).replaceAll("\"", "");
			for (Character c : str.toCharArray()) {
				dataMem.add(convertImmToBinary((int) c, 16));
				globalPointer++;
			}
			dataMem.add(convertImmToBinary(0, 16)); // null terminator
			globalPointer++;
		}
		else if (lineList.get(FUNCTION_POSITION).startsWith(".size")) { // .size command
			globals.put(lineList.get(LABEL_POSITION), globalPointer);
			String sizeStr = lineList.get(FUNCTION_POSITION).replaceAll(".size", "").trim(); // get size
			int size = parseImmediate(sizeStr);
			for (int i = 0; i < size; i++) {
				dataMem.add(convertImmToBinary(0, 16));
				globalPointer++;
			}
		} 
		else if (lineList.get(FUNCTION_POSITION).matches("^\\{.*\\}$")) { // array of values
			globals.put(lineList.get(LABEL_POSITION), globalPointer);
			String str = lineList.get(FUNCTION_POSITION).replaceAll("\\{", "").replaceAll("\\}", "");
			for (String s : str.split(",")) {
				dataMem.add(convertImmToBinary(parseImmediate(s.trim()), 16));
				globalPointer++;
			}
		}
		else { // single value
			globals.put(lineList.get(LABEL_POSITION), globalPointer);
			int value = parseImmediate(lineList.get(FUNCTION_POSITION));
			dataMem.add(convertImmToBinary(value, 16));
			globalPointer++;
		}
		
	}
	
	/**
	 * Expands a psuedo instruction into the one or more supported instructions
	 * Code is tightly coupled with supported instructions so be cautious about modifying this function
	 * @param lineList of a line containing a pseudo instruction
	 * @param lineNumber of currently processed line
	 * @return boolean (always false) indicating to not add the psuedo instruction line in parseLine method
	 */
	private static boolean expandPsuedoInstruction(List<String> lineList, int lineNumber) {
		
		String label = lineList.get(LABEL_POSITION);
		String intermediateReg = REG_PREFIX + AT_REG; // use to prevent overwriting reg1
		String func = lineList.get(FUNCTION_POSITION);
		String reg1 = null;
		String reg2 = null;
		String jlabel = null;
		String sImm = null;
		List<String> first = new ArrayList<>();
		List<String> second = new ArrayList<>();
		List<String> third = new ArrayList<>();
		List<String> fourth = new ArrayList<>();
		
		// branching instruction setup
		if (func.equals("beq")  || func.equals("bne") || func.equals("blt") || 
			func.equals("bleq") || func.equals("bgt") || func.equals("bgeq") ) {
			
			reg1 = lineList.get(RTYPE_DST_REG_POSITION);
			reg2 = lineList.get(RTYPE_SRC_REG_POSITION);
			jlabel = lineList.get(MTYPE_BANK_POSITION);
			
			if (!reg2.equals("$zero") && !reg2.equals("$0")) {
				// mov
				first.add(String.format("%d", lineNumber));
				first.add(label);
				first.add("sub");
				first.add(intermediateReg);
				first.add(intermediateReg);
				
				second.add(String.format("%d", lineNumber));
				second.add("");
				second.add("add");
				second.add(intermediateReg);
				second.add(reg1);
				
				// compare
				third.add(String.format("%d", lineNumber));
				third.add("");
				third.add("comp");
				third.add(intermediateReg);
				third.add(reg2);
			}
			else {
				// compare
				third.add(String.format("%d", lineNumber));
				third.add(label);
				third.add("comp");
				third.add(reg1);
				third.add(reg2);
			}
			
			
		} 
		else if (func.equals("beqi") || func.equals("bnei") || 
				 func.equals("blti") || func.equals("bleqi")) {
			
			reg1 = lineList.get(RTYPE_DST_REG_POSITION);
			sImm = lineList.get(ITYPE_IMM_POSITION);
			jlabel = lineList.get(MTYPE_BANK_POSITION);
			
			if (!sImm.equals("0") && !sImm.equals("0x0")) {
				// mov
				first.add(String.format("%d", lineNumber));
				first.add(label);
				first.add("sub");
				first.add(intermediateReg);
				first.add(intermediateReg);
				
				second.add(String.format("%d", lineNumber));
				second.add("");
				second.add("add");
				second.add(intermediateReg);
				second.add(reg1);
				
				// compare
				third.add(String.format("%d", lineNumber));
				third.add(label);
				third.add("compi");
				third.add(intermediateReg);
				third.add(sImm);
			}
			else {
				// compare
				third.add(String.format("%d", lineNumber));
				third.add(label);
				third.add("compi");
				third.add(reg1);
				third.add(sImm);
			}
		}
		
		switch(lineList.get(FUNCTION_POSITION)) {
		
			case "li":
				
				int imm = parseImmediate(lineList.get(ITYPE_IMM_POSITION));
				String immBinary = convertImmToBinary(imm, 16);
				String immUpTwo = String.format("%s", immBinary.substring(0, 2));
				String immMidHigh = String.format("%s", immBinary.substring(2, 9));
				String immLow = String.format("%s", immBinary.substring(9, 16));
				
				String immUpper = String.format("%s", immBinary.substring(0, 7));
				String immMiddle = String.format("%s", immBinary.substring(7, 14));
				String immLowTwo = String.format("%s", immBinary.substring(14, 16));
				
				int immUTwo = Integer.parseInt(immUpTwo, 2);
				int immMHi = Integer.parseInt(immMidHigh, 2);
				int immL = Integer.parseInt(immLow, 2);
				
				int immUp = Integer.parseInt(immUpper, 2);
				int immMid = Integer.parseInt(immMiddle, 2);
				int immLTwo = Integer.parseInt(immLowTwo, 2);
				
				String reg = lineList.get(ITYPE_DST_REG_POSITION);
				
				if (imm == 0) {
					first.add(String.format("%d", lineNumber));
					first.add(label);
					first.add("sub");
					first.add(reg);
					first.add(reg);
				}
				else if (imm == MAX_VALUE) {
					first.add(String.format("%d", lineNumber));
					first.add(label);
					first.add("sub"); // clear reg
					first.add(reg);
					first.add(reg);
					
					second.add(String.format("%d", lineNumber));
					second.add("");
					second.add("subi");
					second.add(reg);
					second.add("1"); // 0 - 1 = -1 which is all 1's in binary
				}
				else if (imm <= IMMEDIATE_MAX_VALUE){
					first.add(String.format("%d", lineNumber));
					first.add(label);
					first.add("lli");
					first.add(reg);
					first.add(String.format("%d", imm));
				}
				else if (immUTwo == 0){
					first.add(String.format("%d", lineNumber));
					first.add(label);
					first.add("lui");
					first.add(reg);
					first.add(String.format("%d", immMHi));
					
					label = "";
					
					if (immL != 0) {
						second.add(String.format("%d", lineNumber));
						second.add(label);
						second.add("ori");
						second.add(reg);
						second.add(String.format("%d", immL));
					}
				}
				else {
					first.add(String.format("%d", lineNumber));
					first.add(label);
					first.add("lui");
					first.add(reg);
					first.add(String.format("%d", immUp));
					
					label = "";
					
					if (immMid != 0) {
						second.add(String.format("%d", lineNumber));
						second.add(label);
						second.add("ori");
						second.add(reg);
						second.add(String.format("%d", immMid));
					}
					
					third.add(String.format("%d", lineNumber));
					third.add(label);
					third.add("slli");
					third.add(reg);
					third.add(String.format("%d", 2));
					
					if (immLTwo != 0) {
						fourth.add(String.format("%d", lineNumber));
						fourth.add(label);
						fourth.add("ori");
						fourth.add(reg);
						fourth.add(String.format("%d", immLTwo));
					}
				}
				
				break;
				
			case "mov":
				
				reg1 = lineList.get(RTYPE_DST_REG_POSITION);
				reg2 = lineList.get(RTYPE_SRC_REG_POSITION);
				
				first.add(String.format("%d", lineNumber));
				first.add(label);
				first.add("sub");
				first.add(reg1);
				first.add(reg1);
				
				second.add(String.format("%d", lineNumber));
				second.add("");
				second.add("add");
				second.add(reg1);
				second.add(reg2);
				
				break;
				
			case "push":
				
				reg = lineList.get(RTYPE_DST_REG_POSITION);
				
				// $sp++
				first.add(String.format("%d", lineNumber));
				first.add(label);
				first.add("addi");
				first.add("$sp");
				first.add("1");
				
				// push onto top of stack
				second.add(String.format("%d", lineNumber));
				second.add("");
				second.add("write");
				second.add(reg);
				second.add("$sp"); // write to $sp
				second.add("0"); // bank
				
				break;
				
			case "pop":
				
				reg = lineList.get(RTYPE_DST_REG_POSITION);
				
				// pop off of stack
				first.add(String.format("%d", lineNumber));
				first.add(label);
				first.add("read");
				first.add(reg);
				first.add("$sp");
				first.add("0");
				
				// decrement stack pointer
				second.add(String.format("%d", lineNumber));
				second.add("");
				second.add("subi");
				second.add("$sp");
				second.add("1");
				
				break;
				
			case "beq":
				
				// jeq
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jeq");
				fourth.add(jlabel);
				
				break;
				
			case "bne":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jne");
				fourth.add(jlabel);
				
				break;
				
			case "blt":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jlt");
				fourth.add(jlabel);
				
				break;
				
			case "bleq":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jleq");
				fourth.add(jlabel);
				
				break;
				
			case "bgt":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jleq");
				fourth.add(jlabel);
				
				break;
				
			case "bgeq":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jlt");
				fourth.add(jlabel);
				
				break;
				
			case "beqi":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jeq");
				fourth.add(jlabel);
				
				break;
				
			case "bnei":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jne");
				fourth.add(jlabel);
				
				break;
				
			case "blti":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jlt");
				fourth.add(jlabel);
				
				break;
				
			case "bleqi":
				
				fourth.add(String.format("%d", lineNumber));
				fourth.add("");
				fourth.add("jleq");
				fourth.add(jlabel);
				
				break;
		}
		
		if (!first.isEmpty())  lines.add(first);
		if (!second.isEmpty()) lines.add(second);
		if (!third.isEmpty())  lines.add(third);
		if (!fourth.isEmpty()) lines.add(fourth);
 		
		return false;
	}
	
	/**
	 * Parses special .initialize commands (such as .glyph_init
	 * and .screen_init) and then removes them from the lines list.
	 * Stops when it reaches the .teak command, which signals the start
	 * of instruction memory
	 * @param line
	 */
	private static void initialize() {
		String oper = null;
		while ( !(oper = lines.get(0).get(LABEL_POSITION)).equals(".teak")) {
			String arg0 = lines.get(0).get(LABEL_POSITION+1);
			switch(oper) {
				case ".glyph_init":
					glyphGen(arg0);
					lines.remove(0); // remove initializer
					break;
				case ".screen_init":
					screenGen(arg0);
					lines.remove(0); // remove initializer
					break;
			}
		}
		lines.remove(0); // finally remove .teak
		
		return;
	}

	/**
	 * The map phase maps labels to their line number which will be translated into
	 * a pc relative address later. Does error checking: labels cannot start with
	 * a digit and all labels must be unique.
	 */
	private static void map() {
		try {
			for (List<String> l : lines) {
				String label = (String) l.get(LABEL_POSITION);
				if (!(label).isEmpty()) {
					if (!label.matches(LABEL_FORMAT)) //
						throw new AssemblerFormatException(errorMsg(l.get(LINE_NUMBER_POSITION), "Label '" + label + "' cannot start with a digit."));
					if (labels.containsKey(label)) 
						throw new AssemblerFormatException(errorMsg(l.get(LINE_NUMBER_POSITION), "Label '" + label + "' must be unique."));
					else 
						labels.put(label, lines.indexOf(l));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	/**
	 * Processes each line and properly encodes each instruction, immediate,
	 * register, and address into a bit string. 
	 */
	private static void encode() {
		for (List<String> l : lines) {
			if (l.size() > 2) { // line must have more than a line number and label
				String function = l.get(FUNCTION_POSITION);
				Integer opCode = null;
				
				try {
					opCode = InstructionOpCodes.get(function)[OP_CODE_POSITION];
				} catch (NullPointerException npe) {
					System.err.println(errorMsg(l.get(LINE_NUMBER_POSITION), function + " instruction is not supported"));
					npe.printStackTrace();
				}
				
				String encoding = null;
				
				switch(opCode) {
					case RTYPE_OPCODE: 
						encoding = encodeRType(function, l.get(RTYPE_SRC_REG_POSITION), l.get(RTYPE_DST_REG_POSITION));
						break;
					case ITYPE_OPCODE:
						encoding = encodeIType(function, l.get(ITYPE_IMM_POSITION), l.get(ITYPE_DST_REG_POSITION));
						break;
					case MTYPE_OPCODE:
						encoding = encodeMType(function, l.get(MTYPE_BANK_POSITION), l.get(MTYPE_MEM_REG_POSITION), l.get(MTYPE_DST_REG_POSITION));
						break;
					case JTYPE_OPCODE:
						encoding = encodeJType(lines.indexOf(l), function, l.get(JTYPE_ADDR_POSITION));
						break;
				}
				
				textMem.add(encoding);
				
			}
		}
	}
	
	/**
	 * Encodes an R-Type (register operands only) instruction into machine code (bits)
	 * @param instruction name (add, sub, etc.)
	 * @param srcReg name ($r1, $sp, etc.)
	 * @param destReg name ($r2, $ret, etc.)
	 * @return encoded machine instruction
	 */
	private static String encodeRType(String instruction, String srcReg, String destReg) {
		
		String opCodeBits = convertImmToBinary(0, 2);
		String instrCodeBits = convertImmToBinary(InstructionOpCodes.get(instruction)[INSTR_CODE_POSITION], 3);
		String destRegBits = convertImmToBinary(encodeRegister(destReg), 4);
		String srcRegBits = convertImmToBinary(encodeRegister(srcReg), 4);
		
		return opCodeBits + instrCodeBits + "000" + srcRegBits + destRegBits;
	}
	
	/**
	 * Encodes an I-Type (one operand is an immediate value) instruction into machine code (bits)
	 * @param instruction name (addi, lui, etc.)
	 * @param imm value (in decimal or hexidecimal form)
	 * @param destReg name ($r3, $ret, etc.)
	 * @return encoded machine instruction
	 */
	private static String encodeIType(String instruction, String imm, String destReg) {
		
		String opCodeBits = convertImmToBinary(1, OPCODE_BIT_WIDTH);
		String instrCodeBits = convertImmToBinary(InstructionOpCodes.get(instruction)[INSTR_CODE_POSITION], 3);
		String immBits = null;
		String destRegBits = convertImmToBinary(encodeRegister(destReg), REG_BIT_WIDTH);
		
		int immValue = parseImmediate(imm);
		
		if (valueOutOfBounds(immValue, IMMEDIATE_BIT_WIDTH))
			throw new NumberFormatException();
		else 
			immBits = Assemble.convertImmToBinary(immValue, IMMEDIATE_BIT_WIDTH);
		
		return opCodeBits + instrCodeBits + immBits + destRegBits;
		
	}
	
	/**
	 * Encodes an M-Type (read/write from/to memory) instruction into machine code (bits)
	 * @param instruction name (read or write)
	 * @param bank value (in decimal or hex)
	 * @param memAddress reg name ($r6, $r7, etc.)
	 * @param destReg name ($r1, $r2, etc.)
	 * @return encoded machine instruction
	 */
	private static String encodeMType(String instruction, String bank, String memAddress, String destReg) {
		
		String opCodeBits = Assemble.convertImmToBinary(2, OPCODE_BIT_WIDTH);
		String instrCodeBits = Assemble.convertImmToBinary(InstructionOpCodes.get(instruction)[INSTR_CODE_POSITION], 1);
		String bankBits = null;
		String memAddrBits = Assemble.convertImmToBinary(Assemble.encodeRegister(memAddress), REG_BIT_WIDTH);
		String destRegBits = Assemble.convertImmToBinary(Assemble.encodeRegister(destReg), REG_BIT_WIDTH);
		
		int bankValue = parseImmediate(bank);
		
		if (valueOutOfBounds(bankValue, BANK_BIT_WIDTH))
			throw new NumberFormatException();
		else 
			bankBits = Assemble.convertImmToBinary(bankValue, BANK_BIT_WIDTH);
		
		return opCodeBits + instrCodeBits + bankBits +memAddrBits + destRegBits;
	}
	
	/**
	 * Encodes an J-Type (operand is an instruction address) instruction into machine code (bits)
	 * @param currentLine assembler is operating on
	 * @param instruction name (jl, blt, etc.)
	 * @param address label ("start", "end", etc.)
	 * @return encoded machine instruction
	 */
	private static String encodeJType(int currentLine, String instruction, String address) {
		
		String opCodeBits = Assemble.convertImmToBinary(3, OPCODE_BIT_WIDTH);
		String instrCodeBits = Assemble.convertImmToBinary(InstructionOpCodes.get(instruction)[INSTR_CODE_POSITION], 3);
		
		// if jr instruction (operand is register)
		if (address.startsWith(REG_PREFIX)) {
			if (instruction.equals("jr")) {
				String jumpReg = convertImmToBinary(encodeRegister(address), REG_BIT_WIDTH);
				String filler = convertImmToBinary(0, 7);
				
				return opCodeBits + instrCodeBits + filler + jumpReg;
			}
			else {
				System.err.println(errorMsg("unknown", "only the 'jr' jump instruction can operate on registers"));
				return "0";
			}
		}
		else { // other jump types (operand is an 11 bit address)
			String addrBits = null;
			int addrValue = 0;
			try {
				addrValue = labels.get(address);
			} catch (NullPointerException npe) {
				System.err.println(errorMsg("unknown", address + " does not exist"));
				npe.printStackTrace();
			}
			
			if (valueOutOfBounds(addrValue, JUMP_ADDRESS_BIT_WIDTH))
				throw new NumberFormatException();
			else {
				addrValue = addrValue - (currentLine + 1);
				addrBits = Assemble.convertImmToBinary(addrValue, JUMP_ADDRESS_BIT_WIDTH);
			}
			
			return opCodeBits + instrCodeBits + addrBits;
		}
		
		
	}
	
	/*
	|--------------------------------------------------------------------------
	| MACHINE CODE OUTPUT FUNCTIONS
	|--------------------------------------------------------------------------
	|
	| These functions generally operate on the 'output' list variable to build
	| the final machine code (bits) that will be output to the .coe file
	|
	*/
	
	/**
	 * Outputs the final words to the given .coe file
	 * @param outputFile to output bits
	 * @param radix to output to, either binary (2) or hex (16)
	 * @return int total size of output memory (in number of words, words = 16 bits)
	 */
	private static int generateMemory(String outputFile, int radix) {
		
		List<String> output = null;
		
		try {
			output = new ArrayList<>(); // list of final bits to output
			
			PrintWriter out = new PrintWriter(new File(outputFile));
			out.println ("memory_initialization_radix=" + radix + ";");
			out.println ("memory_initialization_vector=");
			out.println();			
			
			zeroPad(screenMem, SCREEN_MEM_SIZE);
			output.addAll(screenMem);
			
			zeroPad(glyphMem, GLYPH_MEM_SIZE);
			output.addAll(glyphMem);

			zeroPad(textMem, TEXT_MEM_SIZE);
			output.addAll(textMem);
			
			zeroPad(dataMem, DATA_MEM_SIZE);
			output.addAll(dataMem);
			
			int memSize = output.size();
			
			int i = 0;
			for (String bitline : output) {
				if (radix == 16)  // hex
					out.print(binaryToHex(bitline));
				else 
					out.print(bitline);
				
				if (i == memSize-1) 
					out.println(";"); // print semi-colon after last memory address
				else 
					out.println(",");
				i++;
			}
			
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		return output.size();
	}
	
	/**
	 * Pads the given memory list with zeros until filled up to size
	 * ex. current memory size = 256, size should = 1024, 
	 * will pad with 1024-256 = 768 words of zeros
	 * @param memory list to pad
	 * @param size that the memory list should be
	 */
	private static void zeroPad(List<String> memory, int size) {
		
		if (memory.size() > size) {
			throw new IndexOutOfBoundsException("Memory area too large, must be less than " + size);
		}
		else {
			int wordsToAdd = size - memory.size();
			for (int i = 0; i < wordsToAdd; i++) {
				memory.add(convertImmToBinary(0, 16));
			}
		}
	}

	/**
	 * Generates ascii glyphs based on given glyphFile
	 * @param glyphFile
	 */
	private static void glyphGen(String glyphFile) {
		BufferedImage image = null;
		try {
			
			image = javax.imageio.ImageIO.read(new File(glyphFile));
		
			StringBuilder bitstream = new StringBuilder();
			
			// set ascii chars 0-31 to blank
			for (int i = 0; i < 32; i++)
			{
				for (int b = 0; b < 8; b++)
					bitstream.append("00000000");
			}
			
			// generate ascii chars 32-127 based on glyphFile
	        for (int i = 32; i < 128; i++)
	        {
	        	int x = ((i-32) % 16) * 8;
	        	int y = ((i-32) / 16) * 8;
	        	
	        	for (int py = 0; py < 8; py++)
	        	{
	        		for (int px = 7; px >= 0; px--)
	        		{
	        			int c = image.getRGB(x + px,  y + py);
	        			if ((c & 0xff) < 20)
	        				bitstream.append ("1");
	        			else
	        				bitstream.append ("0");
	        		}
	        		
	        	}	
	        }
	        
	        // set ascii chars 128-255 to blank
			for (int i = 128; i < 256; i++)
			{
				for (int b = 0; b < 8; b++)
					bitstream.append("00000000");
			}
	
			String s = bitstream.toString();
			
			for (int i = 0; i < 256 * 4; i++) {
				glyphMem.add(s.substring(i*16, (i+1)*16));
			}
			
			
		} catch (IOException e) {
			System.out.println("Error with " + glyphFile);
			e.printStackTrace();
		}
		
		return;
	}
	
	/**
	 * Generates initial vga screen display based on given initFile
	 * @param initFile
	 */
	private static void screenGen(String initFile) {
		FileReader text;
		try {
			text = new FileReader(new File(initFile));
		
			StringBuilder bitstream = new StringBuilder();
			
			boolean ignoreWhitespace = true;
			int color = 255;
			
			for (int row = 0; row < 64; row++)
				for (int col = 0; col < 128; col++)
				{
					if (col < 16 && row < 17 && row >= 1)
						ignoreWhitespace = true;
					int ch = text.read();
					while (ignoreWhitespace && Character.isWhitespace(ch))
						ch = text.read();
					ignoreWhitespace = Character.isWhitespace(ch);
	
					if (col < 16 && row < 17 && row >= 1)
						color = col + (row-1)*16;
					
					// blink
					bitstream.append(0); 
					// bg
					bitstream.append(0);
					bitstream.append(0);
					bitstream.append(0);
					// fg
					bitstream.append(1);
					bitstream.append(1);
					bitstream.append(1);
					bitstream.append(1);

					for (int b = 7; b >= 0; b--)
						bitstream.append((ch >> b) & 1);				
				}
			
			String s = bitstream.toString();
			
			for (int i = 0; i < 128 * 64; i++)
			{
				screenMem.add(s.substring(i*16, (i+1)*16));
			}
		
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	/*
	|--------------------------------------------------------------------------
	| GENERAL PURPOSE HELPER FUNCTIONS
	|--------------------------------------------------------------------------
	|
	| Functions such as converters, simple parsers, etc. In general these 
	| helper functions are only a few lines of code.
	|
	*/
	
	/**
	 * Error message handler to output an error with the line number of the offending code
	 * @param lineNumber to print out with error
	 * @param errorString to print out
	 */
	public static String errorMsg(String lineNumber, String errorString) {
		error = true;
		return "Error on line " + lineNumber + ": " + errorString;
	}

	/**
	 * Formats each line by making each line lowercase
	 * and removing comments
	 * @param line
	 * @return formated line
	 */
	public static String format(String line) {
		line = line.trim();
		line = line.replaceAll("[" + COMMENT + "].*", "").trim(); // remove comments
		
		return line;
	}
	
	/**
	 * Removes spaces and tabs from a given token
	 * @param token
	 * @return cleaned token
	 */
	public static String clean(String token) {
		return token.replaceAll(WHITE_SPACE_PATTERN, ""); // remove whitespace
	}
	
	/**
	 * Takes a register string (ex. $r1, $zero, etc.) and returns the 
	 * associated register number
	 * @param register to decode
	 * @return byte the decoded register number
	 */
	public static byte encodeRegister(String register) {
			
		if (!register.startsWith(REG_PREFIX)) {
			throw new IllegalArgumentException("Registers must begin with a " + REG_PREFIX);
		}
		else {
			register = register.replace(REG_PREFIX, ""); // remove $
		}
		
		
		switch (register) {
			case "0":
			case ZERO_REG:	return 0;
			case RET_REG:	return 12;
			case SP_REG:	return 13;
			case RA_REG:	return 14;
			case AT_REG:	return 15;
		}
		
		if (!register.matches(REG_PATTERN)) {
			throw new IllegalArgumentException("Register names must be either a "
					+ "special register name: zero, ret, sp, ra or of the form " + REG_PATTERN);
		}
		else {
			register = register.replace(REG_PREFIX_CHAR, ""); // remove r
			byte number = Byte.parseByte(register); // all that's left is the number
			if (number > 11) {
				throw new IllegalArgumentException("There are only 16 registers including: zero, "
						+ "ret, sp, ra and registers 1-11");
			}
			else {
				return number;
			}
		}
	}
	
	/**
	 * Parses a given immediate string into a value. Immediate
	 * strings can be in either hexadecimal (of the form 0x[HEX])
	 * or decimal notation. Cannot parse negative hex values
	 * @param imm String in hex or decimal
	 * @return short immediate value
	 */
	public static int parseImmediate(String imm) {
		if (imm.startsWith(HEX_PREFIX))  // match hex format
			return Integer.parseInt(imm.replace(HEX_PREFIX, ""), 16);
		else 
			return Integer.parseInt(imm, 10); // else match decimal
	}
	
	/**
	 * Converts the given signed immediate value to a bit representation string 
	 * with the given bit width (with sign extension).
	 * @param imm the immediate value
	 * @param width the bit width
	 * @return String representing the imm value in bits
	 */
	public static String convertImmToBinary(int imm, int width) {
		String binary = null;
		try {
			
			String format = "%" + width + "s";
			binary = Integer.toBinaryString(imm);
			if (width > binary.length())
				return String.format(format, binary).replaceAll(" ", "0");
			else
				return String.format(format, binary.substring(binary.length()-width, binary.length()));
			
		} catch (StringIndexOutOfBoundsException e) {
			System.err.println("width must be 32 or less");
			e.printStackTrace();
		}
		
		return binary;
	}
	
	/**
	 * Converts a binary string to a hex string
	 * Ex. 1111 => 0xF
	 * @param binary
	 * @return String hex string
	 */
	public static String binaryToHex(String binary) {
		int decimal = Integer.parseInt(binary, 2);
		return String.format("%4s", Integer.toString(decimal, 16)).replace(' ', '0');
	}
	
	/**
	 * Checks if a given value is out of bounds based on the given bit width
	 * @param value to check
	 * @param width to use when calculating max value
	 * @return boolean
	 */
	public static boolean valueOutOfBounds(int value, int width) {
		
		if (value >= Math.pow(2, width))
			return true;
		else
			return false;
	}

}