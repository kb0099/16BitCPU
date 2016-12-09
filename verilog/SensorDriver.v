`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:24:32 12/04/2016 
// Design Name: 
// Module Name:    SensorDriver 
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
module SensorDriver(
   input clock,
   inout data,
   output reg [15:0] send_data,
   output reg data_ready
//   output reg led1,
//   output reg led2,
//   output reg led3,
//   output reg led4,
//   output reg led5,
//   output reg led6,
//   output reg led7,
//   output reg led8
    );
    // States
    reg [3:0] state = INITIAL;
    parameter INITIAL = 0, INITIALIZE = 1, INIT_LOW = 2, INIT_HIGH = 3, RESP_LOW = 4, RESP_HIGH = 5, SEND_LOW = 6, SEND_HIGH = 7, SEND_DATA = 8;
    // 1 second timer for initial state
    reg [26:0] init_timer = 27'd0;
    // Counter for timing
    reg [21:0] counter = 22'd0;
    // Counter for number of bits that have been read.
    reg [5:0] data_count = 6'd0;
    // Register to store bits as they are read.
    reg [15:0] data_to_send = 16'd0;
    // Register to send to the inout pin when applicable
    reg data_out = 1'b1;
    // Register to check validity of read data
    reg [7:0] checksum = 8'd0;
    reg [7:0] checkcheck = 16'd0;
    // Decimal values of temp/humid
    reg [7:0] temp_dec = 8'd0;
    reg [7:0] humi_dec = 8'd0;
    
    // Inout pin handling, code controls value in INITIAL-INIT_LOW states, sensor controls value in remaining
    assign data = (state == INITIAL || state == INITIALIZE || state == INIT_LOW) ? data_out : 1'bZ;
    
    always@(posedge clock)
      begin
      // Wait 1 second before sending data to allow sensor to reach stable state. (data == 1)
      if (state == INITIAL)
         begin
         //send_data <= data_count;
         if (init_timer == 100_000_000)
            begin
            state <= INITIALIZE;
            init_timer <= 27'd0;
            end
         else
            begin
            init_timer <= init_timer + 1'b1;
            data_out <= 1'b1;
            end
         end
      // Initialize registers and whatever else needs to be initialized for each sensor run. (data == 0)
      else if (state == INITIALIZE)
         begin
         counter <= 22'd0;
         data_count <= 6'd0;
         state <= INIT_LOW;
         data_ready <= 1'b0;
         data_out <= 1'b0;
//         led1 <= 1'b0;
//         led2 <= 1'b0;
//         led3 <= 1'b0;
//         led4 <= 1'b0;
//         led5 <= 1'b0;
//         led6 <= 1'b0;
//         led7 <= 1'b0;
//         led8 <= 1'b0;
         end
      // When the communication between MCU and DHT11 begins, the programme of  MCU  will set Data  
      // Single-bus voltage  level  from  high  to  low and this process must take at least 18 ms
      // to ensure DHT's detection of MCU's signal, (data == 0)
      else if (state == INIT_LOW)
         begin
         if (counter == 2_000_000)
            begin
            state <= INIT_HIGH;
            counter <= 22'd0;
            data_out <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // then MCU will pull up voltage and wait 20-40us for DHT'sresponse.
      // DHT responds by pulling voltage down. (data == 1)
      else if (state == INIT_HIGH)
         begin
         // Sensor's pulldown is recognized.
         if (data == 0 && counter > 100 && counter <= 3999)
         begin
            state <= RESP_LOW;
            counter <= 22'd0;
         end
         // If sensor takes too long to respond, return to INITIAL state
         else if (counter > 4000)
            begin
            state <= INITIAL;
            //led1 <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // Once DHT detects the start signal, it will send out a low-voltage-level response signal, 
      // which lasts 80us (data == 0)
      else if (state == RESP_LOW)
         begin
         if (data == 1 && counter > 100 && counter < 9000)
            begin
            state <= RESP_HIGH;
            counter <= 22'd0;
            end
         else if (counter == 9000)
            begin
            state <= INITIAL;
            //led2 <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // Then the programme of DHT sets Data Single-bus voltage level from low to high and 
      // keeps it for 80us for DHT's preparation for sending data. (data == 1)
      else if (state == RESP_HIGH)
         begin
         if (data == 0 && counter > 100 && counter < 9000)
            begin
            state <= SEND_LOW;
            counter <= 22'd0;
            end
         // Signal takes too long, return to INITIAL
         else if (counter == 9000)
            begin
            state <= INITIAL;
            //led3 <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // When DHT is sending data to MCU, every bit of data begins with the 50us low-voltage-level
      // and the length of the following high-voltage-level signal determines whether 
      // data bit is "0" or "1" (26-28 uS == 0 AND 70 uS == 1) ((data == 0))
      else if (state == SEND_LOW)
         begin
         // Once all bits are read, success
         if (data_count == 40)
            begin
            state <= SEND_DATA;
//            led5 <= 1'b1;
//            led7 <= 1'b1;
//            led8 <= 1'b1;
            end
         // Move to SEND_HIGH state to read next bit
         //else if (data == 1 && counter > 4000 && counter < 6000)
         else if (counter == 5600)
            begin
            state <= SEND_HIGH;
            counter <= 22'd0;
            data_count <= data_count + 1'b1;
            end
         // data doesn't go high in time
         else if (counter == 6000)
            begin
            state <= INITIAL;
            //led4 <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // High signal from sensor has been read, bit is determined by the length of the signal.
      // 26-28 uS == 0 ; 70 uS == 1 ((data == 1))
      else if (state == SEND_HIGH)
         begin
         // Timing matches a 0 bit
         if (data == 0 && counter >= 2000 && counter <= 3000)
            begin
            // 0
            case (data_count)
               1: data_to_send[15] <= 1'b0;
               2: data_to_send[14] <= 1'b0;
               3: data_to_send[13] <= 1'b0;
               4: data_to_send[12] <= 1'b0;
               5: data_to_send[11] <= 1'b0;
               6: data_to_send[10] <= 1'b0;
               7: data_to_send[9] <= 1'b0;
               8: data_to_send[8] <= 1'b0;
               9: humi_dec[7] <= 1'b0;
               10: humi_dec[6] <= 1'b0;
               11: humi_dec[5] <= 1'b0;
               12: humi_dec[4] <= 1'b0;
               13: humi_dec[3] <= 1'b0;
               14: humi_dec[2] <= 1'b0;
               15: humi_dec[1] <= 1'b0;
               16: humi_dec[0] <= 1'b0;
               17: data_to_send[7] <= 1'b0;
               18: data_to_send[6] <= 1'b0;
               19: data_to_send[5] <= 1'b0;
               20: data_to_send[4] <= 1'b0;
               21: data_to_send[3] <= 1'b0;
               22: data_to_send[2] <= 1'b0;
               23: data_to_send[1] <= 1'b0;
               24: data_to_send[0] <= 1'b0;
               25: temp_dec[7] <= 1'b0;
               26: temp_dec[6] <= 1'b0;
               27: temp_dec[5] <= 1'b0;
               28: temp_dec[4] <= 1'b0;
               29: temp_dec[3] <= 1'b0;
               30: temp_dec[2] <= 1'b0;
               31: temp_dec[1] <= 1'b0;
               32: temp_dec[0] <= 1'b0;
               33: checksum[7] <= 1'b0;
               34: checksum[6] <= 1'b0;
               35: checksum[5] <= 1'b0;
               36: checksum[4] <= 1'b0;
               37: checksum[3] <= 1'b0;
               38: checksum[2] <= 1'b0;
               39: checksum[1] <= 1'b0;
               40: checksum[0] <= 1'b0;
            endcase
            state <= SEND_LOW;
            counter <= 22'd0;
            end
         // Timing matches a 1 bit
         else if (data == 0 && counter >= 6000 && counter < 8000)
            begin
            // 1
            case (data_count)
               1: data_to_send[15] <= 1'b1;
               2: data_to_send[14] <= 1'b1;
               3: data_to_send[13] <= 1'b1;
               4: data_to_send[12] <= 1'b1;
               5: data_to_send[11] <= 1'b1;
               6: data_to_send[10] <= 1'b1;
               7: data_to_send[9] <= 1'b1;
               8: data_to_send[8] <= 1'b1;
               9: humi_dec[7] <= 1'b1;
               10: humi_dec[6] <= 1'b1;
               11: humi_dec[5] <= 1'b1;
               12: humi_dec[4] <= 1'b1;
               13: humi_dec[3] <= 1'b1;
               14: humi_dec[2] <= 1'b1;
               15: humi_dec[1] <= 1'b1;
               16: humi_dec[0] <= 1'b1;
               17: data_to_send[7] <= 1'b1;
               18: data_to_send[6] <= 1'b1;
               19: data_to_send[5] <= 1'b1;
               20: data_to_send[4] <= 1'b1;
               21: data_to_send[3] <= 1'b1;
               22: data_to_send[2] <= 1'b1;
               23: data_to_send[1] <= 1'b1;
               24: data_to_send[0] <= 1'b1;
               25: temp_dec[7] <= 1'b1;
               26: temp_dec[6] <= 1'b1;
               27: temp_dec[5] <= 1'b1;
               28: temp_dec[4] <= 1'b1;
               29: temp_dec[3] <= 1'b1;
               30: temp_dec[2] <= 1'b1;
               31: temp_dec[1] <= 1'b1;
               32: temp_dec[0] <= 1'b1;
               33: checksum[7] <= 1'b1;
               34: checksum[6] <= 1'b1;
               35: checksum[5] <= 1'b1;
               36: checksum[4] <= 1'b1;
               37: checksum[3] <= 1'b1;
               38: checksum[2] <= 1'b1;
               39: checksum[1] <= 1'b1;
               40: checksum[0] <= 1'b1;
            endcase
            state <= SEND_LOW;
            counter <= 22'd0;
            end
         // Signal is not pulled low in time
         else if (counter == 8000)
            begin
            state <= INITIAL;
            //led6 <= 1'b1;
            end
         else
            counter <= counter + 1'b1;
         end
      // Data has sucessfully been read and can now be sent to memory
      else if (state == SEND_DATA)
         begin
         checkcheck <= data_to_send[15:8] + data_to_send[7:0] + humi_dec + temp_dec;
         if (checkcheck[7:0] == checksum)
            begin
            send_data <= data_to_send;
            data_ready <= 1'b1;
            end
         state <= INITIAL;
         end
      end
endmodule
