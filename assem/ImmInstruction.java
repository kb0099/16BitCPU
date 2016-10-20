package assem;

private class ImmInstruction extends Instruction {

	final private byte imm;
	final private byte destReg;

	public RegInstruction(byte opCode, byte instruction, byte imm, byte destReg) {
		super(opCode, instruction);
		this.imm = imm;
		this.destReg = destReg;
	}

	public byte getImm() {
		return imm;
	}

	public byte getDestReg() {
		return destReg;
	}

	public String toString() {
		return System.out.printf("%x%x%x%x", opCode, instruction, imm, destReg);
	}
}