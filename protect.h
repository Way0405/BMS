#ifndef HEADER_FILE_PROTECT
#define HEADER_FILE_PROTECT

//�����첧�`�᪺���s�}���O�@�{��
void protect()
 {
   float reload;//x��᭫�s�}��
   output_high(protect_pin);
   for(int i=0;i<15;i++){
      delay_ms(1000);
      reload=(i+1)*100*10/15;//20��۰ʶ}��
      printf("reloading...:%2.2f %c\n\r",reload,'%');
      
   }
   printf("reset the program...");
   reset_cpu();//���ب禡�A�ݴ���
}

#endif


