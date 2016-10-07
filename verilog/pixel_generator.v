`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:01:23 09/05/2016 
// Design Name: 
// Module Name:    pixel_generator 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module pixel_generator(
	input enable,
	input reset,
	input clk,
	input [6:0] switch,
	input [9:0] pixel_counter,
	input [9:0] line_counter,
	input [1:0] pixel_state,
	output reg [7:0] color
    );
	 
	parameter SUB_PIXEL_WIDTH = 2; // 2 bits for 25MHz clock (count up to 4)
	parameter PIXELS = 800; // for a visible resolution width of 640 pixels
	parameter PIXEL_WIDTH = 10; // bit width pixel_counter
	parameter LINES = 525; // for a visible resolution width of 480 pixels
	parameter LINE_WIDTH = 10; // bit width of line_counter
	
	parameter TEXT_FETCH = 0;
	parameter GLYPH_FETCH = 1;
	parameter WAIT = 2;
	parameter DRAW = 3;
	 
	wire [12:0] char_addr;  
	wire [15:0] char;
	reg  [9:0] glyph_addr = 10'd0; 
	wire [15:0] glyph;
	wire foreground;
	wire one_sec_pulse;
	
	reg [31:0] seed = 32'h33CDFA82; // LFSR, start with seed
	reg [15:0] pixel_select = 16'd0;
	reg [1:0] rot_position = 2'b00; // 00 = 0*, 01 = 90*, 10 = 180*, 11 = 270*
		
	charBuffer _charBuffer(clk, 1'b0, char_addr, 16'd0, char, 1'b0, 1'b0, 13'd0, 16'd0);
	glyphBuffer _glyphBuffer(clk, 1'b0, glyph_addr, 16'd0, glyph, 1'b0, 1'b0, 10'd0, 16'd0);
	pulseGenerator #(22, 4_000_000) _pulseGenerator(enable, reset, clk, one_sec_pulse); // 40ms (25 Hz) pulse
	 
	// sequential logic
	always@(posedge clk) begin
		if (reset || !enable) begin
		
			seed <= 32'h33CDFA82; // LFSR, start with seed
			color <= 8'b00000000; // black
			
		end
		
		else if (switch[6]) begin
		
			if (one_sec_pulse)
				rot_position <= rot_position + 1'b1;
		
			if (pixel_state == DRAW) begin
				if (foreground & switch[5]) 
					color <= char[15:8];
				else if (foreground & switch[4])
					color <= {8{pixel_counter[3]^line_counter[3]}}; // checkerboard (8x8 pixels square)
				else if (foreground & switch[3]) begin
					// pseudo random number generator (Linear Feedback Shift Register, LFSR)
					seed <= { seed[30:0], seed[31]^seed[21]^seed[1]^seed[0] }; 
					color <= seed[7:0]; // noise
				end
				else if (foreground & switch[2])
					color <= 8'b11100000; // red
				else if (foreground & switch[1])
					color <= 8'b00011100; // green
				else if (foreground & switch[0])
					color <= 8'b00000011; // blue
				else if (foreground)
					color <= 8'b11111111; // white
				else
					color <= 8'b00000000; // black
			end
			
		end
		
		else if (switch[4])
		
			color <= {8{pixel_counter[3]^line_counter[3]}}; // checkerboard (8x8 pixels square)
			
		else if (switch[3]) begin
		
			// pseudo random number generator (Linear Feedback Shift Register, LFSR)
			seed <= { seed[30:0], seed[31]^seed[21]^seed[1]^seed[0] }; 
			color <= seed[7:0]; // noise
			
		end
		
		else if (switch[2])
		
			color <= 8'b11100000; // red
			
		else if (switch[1])
		
			color <= 8'b00011100; // green
			
		else if (switch[0])
		
			color <= 8'b00000011; // blue
			
		else
		
			color <= 8'b00000000; // black
			
	end
	
	// combinational logic
	always@* begin
		
		// NOTE: Adding a negated bit pattern appears to assume two's complement (and thus perform subtraction). 
		// Adding a high bit of 1'b0 fixes this (i.e. here I actually want to add the negated, 
		// positive bit pattern)
			
		case (rot_position)
			1: begin // 90* rotation, (x,y) -> (-y,x)
					glyph_addr = (char[7:0] << 2'd2) + {1'b0, ~pixel_counter[2:1]};
					if (~pixel_counter[0] == 1'b0)
						pixel_select = glyph >> ( 4'd8 + line_counter[2:0] );
					else
						pixel_select = glyph >> ( line_counter[2:0]  );
				end
			2: begin // 180* rotation, (x,y) -> (-x,-y)	
					glyph_addr = (char[7:0] << 2'd2) + {1'b0, ~line_counter[2:1]};
					if (~line_counter[0] == 1'b0)
						pixel_select = glyph >> ( 4'd8 + {1'b0, ~pixel_counter[2:0]} );
					else
						pixel_select = glyph >> ( {1'b0, ~pixel_counter[2:0]} );
				end
			3: begin // 270* rotation, (x,y) -> (y,-x)
					glyph_addr = (char[7:0] << 2'd2) + pixel_counter[2:1];
					if (pixel_counter[0] == 1'b0)
						pixel_select = glyph >> ( 4'd8 + {1'b0, ~line_counter[2:0]} );
					else
						pixel_select = glyph >> ( {1'b0, ~line_counter[2:0]}  );
				end
			default: begin // 0* rotation
					glyph_addr = (char[7:0] << 2'd2) + line_counter[2:1];
					if (line_counter[0] == 1'b0)
						pixel_select = glyph >> ( 4'd8 + pixel_counter[2:0] );
					else
						pixel_select = glyph >> ( pixel_counter[2:0] );
				end
		endcase
			
		/*if (&switch[2:0]) begin // 180* rotation, (x,y) -> (-x,-y)	
			glyph_addr = (char[7:0] << 2'd2) + {1'b0, ~line_counter[2:1]};
			if (~line_counter[0] == 1'b0)
				pixel_select = glyph >> ( 4'd8 + {1'b0, ~pixel_counter[2:0]} );
			else
				pixel_select = glyph >> ( {1'b0, ~pixel_counter[2:0]} );
		end
		else if (&switch[1:0]) begin // 90* rotation, (x,y) -> (-y,x)
			glyph_addr = (char[7:0] << 2'd2) + {1'b0, ~pixel_counter[2:1]};
			if (~pixel_counter[0] == 1'b0)
				pixel_select = glyph >> ( 4'd8 + line_counter[2:0] );
			else
				pixel_select = glyph >> ( line_counter[2:0]  );
		end
		else begin
			glyph_addr = (char[7:0] << 2'd2) + line_counter[2:1];
			if (line_counter[0] == 1'b0)
				pixel_select = glyph >> ( 4'd8 + pixel_counter[2:0] ); // use (4'd15 - pixel_counter[2:0]) ...
			else
				pixel_select = glyph >> ( pixel_counter[2:0] ); 		 // and (3'd7 - pixel_couunter[2:0]) to reverse text
		end*/
			
	end
	
	assign char_addr = { line_counter[8:3], pixel_counter[9:3] };
	//assign glyph_addr = (char[7:0] << 2'd2) + line_counter[2:1];
	assign foreground = pixel_select[0];

endmodule
