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
		String opCode = "00";
		String instruction = DecodeInstruction(this.getInstruction());
		String srcReg = ConvertRegToBinary(DecodeRegister(this.srcReg));
		String destReg = ConvertRegToBinary(DecodeRegister(this.destReg));

		return opCode + instruction + srcReg + destReg;
		
		//return String.format("%02x%03x%04x%04x", opCode, instruction, srcReg, destReg);
	}
}