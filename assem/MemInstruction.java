package assem;

private class MemInstruction extends Instruction {

	final private byte bank;
	final private byte srcReg;
	final private byte destReg;

	public RegInstruction(byte opCode, byte instruction, byte bank, byte srcReg, byte destReg) {
		super(opCode, instruction);
		this.bank = bank;
		this.srcReg = srcReg;
		this.destReg = destReg;
	}

	public byte bank {
		return bank;
	}

	public byte getSrcReg() {
		return srcReg;
	}

	public byte getDestReg() {
		return destReg;
	}

	public String toString() {
		return System.out.printf("%x%x%x%x%x", opCode, instruction, bank, srcReg, destReg);
	}
}