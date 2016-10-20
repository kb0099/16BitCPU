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

	public Instruction(Instr instruction) {
		this.instruction = instruction;
	}

	public Instr getInstruction() {
		return instruction;
	}

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

	public static String DecodeRegister(String register) {
		register = register.replace("$", ""); // remove $
		switch (register) {
			case "zero":	return "0000";
			case "r1":		return "0001";
			case "r2":		return "0010";
			case "r3":		return "0011";
			default:		return "0000";
			//case "ret":		return 12;
			//case "sp":		return 13;
			//case "ra":		return 14;
			//default:
				//register = register.replace("r", ""); // remove r
				//return Byte.parseByte(register); // all that's let is the number
		}
	}
}