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
	
	// assembler variables
	private static List<List<String>> lines = new ArrayList<>(); // list of lines
	private static List<String> output = new ArrayList<>(); // list of final bits to output
	private static Map<String, Integer> labels = new HashMap<>(); // labels mapped to line address

	/*
	|--------------------------------------------------------------------------
	| MAIN
	|--------------------------------------------------------------------------
	|
	| Assembler entry point
	|
	*/
	
	public static void main(String[] args) {
		
		String assemblyFile = null;
		if (args.length != 1) {
			System.out.println("Please input an assembly file");
			return;
		}
		else {
			assemblyFile = args[0];
		}
		
		tokenize(assemblyFile);
		
		initialize();
		map();
		decode();
		
		for (List<String> l : lines) {
			System.out.println(l);
		}
		

		labels.forEach((k,v)->System.out.println(k + ": " + v));
		
		System.out.format("%s\n", convertImmToBinary(7, 11));
		
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
	
	private static void decode() {
		
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
			System.out.println("Opening " + assemblyFile + "...\n");
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

}