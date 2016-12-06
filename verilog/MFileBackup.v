
module NewFSMCore2(
  input 		clk,
  input 		reset,
  input[15:0] 	mem_data_in,
  output[15:0] 	cpu_data_out,
  output[23:0] 	mem_address,
	output 		we_mem,
	input debug_move_next,
	input[3:0] reg_debug_addr,
	output[15:0] reg_debug_output,
	output reg[1:0] sr
  );

  // variables
  localparam [1:0] Reset=2'd0, Fetch = 2'd1, Execute = 2'd2,  Memory = 2'd3;
  reg[1:0] ps = 2'b00;
  reg[1:0] ns;

  // 
  reg[23:0] MAR;
  reg[15:0] IR;

  // 
  localparam 	PC_START 	= 24'd9216;
  reg[23:0] 	PC 			= PC_START;
  //wire[23:0] 	pc_next;
  //reg[1:0]		sr;

  // wires
  // internal wires 
  wire[15:0] 	a, b, data_in_c, data_in_d, data_out_a, data_out_b;
  wire[3:0]		read_addr_a, read_addr_b, write_addr_c;
  reg[3:0] write_addr_d;
	reg[15:0] alu_controls;
  wire[10:0] 	jump_address;
  wire[10:4]	i_type_imm;
  wire[12:8]	m_type_imm;
  wire we_c, sw, lw, i_type, r_type, z, m_type, j_type;  
  wire[23:0] data_mem_addr;
  wire[1:0] pc_select;
  reg we_d; 

  //wire[10:4] i_type_imm;
  //wire[12:8] m_type_imm;

  // KTodo :: remove these extra signals
  //wire m_type = (IR[15:14] == 2'b01);
  //wire i_type = 0, j_type = 0, r_type = 1;

  // Return address reg number
  localparam REG_RA = 4'd14;
  
  // Debug output
  assign reg_debug_output = data_out_b;

  // ns combinational logic
  always @(*) begin
    case (ps)
      Reset:        	ns = reset ? Reset : Fetch;
      Fetch:			ns = debug_move_next ? Execute : Fetch; /* data_ready ?  */
      Execute: 		ns = m_type ? Memory : Fetch;
      Memory: 			ns = Fetch; /* data_ready ?  Fetch : Memory; */
    endcase
  end

  // sequential ps
  always @(posedge clk) begin
    //if(reset)   	ps		<= Reset;
    ps 	<= ns;
  end

  // MAR // IR
  // Reset/Ex -- to -- > Fetch 	: PC++; MAR fixed
  // Fetch ----- to ---> Execute: PC fixed; MAR <= PC;
  always @(posedge clk) begin
	 sr <= reset ? 2'd0 : ((|IR[15:11]) ? {lt, z} : sr); 	// KTODO :: need to update as core progresses
    case (ps)
      Reset: begin
        if(!reset)  begin
          PC 	<= {PC + 1};//[23:0]; 
          /*
           Increments PC so that it can be copied by MAR on end of 
           this fetch (beginning of exec)
           Which will used at the end of exec to fetch new data from mem.
          */
        end
      end
      Fetch: begin
			if(debug_move_next) begin
			  MAR <= PC;  		// this is in fact incremented value PC+1
			  // might have to wait here for 1 or more extra cycle for reading from mem.
			  // KTODO :: fix after mem controller is designed.
			  IR <= mem_data_in;
			 end else begin
				IR <= {{8{1'b0}}, reg_debug_addr, 4'd0};		// add $0, reg_debug; and capture reg output from port b.
			 end	 			 
      end
      Execute: begin
        // PC <= pc_next;			// should be safe to increment here
        // Does all the combinational logic
        if(j_type) begin
          // KTODO :: need these two statements
          // PC <= branch_address + 1'b1;
          // MAR <= branch_address + 1'b1;
			 PC 	<= {mem_address+1};//[23:0];
        end else if(!m_type) begin
          PC 	<= {PC+1};//[23:0]; // increment before going to Fetch for non-m type (make MAR redundant)   
        end
               
          IR 	<= 16'd0;
      end
      Memory: begin
        PC <= {PC+1};//[23:0];				// increment before going to Fetch
        IR <= 16'd0;
        // if branch instruction need to re-adjusts PC here.
      end
    endcase

    // but 
    if(reset) 	begin
      PC 	<= PC_START;
      MAR	<= PC_START;
      IR 	<= 16'd0;
    end
  end


	//
	//
	reg[15:0] lifafa[15:0];	// $zero is a dummy register.
	integer ii;						// loop variable
	
	// read operations
	assign data_out_a = (read_addr_a == 4'd0) ? 16'd0 : lifafa[read_addr_a];
	assign data_out_b = (read_addr_b == 4'd0) ? 16'd0 : lifafa[read_addr_b];
	
	// write operations
	always @(posedge clk) begin
		if(reset) begin
			for(ii = 0; ii <= 15; ii = ii + 1) begin
				lifafa[ii] <= 16'd0;
			end
		end else begin
			if(we_d) begin
				lifafa[write_addr_d] <= data_in_d;
			end
			if(we_c ) begin
				lifafa[write_addr_c] <= data_in_c;
			end
		end
		
	end
  

  wire others; 
  reg[15:0] result;
  
  //
  //
  //
  
  
  //localparam REG_RA = 4'd14;
  wire[4:0] opcode;										// 2-bit opcode + 3-bit instruction code
  wire[15:0] instruction;
  assign instruction = IR;
  assign opcode = instruction[15:11];
	

  localparam JUMP = 4'd10;
	reg v;
	
  always @(*) begin
    case(opcode[4:3])
      2'b00, 2'b01:
        case (opcode[2:0])
          3'b000: alu_controls = 4'd0;
          3'b001: alu_controls = 4'd1;
          3'b010: alu_controls = 4'd2;
          3'b011: alu_controls = 4'd3;
          3'b100: alu_controls = 4'd4;
          3'b101: alu_controls = 4'd5;
          3'b110: begin 
				alu_controls = (opcode[4:3] == 2'b00) ? 4'd6 : 4'd8;		// LUI		
			 end
          3'b111: begin
				alu_controls = (opcode[4:3] == 2'b00) ? 4'd7 : 4'd9;		// LI
			 end
			 
          //5'b01_000: alu_controls = 4'd0;				// add immediate
          //5'b01_111: alu_controls = 4'd0;				// load immediate or move imm: just add 0(a) + imm(b)
        endcase
      2'b10: begin 
        alu_controls = 4'd0;
        //5'b10_xxx: alu_controls = 4'd0;				// load word : lw $r1, $r2, 0 => $r1 = Mem[$r2 offset]
        //5'b10_xxx: alu_controls = 4'd0;				// store word: sw $r1, $r2, 0 => Mem[$r2 offset] = $r1;
      end
      2'b11: begin    
        // 5'b11_xxx is used for jumping, currently, any other instruction except ones above does a jump
        alu_controls = JUMP;
      end
    endcase
  end

  assign read_addr_a 	= instruction[3:0];
  assign read_addr_b 	= instruction[7:4];
  assign write_addr_c 	= jal_type ? REG_RA : instruction[3:0];
  assign others 			= 1'b0;

  // pc_select signal
  assign pc_select 		= (alu_controls == JUMP) ? 2'b11 : 2'b00;
  assign jump_address	= instruction[10:0];


  // port c is write enabled in same cycle
  // port d is write enabled if needed
  // 	- in 2nd cycle for load instruction


  // enable to true if lw	
  always @(posedge clk) begin		
    we_d 						<= lw; // (instruction[15:13] == 3'b100);		// load word
    write_addr_d 				<= instruction[3:0];
    if(reset) begin
      we_d 						<= 1'b0;
    end
  end


  // chages start
  ///assign we_d = lw;
  //assign write_addr_d = instruction[3:0];
  //changes end


  // KTODO :: Currently many instructions need write enable.
  assign we_c 					= (instruction[15:14] != 2'b11) && (instruction[15:14] != 3'b10) || jal_type;		// if not branch and not load/store word
  assign data_mem_we 		= (instruction[15:13] == 3'b101);												// store word 

  // control signals for lw/sw
  assign m_type_imm				= instruction[12:8];	
  assign i_type_imm				= instruction[10:4];
  assign lw 						= (instruction[15:13] == 3'b100);		// load word
  assign sw 						= (instruction[15:13] == 3'b101);		// load word
  assign r_type					= instruction[15:14] == 2'b00;
  assign i_type					= instruction[15:14] == 2'b01;
  assign m_type					= instruction[15:14] == 2'b10;
  assign j_type					= instruction[15:14] == 2'b11; 		// KCC
  assign jl_type					= instruction[15:11] == 5'b11000; 		// KCC
  assign jal_type 				= instruction[15:11] == 5'b11011;
  assign jr_type					= instruction[15:11] == 5'b11100;
  assign beq						= instruction[15:11] == 5'b11001;
  assign bne						= instruction[15:11] == 5'b11010;

  assign we_mem = data_mem_we;
  
 //
 //
 //
  localparam 	ADD 	= 4'd0,
					SUB 	= 4'd1,
					AND 	= 4'd2,
					OR 	= 4'd3,
					XOR 	= 4'd4,
					SLL 	= 4'd5,
					SRL 	= 4'd6,
					SRA 	= 4'd7,
					LUI	= 4'd8,					
					LI 	= 4'd9;
					
	always @(*) begin
	v = 1'b0;
		case (alu_controls)
			ADD: begin
				result = a + b;
				v = (~a[15] & ~b[15] & result[15]) | (a[15] & b[15] & ~result[15]);
			end
			SUB: begin
				result = a - b;
				v = (~a[15] & b[15] & result[15]) | (a[15] & ~b[15] & ~result[15]); 
			end
			AND: begin
				result = a & b;
			end
			OR: begin
				result = a | b;
			end
			XOR: begin
				result = a ^ b;
			end
			
			// --------------------------
			// KTODO :: Following operations are disabled for current build.
			SLL: begin
				result = a << b[3:0];
			end
			SRL: begin
				result = a >> b[3:0];
			end
			SRA: begin
				result = a >>> b[3:0];
			end
			LI: begin
				result = b;	// comented because : LI will use Add instruction.
			end 
			LUI: begin
				result = b << 7;	// KTODO :: LUI will also use shift (left) => LUI $r1, 0x8A => $r1 = 0x8A << 7; shifted by 7 bits
			end
			
			// --------------------------
			
			default: begin
				result = {16{1'd1}};			// KTODO :: for testing ALU will output 16 1's for all other operations.
			end
		endcase
		
	end
	
	// other logic
	assign z 	= (result == 16'd0);
	//assign v 	= 1'b0;							// KTODO
	assign lt 	= result[15] ^ v;
	
	

  // internal logic
  assign a 					=  data_out_a;
	// if store, do: a=a, b=0, result = a+0 = a
  assign b 					=  i_type ? {8'd0, i_type_imm} : (sw ? 16'd0:data_out_b); //(i_type || we_mem) ? 16'b0 : data_out_b;  	// i type or store type
  //assign a 				= (instruction[15:14] == 2'b01) ? 0 : data_out_a;
  //assign b 				= (instruction[15:14] == 2'b01) ? instruction[10:4] : data_out_b;
  assign data_in_c 			= jal_type ? PC : result;
  assign data_in_d 			= mem_data_in;
  assign data_mem_addr		= {m_type_imm, data_out_b};


  // Core outputs
  assign cpu_data_out 		= result;
  // status register will be zero when equal.
  assign blt 					= IR[15:11] == 5'b11101;
  assign bleq 					= IR[15:11] == 5'b11110;
  //assign jr						= IR[15:11] == 5'b11100;
  assign mem_address			= m_type ? data_mem_addr : ( jr_type ? data_out_a : ( ( (jl_type | jal_type) || (beq & (sr[0])) || (bne & (~sr[0])) || (blt & sr[1]) || (bleq & (|sr))  )? (PC + { {13{jump_address[10]}}, jump_address}) : PC)); // KTODO :: check
  /* assign next_pc 			=(pc_select == 2'b11) ? {13'd0, jump_address} : pc + 1'b1;	 */

endmodule









module NumberToSevenSegment(
    input wire [3:0] number,
    output reg [6:0] pattern
    );
	 
	 /* combinational logic */
	 always @*
	 case (number)	/* full + parallel */
	 /*4'b0000: pattern = 7'babcdefg */
		4'b0000: pattern = 7'b0000001;
		4'b0001: pattern = 7'b1001111;
		4'b0010: pattern = 7'b0010010;
		4'b0011: pattern = 7'b0000110;
		4'b0100: pattern = 7'b1001100;
		4'b0101: pattern = 7'b0100100;
		4'b0110: pattern = 7'b0100000;
		4'b0111: pattern = 7'b0001111;
		4'b1000: pattern = 7'b0000000;
		4'b1001: pattern = 7'b0001100;
		4'b1010: pattern = 7'b0001000;
		4'b1011: pattern = 7'b1100000;
		4'b1100: pattern = 7'b0110001;
		4'b1101: pattern = 7'b1000010;
		4'b1110: pattern = 7'b0110000;
		4'b1111:	pattern = 7'b0111000;	
	 endcase
	 

endmodule

module KSevenSegmentMux
  #(parameter N = 17)	
  (
  	input      clk,
  	input      reset,
    input[3:0] d3, d2, d1, d0, /* 4 numbers from left to right */
    input dp3, dp2, dp1, dp0, /* decimal point in order */
    output reg[3:0] an,				/* this directly connects to FPGA an pins */
    output[7:0] pattern		/* {dp, pattern} */
  );
  
  /* current number */
    reg[3:0] number;
    reg dp;		/* current dp */
  
    /* counter */
    localparam N1 = N-1;
    reg[N1:0] count;
    wire[N1:0] next_count;
    localparam MAX_COUNT = {N{1'b1}};
    
  /* states */
    localparam[1:0] D0 = 2'b00, D1 = 2'b01, D2 = 2'b10, D3=2'b11;
    reg[1:0] ps, ns;		/* present and next state logic */
    
  /* sequential logic */
    always @(posedge clk, posedge reset) begin
      if(reset) begin
        count <= 0;
        ps <= D0;
      end
      else begin
        count <= next_count;
        ps <= ns;
      end        
    end
    
    // continuous assignment
    assign next_count = count + 1'b1;
    
    /* combinational logic */
    always @* begin  
      ns = ps; /* default */
      if(next_count == MAX_COUNT)	
        ns = ps+1'b1;
    end
    
    /* output logic */
    assign pattern[7] = dp;    
    always @* begin
      /* defaults */
      an = 4'b1111; /* active low, means 1111 will disable all */
      case(ps)
        D0: begin
          an[0] = 1'b0;
          number = d0;
          dp = dp0;
        end
        D1: begin
          an[1] = 1'b0;
          number = d1;
          dp = dp1;
        end
        D2: begin
          an[2] = 1'b0;
          number = d2;
          dp = dp2;
        end
        D3: begin
          an[3] = 1'b0;
          number = d3;
          dp = dp3;
        end
      endcase
    end
      

    // the decoder instance
    NumberToSevenSegment ntss (.number(number), .pattern(pattern[6:0]));
  
endmodule
          
   


