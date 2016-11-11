package assem;

import static org.junit.Assert.*;

import org.junit.Test;

public class HelperFunctionsTest {

	@Test
	public void parseDecimalPosTest() {
		assertEquals(0, Assemble.parseImmediate("0"));
		assertEquals(2, Assemble.parseImmediate("2"));
		assertEquals(55, Assemble.parseImmediate("55"));
	}
	
	@Test
	public void parseDecimalNegTest() {
		assertEquals(-1, Assemble.parseImmediate("-1"));
	}
	
	@Test
	public void parseHexTest() {
		assertEquals(0, Assemble.parseImmediate("0x0"));
		assertEquals(1, Assemble.parseImmediate("0x1"));
		assertEquals(2, Assemble.parseImmediate("0x2"));
		assertEquals(10, Assemble.parseImmediate("0xA"));
		assertEquals(15, Assemble.parseImmediate("0xF"));
		assertEquals(16, Assemble.parseImmediate("0x10"));
		assertEquals(255, Assemble.parseImmediate("0xFF"));
		assertEquals(4095, Assemble.parseImmediate("0xFFF"));
	}
	
	@Test
	public void encodeRegistersTest() {
		assertEquals(0, Assemble.encodeRegister("$0"));
		assertEquals(0, Assemble.encodeRegister("$zero"));
		assertEquals(12, Assemble.encodeRegister("$ret"));
		assertEquals(13, Assemble.encodeRegister("$sp"));
		assertEquals(14, Assemble.encodeRegister("$ra"));
		assertEquals(1, Assemble.encodeRegister("$r1"));
		assertEquals(2, Assemble.encodeRegister("$r2"));
		assertEquals(3, Assemble.encodeRegister("$r3"));
		assertEquals(4, Assemble.encodeRegister("$r4"));
		assertEquals(5, Assemble.encodeRegister("$r5"));
		assertEquals(6, Assemble.encodeRegister("$r6"));
		assertEquals(7, Assemble.encodeRegister("$r7"));
		assertEquals(8, Assemble.encodeRegister("$r8"));
		assertEquals(9, Assemble.encodeRegister("$r9"));
		assertEquals(10, Assemble.encodeRegister("$r10"));
		assertEquals(11, Assemble.encodeRegister("$r11"));
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void encodeRegistersExceptionTest() {
		Assemble.encodeRegister("$r12");
		Assemble.encodeRegister("$test");
		Assemble.encodeRegister("$blah");
		Assemble.encodeRegister("r1");
		Assemble.encodeRegister("$s3");
	}
	
	@Test
	public void convertImmToBinaryTest() {
		assertEquals("0001", Assemble.convertImmToBinary(1, 4));
		assertEquals("1000", Assemble.convertImmToBinary(8, 4));
		assertEquals("1111", Assemble.convertImmToBinary(15, 4));
		assertEquals("1111", Assemble.convertImmToBinary(-1, 4));
		assertEquals("00000001", Assemble.convertImmToBinary(-255, 8));
		assertEquals("1100000001", Assemble.convertImmToBinary(-255, 10));
	}
	
	@Test
	public void binaryToHexTest() {
		assertEquals("0000", Assemble.binaryToHex("0000"));
		assertEquals("000f", Assemble.binaryToHex("1111"));
		assertEquals("001f", Assemble.binaryToHex("00011111"));
		assertEquals("00ff", Assemble.binaryToHex("11111111"));
		assertEquals("e00f", Assemble.binaryToHex("1110000000001111"));
	}
	
	@Test
	public void valueOutOfBoundsTest() {
		assertTrue(Assemble.valueOutOfBounds(8, 3));
		assertFalse(Assemble.valueOutOfBounds(7, 3));
		assertTrue(Assemble.valueOutOfBounds(256, 8));
		assertTrue(Assemble.valueOutOfBounds(4096, 12));
	}
	
	@Test
	public void jEncodingTest() {
		
	}

}
