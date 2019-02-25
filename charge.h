#ifndef HEADER_FILE_CHARGE
#define HEADER_FILE_CHARGE

#include <stdio.h>

void charge(){
   setup_ccp1(CCP_PWM);//open the pwm
   /*-------setting pwm property------- */
   
   /*----------------------------------*/
   /*charge all*/
   while(1){
      output_high(PIN_D4);//total switch
      output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:1111
      output_low(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:0000
      printf("-----recheck battery situation-----\n\r");vol_measure();//recheck voltage
      delay_ms(1000);
      if(vol1>4.0||vol2>4.0||vol3>4.0||vol4>4.0||vol5>4.0||vol6>4.0||vol7>4.0||vol8>4.0||vol9>4.0||vol10>4.0||vol11>4.0||vol12>4.0||vol13>4.0||vol14>4.0||vol14>4.0||vol15>4.0||vol16>4.0)
         break;
   }
   
   while(vol1<=4.0){
      printf("charing 1st battery:\n\r");
         if(vol1>4.0)
            break;
      output_low(PIN_D0);output_low(PIN_D1);output_low(PIN_D2);output_low(PIN_D3);//muxB:0000
      output_low(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:0000
      vol_measure();
   }
   
   while(vol2<=4.0){
      printf("charing 2nd battery:\n\r");
      output_high(PIN_D0);output_low(PIN_D1);output_low(PIN_D2);output_low(PIN_D3);//muxB:1000
      output_high(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:1000
      vol_measure();
      if(vol2>4.0)
         break;
   } 
 
   while(vol3<=4.0){
      printf("charing 3rd battery:\n\r");
      output_high(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_low(PIN_D3);//muxB:0100
      output_high(PIN_A3);output_high(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:0100
      vol_measure();
      if(vol3>4.0)
         break;
   } 

   while(vol4<=4.0){
   printf("charing 4th battery:\n\r");
      output_high(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_low(PIN_D3);//muxB:1100
      output_high(PIN_A3);output_high(PIN_A4);output_low(PIN_A5);output_low(PIN_C1);//muxA:1100
      vol_measure();
      if(vol4>4.0)
         break;
   }
   
   while(vol5<=4.0){
   printf("charing 5th battery:\n\r");
      output_low(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);//muxB:0010
      output_low(PIN_A3);output_low(PIN_A4);output_high(PIN_A5);output_low(PIN_C1);//muxA:0010
      vol_measure();
      if(vol5>4.0)
         break;
   }
   
   while(vol6<=4.0){
      printf("charing 6th battery:\n\r");
      output_high(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);//muxB:1010
      output_high(PIN_A3);output_low(PIN_A4);output_high(PIN_A5);output_low(PIN_C1);//muxA:1010
      vol_measure();
      if(vol6>4.0)
         break;
   }
   
   while(vol7<=4.0){
   printf("charing 7th battery:\n\r");
      output_low(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);//muxB:0110
      output_low(PIN_A3);output_high(PIN_A4);output_high(PIN_A5);output_low(PIN_C1);//muxA:0110
      vol_measure();
      if(vol7>4.0)
         break;
   }
   
   while(vol8<=4.0){
      printf("charing 8th battery:\n\r");
      output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_low(PIN_D3);//muxB:1110
      output_high(PIN_A3);output_high(PIN_A4);output_high(PIN_A5);output_low(PIN_C1);//muxA:1110
      vol_measure();
      if(vol8>4.0)
         break;
   }
   
   while(vol9<=4.0){
      printf("charing 9th battery:\n\r");
      output_low(PIN_D0);output_low(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);//muxB:0001
      output_low(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_high(PIN_C1);//muxA:0001
      vol_measure();
      if(vol9>4.0)
         break;
   }
   
   while(vol10<=4.0){
      printf("charing 10th battery:\n\r");
      output_high(PIN_D0);output_low(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);//muxB:1001
      output_high(PIN_A3);output_low(PIN_A4);output_low(PIN_A5);output_high(PIN_C1);//muxA:1001
      vol_measure();
      if(vol10>4.0)
         break;
   }
   
   while(vol11<=4.0){
      printf("charing 11th battery:\n\r");
      output_low(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);//muxB:0101
      output_low(PIN_A3);output_high(PIN_A4);output_low(PIN_A5);output_high(PIN_C1);//muxA:0101
      vol_measure();
      if(vol11>4.0)
         break;
   } 
   
   while(vol12<=4.0){
      printf("charing 12th battery:\n\r");
      output_high(PIN_D0);output_high(PIN_D1);output_low(PIN_D2);output_high(PIN_D3);//muxB:1101
      output_high(PIN_A3);output_high(PIN_A4);output_low(PIN_A5);output_high(PIN_C1);//muxA:1101
      vol_measure();
      if(vol12>4.0)
         break;
   }
   
   while(vol13<=4.0){
      printf("charing 13th battery:\n\r");
      output_low(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:0011
      output_low(PIN_A3);output_low(PIN_A4);output_high(PIN_A5);output_high(PIN_C1);//muxA:0011
      vol_measure();
      if(vol13>4.0)
         break;
   }
   
   while(vol14<=4.0){
      printf("charing 14th battery:\n\r");
      output_high(PIN_D0);output_low(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:1011
      output_high(PIN_A3);output_low(PIN_A4);output_high(PIN_A5);output_high(PIN_C1);//muxA:1011
      vol_measure();
      if(vol14>4.0)
         break;
   }
   
   while(vol15<=4.0){
   printf("charing 15th battery:\n\r");
      output_low(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:0111
      output_low(PIN_A3);output_high(PIN_A4);output_high(PIN_A5);output_high(PIN_C1);//muxA:0111
      vol_measure();
      if(vol15>4.0)
         break;
   }
   
   while(vol16<=4.0){
      printf("charing 16th battery:\n\r");
      output_high(PIN_D0);output_high(PIN_D1);output_high(PIN_D2);output_high(PIN_D3);//muxB:1111
      output_high(PIN_A3);output_high(PIN_A4);output_high(PIN_A5);output_high(PIN_C1);//muxA:1111
      vol_measure();
      if(vol16>4.0)
         break;
   }
   return;
}

#endif

