package assem;

public class Instruction {

	// instructions are immutable
	final private Instr instruction; // 3 bits (except for MemType, which is 1 bit)

	public enum Instr {
		ADD,  SUB, AND,  OR,   XOR,  SLL, SRL, SRA,
		ADDI, CMP, ANDI, ORI,  XORI, LUI, LI,
		READ, WRITE,
		JL,   BEQ, BNE,  CALL, JR
	}

	/**
	 * Instruction Constructor
	 * @param instruction
	 */
	public Instruction(Instr instruction) {
		this.instruction = instruction;
	}

	/**
	 * Getter for instruction
	 * @return Instr enum
	 */
	public Instr getInstruction() {
		return instruction;
	}

	/**
	 * Takes an instruction enum type and returns the decoded instruction
	 * machine code in bits.
	 * @param instruction to decode
	 * @return String the decoded instruction in bits
	 */
	public static String DecodeInstruction(Instr instruction) {
		switch(instruction) {
			case ADD: case ADDI: case READ : case JL : return "000";
			case SUB: case CMP : case WRITE: case BEQ: return "001";
			case AND: case ANDI: case BNE:  return "010";
			case OR : case ORI : case CALL: return "011";
			case XOR: case XORI: case JR  : return "100";
			case SLL: case LUI : return "101";
			case SRL: case LI  : return "110";
			case SRA: return "111";
			default: return "000";
		}
	}

	/**
	 * Takes a register string (ex. $r1, $zero, etc.) and returns the 
	 * associated register number
	 * @param register to decode
	 * @return byte the decoded register number
	 */
	public static byte DecodeRegister(String register) {
		String startingChar = "$";
		String regChar = "r";
		String regPattern = regChar + "[0-9]+";
		
		if (!register.startsWith(startingChar)) {
			throw new IllegalArgumentException("Registers must begin with a " + startingChar);
		}
		else {
			register = register.replace(startingChar, ""); // remove $
		}
		
		
		switch (register) {
			case "0":
			case "zero":	return 0;
			case "ret":		return 12;
			case "sp":		return 13;
			case "ra":		return 14;		
		}
		
		if (!register.matches(regPattern)) {
			throw new IllegalArgumentException("Register names must be either a "
					+ "special register name: zero, ret, sp, ra or of the form " + regPattern);
		}
		else {
			register = register.replace(regChar, ""); // remove r
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
	 * Takes a register number (0, 1, 2, etc.) and returns the number
	 * in bits. Registers are defined to be 4 bits wide (total of 16 registers).
	 * @param reg to convert to binary
	 * @return String of bits representing the reg
	 */
	public static String ConvertRegToBinary(byte reg) {
		return String.format("%4s", Integer.toBinaryString(reg)).replace(' ', '0');
	}
	
	/**
	 * Converts the given immediate value to a bit representation string 
	 * with the given bit width (zero padded).
	 * @param imm the immediate value
	 * @param width the bit width
	 * @return String representing the imm value in bits
	 */
	public static String ConvertImmToBinary(short imm, int width) {
		String format = "%" + width + "s";
		return String.format(format, Integer.toBinaryString(imm)).replace(' ', '0');
	}
	
	/**
	 * Parses a given immediate string into a value. Immediate
	 * strings can be in either hexadecimal (of the form 0x[HEX])
	 * or decimal notation.
	 * @param imm String in hex or decimal
	 * @return short immediate value
	 */
	public static short ParseImmediate(String imm) {
		if (imm.startsWith("0x")) { // match hex format
			imm = imm.replace("0x", ""); // remove hex identifier
			System.out.println(imm + ": " + Short.parseShort(imm, 16));
			return Short.parseShort(imm, 16);
		}
		else {
			Short.parseShort(imm, 10); // else match decimal
		}
		return 0;
	}
}