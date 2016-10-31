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
	
	// lines list position constants
	private static final int LINE_NUMBER_POSITION 	= 0; // position in lines list (source line number)
	private static final int LABEL_POSITION 	  	= 1; // position in lines list
	private static final int FUNCTION_POSITION 	  	= 2; // position in lines list
	
	// regex patterns
	private static final String LABEL_FORMAT 		= "^\\D.*"; // labels cannot start with a digit
	private static final String WHITE_SPACE_PATTERN = "[ \t]"; // spaces and tabs
	private static final String LABEL_DELIMITER 	= ":"; // colon
	private static final String DELIMITER_PATTERN 	= "[ |\t|,]"; // spaces, tabs, and commas
	private static final String SPECIAL_FUNC_PREFIX = "."; // period
	private static final String COMMENT 			= "//"; // slash slash
	private static final String HEX_PREFIX 			= "0x";
	
	// bit widths (use for max value error checking)
	private static final int JUMP_ADDRESS_BIT_WIDTH = 11; // max jump address = 2^11
	private static final int IMMEDIATE_BIT_WIDTH    =  7; // max immediate value = 2^7
	private static final int BANK_BIT_WIDTH 		=  5; // max bank size = 2^5
	private static final int REGISTER_BIT_WIDTH 	= 16; // max register size = 2^16
	
	// instruction mappings
	private static final Map<String, String> functions = new HashMap<>();
	static {
		String rType = convertImmToBinary(0, 2);
		String iType = convertImmToBinary(1, 2);
		String mType = convertImmToBinary(2, 2);
		String jType = convertImmToBinary(3, 2);
		
		// register type instructions
		functions.put("add", rType + "000");
		functions.put("sub", rType + "001");
		// immediate type instructions
		functions.put("addi", iType + "000");
		functions.put("li", iType + "111");
		// memory type instructions
		functions.put("read", mType + "0");
		functions.put("write", mType + "1");
		// jump type instructions
		functions.put("jl", jType + "000");
	}
	
	// assembler variables
	private static List<List<String>> lines = new ArrayList<>(); // list of lines
	private static List<String> output = new ArrayList<>(); // list of final bits to output
	private static Map<String, Integer> labels = new HashMap<>(); // labels mapped to line address
	
	// help description
	private static final String HELP = "Assemble - TEAK assembler v0.1 \n\n"
									 + "usage: Assemble [.teak file] [.coe output file]? [output radix]? \n\n"
									 + "arguments: \n"
									 + "\t [.teak file] \t\t the name of a .teak assembly file to assemble into machine code (bits) \n"
									 + "\t [.coe output file] \t (optional) the name of a .coe file to write machine code to (defaults to 'mem.coe') \n"
									 + "\t [output radix] \t (optional) bit radix to use, 2 (binary, default) or 16 (hexadecimal) \n";

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
		int outputRadix = 2; // default
		
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
		
		System.out.format("Assembling '%s' into '%s' (using radix %d) \n", assemblyFile, outputFile, outputRadix);
		long start = System.currentTimeMillis(); // time execution time and report
		
		// work
		tokenize(assemblyFile); // split each line into tokens (labels, functions, registers, etc.)
		initialize(); // run any special .initializers before anything else
		map(); // map labels to a corresponding label address
		encodeSimple(); // encode instructions and operators into machine code (bits)
		generateMemory(outputFile, outputRadix); // write resulting machine code to .coe file
		
		long end = System.currentTimeMillis();
		double time = (end-start)/1000d; // display execution time in seconds
		System.out.format("Done. \nWrote %d words to '%s' in %.3fs \n", output.size(), outputFile, time);
		
