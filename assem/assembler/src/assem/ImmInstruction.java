package assem;

public class ImmInstruction extends Instruction {

	final private short imm;
	final private String destReg;

	public ImmInstruction(Instr instruction, String destReg, String imm) {
		super(instruction);
		this.imm = Short.parseShort(imm);
		this.destReg = destReg;
	}

	public Short getImm() {
		return imm;
	}

	public String getDestReg() {
		return destReg;
	}

	public String toString() {
		String opCode = "01";
		String instruction = DecodeInstruction(this.getInstruction());
		String destReg = DecodeRegister(this.destReg);
		String imm = String.format("%7s", Integer.toBinaryString(this.imm)).replace(' ', '0');

		return opCode + instruction + imm + destReg;
		
		//return String.format("%02x%03x%07x%04x", opCode, instruction, imm, destReg);
	}
}