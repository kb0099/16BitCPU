package assem;

public class Register {
	
	private short regNumber;
	private short value;
	final short bitWidth = 16;
	
	public Register(short regNumber, short value) {
		this.regNumber = regNumber;
		setValue(value);
	}
	
	private void setValue(short value) {
		double max = Math.pow(2, 16);
		if (value < max) {
			this.value = value;
		}
		else {
			throw new NumberFormatException("Register value too large: "
					+ "max = " + (max-1) + ", actual = " + value);
		}
	}
	
	public String toString() {
		return "$r" + regNumber;
	}

}