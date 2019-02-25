 #ifndef HEADER_FILE_BALANCE
#define HEADER_FILE_BALANCE
#include <stdio.h>

void  balance()
 {
   /*ideal situation*/
   output_low(protect_pin);
   output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:1111
   output_low(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:0000
   

}
