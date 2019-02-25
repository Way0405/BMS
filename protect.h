#ifndef HEADER_FILE_PROTECT
#define HEADER_FILE_PROTECT

//腳位宣告
protect_pin=PIN_D4;
//
void protect()
 {
   float reload;//x秒後重新開機
   output_high(protect_pin);
   for(int i=0;i<15;i++){
      delay_ms(1000);
      reload=(i+1)*100*10/15;//20後自動開機
      printf("reloading...:%2.2f %c\n\r",reload,'%');
      
   }
   printf("reset the program...");
   reset_cpu();
}

#endif


