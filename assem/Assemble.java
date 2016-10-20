package assem;

import java.util.*;

public class Assemble {

	public static void main(String[] args) {
		ArrayList<Instruction> instructions = new ArrayList<>();
		instructions.add(new ImmInstruction(Instr.LUI, "$r1", 0x00));
		instructions.add(new ImmInstruction(Instr.LI, "$r1", 0x20));
		instructions.add(new MemInstruction(Instr.READ, "$r1", "$r2", 0));
		instructions.add(new ImmInstruction(Instr.ADDI, "$r1", 1));
		instructions.add(new MemInstruction(Instr.WRITE, "$r2", "$r1", 0));
		instructions.add(new ImmInstruction(Instr.ADDI, "$r2", 1));
		instructions.add(new JmpInstruction(Instr.JL, "start"));

		for(Instruction instruction : instructions) {
			System.out.println(instruction);
		}
	}

}