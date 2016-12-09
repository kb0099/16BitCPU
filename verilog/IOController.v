module IOController(
	input clk, 
	input [23:0] address_in,
	input sensorready, 
	input [15:0] sensor_out, 
	input [15:0] buttons_out,
   input [15:0] leds_in,
	output reg [15:0] data_out,
   output reg [7:0] leds_out
	);
	// SET THATAE PARAMETERSS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	parameter BUTTON_ADDRESS = 19456;
	parameter SENSOR_ADDRESS = 19457;
   parameter LEDS_ADDRESS = 19958;
    
	 reg [15:0] sensor; // sensor data
	 reg [15:0] buttons; // button state
    initial data_out = 16'b0;
	 
    always@(posedge clk)
    begin
      if (sensorready==1'b1)
         sensor <= sensor_out;
      else if (address_in[14:0] == LEDS_ADDRESS && address_in[23] == 1'b1)
         leds_out <= leds_in[7:0];
      else 
         buttons <= buttons_out;
			
		// latch data_out to simulate the way memory serves data
		// Namely, provide data one cycle after the address is recieved
		if (address_in[14:0] == SENSOR_ADDRESS)
			data_out <= sensor;
		else if (address_in[14:0] == BUTTON_ADDRESS)
			data_out <= buttons;
		else
			data_out <= 16'b0;
    end


endmodule
