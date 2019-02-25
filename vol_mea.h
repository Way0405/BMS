#ifndef HEADER_FILE_MEASURE
#define HEADER_FILE_MEASURE
static float x,vol1,vol2,vol3,vol4,vol5,vol6,vol7;
static float vol8,vol9,vol10,vol11,vol12,vol13,vol14,vol15,vol16;//next time change in maxtrix improve efficiency
#include<stdio.h>
void vol_measure()
{
   int i;
   set_adc_channel (0);  
     for(i=0;i<5;i++){ 
     output_B(0x00); //battery1
     /*0000 0000*/
     x=read_adc();
     vol1=x*5/65536;
     printf("x=%f;voltage1:%1.3f\n\r",x,vol1);
     delay_ms(100);
     
     output_B(0x20);//battery2
     /*0010 0000*/
     x=read_adc();
     vol2=x*5/65536;
     printf("x=%f;voltage2:%1.3f\n\r",x,vol2);
     delay_ms(100);
     
     output_B(0x10);//battery3
     /*0001 0000*/
     x=read_adc();
     vol3=x*5/65536;
     printf("x=%f;voltage3:%1.3f\n\r",x,vol3);
     delay_ms(100); 
     
     output_B(0x30);//battery4
     /*0011 0000*/
     x=read_adc();
     vol4=x*5/65536;
     printf("x=%f;voltage4:%1.3f\n\r",x,vol4);
     delay_ms(100);
     
     output_B(0x08);//battery5
     /*0000 1000*/
     x=read_adc();
     vol5=x*5/65536;
     printf("x=%f;voltage5:%1.3f\n\r",x,vol5);
     delay_ms(100);
     
     output_B(0x28);//battery6
     /*0010 1000*/
     x=read_adc();
     vol6=x*5/65536;
     printf("x=%f;voltage6:%1.3f\n\r",x,vol6);
     delay_ms(100);
     
     output_B(0x18);//battery7
     /*0001 1000*/
     x=read_adc();
     vol7=x*5/65536;
     printf("x=%f;voltage7:%1.3f\n\r",x,vol7);
     delay_ms(100); 
 
     output_B(0x38);//battery8
     /*0011 1000*/
     x=read_adc();
     vol8=x*5/65536;
     printf("x=%f;voltage8:%1.3f\n\r",x,vol8);
     delay_ms(100);

     output_B(0x04);//battery9
     /*0000 0100*/
     x=read_adc();
     vol9=x*5/65536;
     printf("x=%f;voltage9:%1.3f\n\r",x,vol9);
     delay_ms(100);

     output_B(0x24);//battery10
     /*0010 0100*/
     x=read_adc();
     vol10=x*5/65536;
     printf("x=%f;voltage10:%1.3f\n\r",x,vol10);
     delay_ms(100);

     output_B(0x14);//battery11
     /*0001 0100*/
     x=read_adc();
     vol11=x*5/65536;
     printf("x=%f;voltage11:%1.3f\n\r",x,vol11);
     delay_ms(100);
     
     output_B(0x34);//battery12
     /*0011 0100*/
     x=read_adc();
     vol12=x*5/65536;
     printf("x=%f;voltage12:%1.3f\n\r",x,vol12);
     delay_ms(100);


     output_B(0x0c);//battery13
     /*0000 1100*/
     x=read_adc();
     vol13=x*5/65536;
     printf("x=%f;voltage13:%1.3f\n\r",x,vol13);
     delay_ms(100);

     output_B(0x2c);//battery14
     /*0010 1100*/
     x=read_adc();
     vol14=x*5/65536;
     printf("x=%f;voltage14:%1.3f\n\r",x,vol14);
     delay_ms(100);

     output_B(0x1c);//battery15
     /*0001 1100*/
     x=read_adc();
     vol15=x*5/65536;
     printf("x=%f;voltage15:%1.3f\n\r",x,vol15);
     delay_ms(100);
     output_B(0x3c);//battery16
     /*0011 1100*/
     x=read_adc();
     vol16=x*5/65536;
     printf("x=%f;voltage16:%1.3f\n\r",x,vol16);
     delay_ms(100);
    }
   return;
}

void amp_measure(){//total current measure

   float x,amp;
   set_adc_channel (1);//設定read_adc的腳位
   x=read_adc();
   x=x*5/65536;
   amp=(x-2.5)*100;
   printf("x=%f,current=%1.3fmA\n\r",x,amp);
   return;
}

void temp_measure(){
return;
}

#endif



