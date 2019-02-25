#ifndef HEADER_FILE_PROTECT
#define HEADER_FILE_PROTECT

void protect(){
   float reload;
   output_high(PIN_D4);
   for(int i=0;i<15;i++){
      delay_ms(1000);
      reload=(i+1)*100*10/15;//20後自動開機
      printf("reloading...:%2.2f %c\n\r",reload,'%');
      
   }
   printf("reset the program...");
   reset_cpu();
}

#endif


