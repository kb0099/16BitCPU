package assem;

public class MemInstruction extends Instruction {

	final private byte bank;
	final private String srcReg;
	final private String destReg;

	public MemInstruction(Instr instruction, String srcReg, String destReg, String bank) {
		super(instruction);
		this.bank = Byte.parseByte(bank);
		this.srcReg = srcReg;
		this.destReg = destReg;
	}

	public byte getBank() {
		return bank;
	}

	public String getSrcReg() {
		return srcReg;
	}

	public String getDestReg() {
		return destReg;
	}

	public String toString() {
		String opCode = "10";
		String instruction = DecodeInstruction(this.getInstruction());
		if (instruction == "000")
			instruction = "0";
		else
			instruction = "1";
		String srcReg = DecodeRegister(this.srcReg);
		String destReg = DecodeRegister(this.destReg);
		String bank = String.format("%5s", Integer.toBinaryString(this.bank)).replace(' ', '0');

		return opCode + instruction + bank + srcReg + destReg;
		
		//return String.format("%02x%01x%05x%04x%04x", opCode, instruction, bank, srcReg, destReg);
	}
}