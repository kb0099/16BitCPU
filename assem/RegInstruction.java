package assem;

public class RegInstruction extends Instruction {
	
	final private String srcReg; // 4 bits
	final private String destReg; // 4 bits

	public RegInstruction(Instr instruction, String srcReg, String destReg) {
		super(instruction);
		this.srcReg = srcReg;
		this.destReg = destReg;
	}

	public String getSrcReg() {
		return srcReg;
	}

	public String getDestReg() {
		return destReg;
	}

	public String toString() {
		byte opCode = 0;
		byte instruction = DecodeInstruction(this.instruction);
		byte srcReg = DecodeRegister(this.srcReg);
		byte destReg = DecodeRegister(this.destReg);

		return System.out.printf("%02x%03x%04x%04x", opCode, instruction, srcReg, destReg);
	}
}