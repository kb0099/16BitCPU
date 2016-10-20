package assem;

private class JmpInstruction extends Instruction {

	final private short address;

	public RegInstruction(byte opCode, byte instruction, short address) {
		super(opCode, instruction);
		this.address = address;
	}

	public short address() {
		return address;
	}

	public String toString() {
		return System.out.printf("%x%x%x%x", opCode, instruction, address);
	}
}