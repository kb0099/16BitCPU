package assem;

public class Instruction {

	// instructions are immutable
	final private Instr instruction; // 3 bits (except for MemType, which is 1 bit)

	private enum Instr {
		ADD,  SUB, AND,  OR,   XOR,  SLL, SRL, SRA,
		ADDI, CMP, ANDI, ORI,  XORI, LUI, LI,
		READ, WRITE,
		JL,   BEQ, BNE,  CALL, JR
	}

	public Instruction(Instr instruction) {
		this.instruction = this.instruction;
	}

	public OpCode getOpCode() {
		return opCode;
	}

	public Instr getInstruction() {
		return instruction;
	}

	public static byte DecodeInstruction(Instr instruction) {
		switch(instruction) {
			case ADD: case ADDI: case READ : case JL : return 0;
			case SUB: case CMP : case WRITE: case BEQ: return 1;
			case AND: case ANDI: case BNE:  return 2;
			case OR : case ORI : case CALL: return 3;
			case XOR: case XORI: case JR  : return 4;
			case SLL: case LUI : return 5;
			case SRL: case LI  : return 6;
			case SRA: return 7;
		}
	}

	public static byte DecodeRegister(String register) {
		register = register.replace("$", ""); // remove $
		switch (register) {
			case "zero":	return 0;
			case "ret":		return 12;
			case "sp":		return 13;
			case "ra":		return 14;
			default:
				register = register.replace("r", ""); // remove r
				return Byte.parseByte(register); // all that's let is the number
		}
	}
}