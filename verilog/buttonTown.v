`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:39:41 12/01/2016 
// Design Name: 
// Module Name:    buttonTown 
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
module buttonTown(
   input clk,
   input buttonUp,
   input buttonLeft,
   input buttonCenter,
   input buttonRight,
   input buttonDown,
   input [5:0] switches,
   output reg [15:0] buttonsOut
    );
	 
	 wire buttonUp_db, buttonLeft_db, buttonCenter_db, buttonRight_db, buttonDown_db;
	 
	 debounce _db_up(clk, buttonUp, buttonUp_db);
	 debounce _db_left(clk, buttonLeft, buttonLeft_db);
	 debounce _db_center(clk, buttonCenter, buttonCenter_db);
	 debounce _db_right(clk, buttonRight, buttonRight_db);
	 debounce _db_down(clk, buttonDown, buttonDown_db);
    
    reg [10:0] buttons;
    
    always@*
    begin
      buttonsOut = {5'b00000, buttons};
    end
    
    always@(posedge clk)
    begin
      if (buttonUp_db == 1'b1)
         buttons[0] = 1'b1;
      else
         buttons[0] = 1'b0;
         
      if (buttonRight_db == 1'b1)
         buttons[1] = 1'b1;
      else
         buttons[1] = 1'b0;
         
      if (buttonDown_db == 1'b1)
         buttons[2] = 1'b1;
      else
         buttons[2] = 1'b0;
         
      if (buttonLeft_db == 1'b1)
         buttons[3] = 1'b1;
      else
         buttons[3] = 1'b0;
         
      if (buttonCenter_db == 1'b1)
         buttons[4] = 1'b1;
      else
         buttons[4] = 1'b0;
      
      if (switches[0] == 1'b1)
         buttons[10] = 1'b1;
      else
         buttons[10] = 1'b0;
      
      if (switches[1] == 1'b1)
         buttons[9] = 1'b1;
      else
         buttons[9] = 1'b0;
      
      if (switches[2] == 1'b1)
         buttons[8] = 1'b1;
      else
         buttons[8] = 1'b0;
      
      if (switches[3] == 1'b1)
         buttons[7] = 1'b1;
      else
         buttons[7] = 1'b0;
      
      if (switches[4] == 1'b1)
         buttons[6] = 1'b1;
      else
         buttons[6] = 1'b0;
      
      if (switches[5] == 1'b1)
         buttons[5] = 1'b1;
      else
         buttons[5] = 1'b0;
    end
      


endmodule
