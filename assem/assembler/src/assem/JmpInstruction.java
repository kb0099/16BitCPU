package assem;

public class JmpInstruction extends Instruction {

	final private short address;

	public JmpInstruction(Instr instruction, String address) {
		super(instruction);
		this.address = Short.parseShort(address);
	}

	public short address() {
		return address;
	}

	public String toString() {
		String opCode = "11";
		String instruction = DecodeInstruction(this.getInstruction());
		String address = String.format("%11s", Integer.toBinaryString(this.address)).replace(' ', '0');

		return opCode + instruction + address;
		
		//return String.format("%02x%03x%011x", opCode, instruction, address);
	}
}