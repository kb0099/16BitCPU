package assem;

public class ImmInstruction extends Instruction {

	final private short imm;
	final private String destReg;

	public ImmInstruction(Instr instruction, String destReg, String imm) {
		super(instruction);
		this.imm = ParseImmediate(imm);
		this.destReg = destReg;
	}

	public short getImm() {
		return imm;
	}

	public String getDestReg() {
		return destReg;
	}

	public String toString() {
		String opCode = "01";
		String instruction = DecodeInstruction(this.getInstruction());
		String destReg = ConvertRegToBinary(DecodeRegister(this.destReg));
		String imm = ConvertImmToBinary(this.imm, 7);

		return opCode + instruction + destReg + imm;
		
		//return String.format("%02x%03x%07x%04x", opCode, instruction, imm, destReg);
	}
	
}