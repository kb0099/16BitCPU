package assem;

import java.util.*;
import java.io.*;
import assem.Instruction.Instr;

public class Assemble {
	
	private static ArrayList<Instruction> instructions = new ArrayList<>();
	
	public static void Decode(String assemblyFile) {
		try {
			FileReader fileReader = new FileReader(assemblyFile);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
		} catch (FileNotFoundException e) {
			System.out.println("Unable to open " + assemblyFile + ": " + e);
		}
	}

	public static void main(String[] args) {
		
		//if (args.length != 1) {
			//System.out.println("Please input a assembly file");
			//return;
		//}
		
		//initializeGlyphs();
		//initializeText();
		//Decode(args[0]);
		
		
		instructions.add(new ImmInstruction(Instr.LUI, "$r1", "0x00"));
		instructions.add(new ImmInstruction(Instr.LI, "$r1", "0x00"));
		instructions.add(new MemInstruction(Instr.READ, "$r1", "$r2", "0x0"));
		instructions.add(new ImmInstruction(Instr.ADDI, "$r1", "1"));
		instructions.add(new MemInstruction(Instr.WRITE, "$r2", "$r1", "0x0"));
		instructions.add(new ImmInstruction(Instr.ADDI, "$r2", "1"));
		instructions.add(new JmpInstruction(Instr.JL, "0x1"));

		for(Instruction instruction : instructions) {
			System.out.println(instruction + ",");
		}
	}

}