#include <main.h>
#include <vol_mea.h>
#include <charge.h>
#include <balance.h>
#include <protect.h>
#INT_EXT
/*charging check*/
void  EXT_isr(void) 
{
   printf("-----charging loading-----\n\r");
   int load_percent;
   for(int i=0;i<5;i++){
      delay_ms(500);
      load_percent=(i+1)*20;
      
      if(input(PIN_B0)){
         printf("loading......:%d %c",load_percent,'%');
         if(i==4)
            charge();
      }
      else
         return;
   }
}

#INT_EXT1
/*protect check*/
void  EXT1_isr(void) 
{
   input(PIN_B1);
   printf("warning!!!(abnormal situation)/n/r");
   protect();
}

/*normal situation*/

void main()
{
   setup_adc_ports(AN0_TO_AN2);

   enable_interrupts(INT_EXT);
   enable_interrupts(INT_EXT1);
   enable_interrupts(GLOBAL);
   
   setup_ccp1(CCP_OFF);//only charging need PWM
   while(TRUE)
   {
      vol_measure();
      balance();
      amp_measure();
      temp_measure();
   }

}