//		for (List<String> l : lines) {
//			System.out.println(l);
//		}
//		
//
//		labels.forEach((k,v)->System.out.println(k + ": " + v));
//		
//		System.out.format("%s\n", convertImmToBinary(7, 11));
//		
//		int i = 0;
//		for (String o : output)
//			System.out.println(i++ + ": " + o);
		
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
	 * Processes each line and properly encodes each instruction, immediate,
	 * register, and address into a bit string. Simple implementation for use
	 * with barebones core
	 */
	private static void encodeSimple() {
		
		for (List<String> l : lines) {
			if (l.size() > 2) {
				String function = l.get(FUNCTION_POSITION);
				
				switch(function) {
					case "read":
						output.add(convertImmToBinary(0, 16));
						break;
					case "incr":
						output.add(convertImmToBinary(2, 16));
						break;
					case "write":
						output.add(convertImmToBinary(1, 16));
						break;
					case "jump":
						output.add(convertImmToBinary(3, 16));
						break;
				}
			}
		}
	}
	
	/**
	 * Processes each line and properly encodes each instruction, immediate,
	 * register, and address into a bit string. 
	 */
	private static void encode() {
		for (List<String> l : lines) {
			if (l.size() > 2) {
				String function = l.get(FUNCTION_POSITION);
				
				switch(function) {
					case "add":
						break;
					case "sub":
						break;
					case "addi":
						break;
					case "li":
						break;
					case "lw":
						break;
					case "sw":
						break;
					case "jl":
						break;
				}
			}
		}
	}

	/**
	 * Tokenizes each line by storing each parameter into a list
	 * Most of this work is done in parseLine
	 * @param assemblyFile
	 */
	public static void tokenize(String assemblyFile) {
		// open file and parse
		try {
			// open file
			FileReader fileReader = new FileReader(assemblyFile);
			BufferedReader reader = new BufferedReader(fileReader);
			
			String line = null;
			
			// loop through lines and parse
			int lineNumber = 0; // keep track of lines for debugging
			while( (line = reader.readLine()) != null) {
				if (!line.isEmpty()) { // only operate on lines with text
					line = format(line); // cleans line of whitespace and comments
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
	public static void parseLine(String line, int lineNumber) {
		// split by labels (keep : delimiter)
		ArrayList<String> tokens = new ArrayList<>(Arrays.asList(line.split("(?<=" + LABEL_DELIMITER + ")"))); 
		
		List<String> lineList = new ArrayList<>(); // list of parameters on line
		lineList.add(String.format("%d", lineNumber));
		
		// first element in line is defined as a label
		// if no label exist, a blank string is stored in the first element
		if (tokens.get(0).endsWith(LABEL_DELIMITER) || tokens.get(0).startsWith(SPECIAL_FUNC_PREFIX)) {
			
			lineList.add(clean(tokens.get(0).replaceAll(LABEL_DELIMITER, "")));
			tokens.remove(0); // remove label from tokens to make parsing args easier
		}
		else // if there is no label, add blank string
			lineList.add("");
		
		// parse and store arges into lineList
		if (tokens.size() > 0) {
			
			// args can be space, comman, or tab delimited
			String[] args = tokens.get(0).split(DELIMITER_PATTERN);
			
			for (String a : args) {
				if (!a.isEmpty())
					lineList.add(clean(a)); // add all parameters
			}
		}
		
		lines.add(lineList); // add this line the the lines list
		
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
						error(l.get(LINE_NUMBER_POSITION), "Label '" + label + "' cannot start with a digit.");
					if (labels.containsKey(label)) 
						error(l.get(LINE_NUMBER_POSITION), "Label '" + label + "' must be unique.");
					else 
						labels.put(label, lines.indexOf(l));
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static void error(String lineNumber, String errorString) throws Exception {
		throw new Exception("Error on line " + lineNumber + ": " + errorString);
	}
	
	/**
	 * Parses special .initialize commands (such as .glyph_init
	 * and .screen_init) and then removes them from the lines list.
	 * Stops when it reaches the .teak command, which signals the start
	 * of instruction memory
	 * @param line
	 */
	public static void initialize() {
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
	
	/*
	|--------------------------------------------------------------------------
	| MACHINE CODE OUTPUT FUNCTIONS
	|--------------------------------------------------------------------------
	|
	| These functions generally operate on the 'output' list variable to build
	| the final machine code (bits) that will be output to the .coe file
	|
	*/
	
	public static void generateMemory(String outputFile, int radix) {
		
		try {
			PrintWriter out = new PrintWriter(new File(outputFile));
			out.println ("memory_initialization_radix=" + radix + ";");
			out.println ("memory_initialization_vector=");
			out.println();
			
			int memSize = output.size();
			
			for (String bitline : output) {
				if (radix == 16)  // hex
					out.print(binaryToHex(bitline));
				else 
					out.print(bitline);
				
				if (output.indexOf(bitline) == memSize-1) 
					out.println(";"); // print semi-colon after last memory address
				else 
					out.println(",");
			}
			
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		return;
	}
	
	/**
	 * Generates ascii glyphs based on given glyphFile
	 * @param glyphFile
	 */
	public static void glyphGen(String glyphFile) {
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
				output.add(s.substring(i*16, (i+1)*16));
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
	public static void screenGen(String initFile) {
		FileReader text;
		try {
			text = new FileReader(new File(initFile));
		
			StringBuilder bitstream = new StringBuilder();
			
			boolean ignoreWhitespace = true;
			int color = 256;
			boolean increment = false;
			
			for (int row = 0; row < 64; row++)
				for (int col = 0; col < 128; col++)
				{
					if (col < 16 && row < 17 && row >= 1)
						ignoreWhitespace = true;
					int ch = text.read();
					while (ignoreWhitespace && Character.isWhitespace(ch))
						ch = text.read();
					ignoreWhitespace = Character.isWhitespace(ch);
					
					if (color == 0)
						increment = true;
					else if (color == 255)
						increment = false;
	
					if (increment)
						color += 1;
					else
						color -= 1;
	
					if (col < 16 && row < 17 && row >= 1)
						color = col + (row-1)*16;
					
					for (int b = 7; b >= 0; b--)
						bitstream.append ((color >> b) & 1);
					for (int b = 7; b >= 0; b--)
						bitstream.append ((ch >> b) & 1);				
				}
			
			String s = bitstream.toString();
			
			for (int i = 0; i < 128 * 64; i++)
			{
				output.add(s.substring(i*16, (i+1)*16));
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
	 * Formats each line by making each line lowercase
	 * and removing comments
	 * @param line
	 * @return formated line
	 */
	public static String format(String line) {
		line = line.toLowerCase(); // operate on lower case
		line = line.replaceAll("[" + COMMENT + "].*", ""); // remove comments
		
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
			Integer.parseInt(imm, 10); // else match decimal
		return 0;
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
			if (imm >=0 )
				return String.format(format, binary).replace(' ', '0');
			else // imm is negative 
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

}