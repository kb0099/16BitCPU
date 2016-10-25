package assem;

public class MemInstruction extends Instruction {

	final private short bank;
	final private String srcReg;
	final private String memReg;

	public MemInstruction(Instr instruction, String srcReg, String memReg, String bank) {
		super(instruction);
		this.bank = ParseImmediate(bank);
		this.srcReg = srcReg;
		this.memReg = memReg;
	}

	public short getBank() {
		return bank;
	}

	public String getSrcReg() {
		return srcReg;
	}

	public String getMemReg() {
		return memReg;
	}

	public String toString() {
		String opCode = "10";
		String instruction = DecodeInstruction(this.getInstruction());
		if (instruction == "000")
			instruction = "0";
		else
			instruction = "1";
		String srcReg = ConvertRegToBinary(DecodeRegister(this.srcReg));
		String memReg = ConvertRegToBinary(DecodeRegister(this.memReg));
		String bank = ConvertImmToBinary(this.bank, 5);

		return opCode + instruction + srcReg + memReg + bank;
		
		//return String.format("%02x%01x%05x%04x%04x", opCode, instruction, bank, srcReg, destReg);
	}
}