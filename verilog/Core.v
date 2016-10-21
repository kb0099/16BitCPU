`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:08:23 10/20/2016 
// Design Name: 
// Module Name:    Core 
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
module Core(
   input clock,
   input [15:0] datain,
   output reg [14:0] addrout,
   output reg [15:0] dataout,
   output reg we
    );
    
    parameter [14:0] startAddr = 15'd9216;
    reg [2:0] CI = 3'b000;
    reg inEx = 0;
    reg [15:0] currentData = 16'd0;
    reg [14:0] dataAddr = 15'd0;
    reg [14:0] instrAddr = startAddr;
    reg [25:0] clockLimit = 26'd0;
    initial we = 1'b0;

   always@(posedge clock)
   begin
      clockLimit <= clockLimit + 1'b1;
      if (clockLimit == 10) begin
         if (inEx == 0) begin
         //addrout = startaddr;
         inEx <= 1;
         //addrout <= instrAddr;
         $display("instr address: %d", instrAddr);
         
      end
      else if (CI == 0) begin 
         $display("INSTRUCTION IN: %d", datain);
         case (datain)
            0: CI <= 3'b001; // read
            1: CI <= 3'b010; // write
            2: CI <= 3'b011; // add
            3: CI <= 3'b100; // jump
         endcase
      end

      if(CI > 0)begin
         case(CI)
            1: begin // read 1
               //addrout <= dataAddr;
               we <= 1'b0;
               CI <= 3'b110;
               $display("READ1");
               end
            2: begin // write
               dataout <= currentData;
               //addrout <= dataAddr;
               we <= 1'b1;
               CI <= 3'b100;
               //inEx <= 1'b0;
               //instrAddr <= instrAddr + 1'b1;
               $display("WRITE");
               end
            3: begin // add
               currentData <= currentData + 1'b1;
               dataAddr <= dataAddr + 1'b1;
               CI <= 3'b000;
               inEx <= 1'b0;
               we <= 1'b0;
               instrAddr <= instrAddr + 1'b1;
               $display("ADD instr addr: %d", instrAddr);
               end
            4: begin // jump/reset
               instrAddr <= startAddr;
               CI <= 3'b000;
               $display("JUMP");
               inEx <= 1'b0;
               we <= 1'b0;
               //instrAddr <= instrAddr + 1'b1;
               end
            5: begin // read 3
               currentData <= datain;
               CI <= 3'b000;
               inEx <= 1'b0;
               instrAddr <= instrAddr + 1'b1;
               $display("READ2");
               end
            6: begin // read 2 (wait)
               CI <= 3'b101;
               end
          endcase
       end
    end
  end
  
  always@*
  begin
  if (inEx == 0)
    addrout = instrAddr;
  else
    addrout = dataAddr;
  end
      
endmodule
