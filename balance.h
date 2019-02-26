 #ifndef HEADER_FILE_BALANCE
#define HEADER_FILE_BALANCE
#include <stdio.h>

void  balance()
 {
	int i;
   /*ideal situation*/
   output_low(total_switch);
   for(i=0;i<=4;i++)
   {
	output_high(mux_b_sel[i]);//muxB:1111
	output_low(mux_a_sel[i]);//muxA:0000
   }
   /*原版
   output_high(mux_b_sel[0] );output_high(mux_b_sel[1]);output_high(mux_b_sel[2]);output_high(mux_b_sel[3]);//muxB:1111
   output_low(mux_a_sel[0]);output_low(mux_a_sel[1]);output_low(mux_a_sel[2]);output_low(mux_a_sel[3]);//muxA:0000
   */

}
