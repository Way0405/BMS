#ifndef HEADER_FILE_CHARGE
#define HEADER_FILE_CHARGE

#include <stdio.h>

void charge()
{
   setup_ccp1(CCP_PWM);//open the pwm
   /*-------setting pwm property------- */
   
   /*----------------------------------*/
	/////////大電流串聯充電//////////////
	int i_set,i_battery;
   while(1)
	{
		output_high(total_switch);
		for(i_set=0;i_set<=4;i_set++)
		 {
			output_high(mux_b_sel[i_set]);//muxB:1111
			output_low(mux_a_sel[i_set]);//muxA:0000
		 }
	/*
	output_high(mux_b_sel[0]);output_high(mux_b_sel[1]);output_high(mux_b_sel[2]);output_high(mux_b_sel[3]);//muxB:1111
	output_low(mux_a_sel[0]);output_low(mux_a_sel[1]);output_low(mux_a_sel[2]);output_low(mux_a_sel[3]);//muxA:0000
	*/
		printf("-----recheck battery situation-----\n\r");
		vol_measure();//recheck voltage
		delay_ms(1000);
		for(i_battery=1;i_battery=16;i_battery++)
		 {
			 if(vol[i_battery]>=battery_whole_max)
				 break;
		 }
		/*
		if(vol[1]>battery_whole_max||vol2>battery_whole_max||vol3>battery_whole_max||vol4>battery_whole_max||vol5>battery_whole_max||vol6>battery_whole_max||vol7>battery_whole_max||vol8>battery_whole_max||vol9>battery_whole_max||vol10>battery_whole_max||vol11>battery_whole_max||vol12>battery_whole_max||vol13>battery_whole_max||vol14>battery_whole_max||vol14>battery_whole_max||vol15>battery_whole_max||vol16>battery_whole_max)
			break;
		*/
	}
 /////////小電流並聯充電//////////////
 
 
   while(vol[1]<=battery_individual_max)
    {
		printf("charing 1st battery:\n\r");

		output_low(mux_b_sel[3]);output_low(mux_b_sel[2]);output_low(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:0000
		output_low(mux_a_sel[3]);output_low(mux_a_sel[2]);output_low(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:0000
		vol_measure();
		if(vol[1]>battery_individual_max)
            break;
    }
	
   while(vol[2]<=battery_individual_max)
    {
		printf("charing 2st battery:\n\r");

		output_high(mux_b_sel[3]);output_low(mux_b_sel[2]);output_low(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:1000
		output_high(mux_a_sel[3]);output_low(mux_a_sel[2]);output_low(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:1000
		vol_measure();
		if(vol[2]>battery_individual_max)
            break;
    }

	while(vol[3]<=battery_individual_max)
    {
		printf("charing 3st battery:\n\r");

		output_low(mux_b_sel[3]);output_high(mux_b_sel[2]);output_low(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:0100
		output_low(mux_a_sel[3]);output_high(mux_a_sel[2]);output_low(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:0100
		vol_measure();
		if(vol[3]>battery_individual_max)
            break;
    }
 
   while(vol[4]<=battery_individual_max)
    {
		printf("charing 1st battery:\n\r");

		output_high(mux_b_sel[3]);output_high(mux_b_sel[2]);output_low(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:1100
		output_high(mux_a_sel[3]);output_high(mux_a_sel[2]);output_low(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:1100
		vol_measure();
		if(vol[4]>battery_individual_max)
            break;
    }

   while(vol[5]<=battery_individual_max)
    {
		printf("charing 5st battery:\n\r");

		output_low(mux_b_sel[3]);output_low(mux_b_sel[2]);output_high(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:0010
		output_low(mux_a_sel[3]);output_low(mux_a_sel[2]);output_high(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:0010
		vol_measure();
		if(vol[5]>battery_individual_max)
            break;
    }
   
   while(vol[6]<=battery_individual_max)
    {
		printf("charing 6st battery:\n\r");

		output_high(mux_b_sel[3]);output_low(mux_b_sel[2]);output_high(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:1010
		output_high(mux_a_sel[3]);output_low(mux_a_sel[2]);output_high(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:1010
		vol_measure();
		if(vol[6]>battery_individual_max)
            break;
    }
   
   while(vol[7]<=battery_individual_max)
    {
		printf("charing 7st battery:\n\r");

		output_low(mux_b_sel[3]);output_high(mux_b_sel[2]);output_high(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:0110
		output_low(mux_a_sel[3]);output_high(mux_a_sel[2]);output_high(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:0110
		vol_measure();
		if(vol[7]>battery_individual_max)
            break;
    }
   
   while(vol[8]<=battery_individual_max)
    {
		printf("charing 7st battery:\n\r");

		output_high(mux_b_sel[3]);output_high(mux_b_sel[2]);output_high(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:1110
		output_high(mux_a_sel[3]);output_high(mux_a_sel[2]);output_high(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:1110
		vol_measure();
		if(vol[8]>battery_individual_max)
            break;
    }
   
   while(vol[9]<=battery_individual_max)
    {
		printf("charing 1st battery:\n\r");

		output_low(mux_b_sel[3]);output_low(mux_b_sel[2]);output_low(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:0001
		output_low(mux_a_sel[3]);output_low(mux_a_sel[2]);output_low(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:0001
		vol_measure();
		if(vol[9]>battery_individual_max)
            break;
    }
   
   while(vol[10]<=battery_individual_max)
    {
		printf("charing 10st battery:\n\r");

		output_high(mux_b_sel[3]);output_low(mux_b_sel[2]);output_low(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:1001
		output_high(mux_a_sel[3]);output_low(mux_a_sel[2]);output_low(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:1001
		vol_measure();
		if(vol[10]>battery_individual_max)
            break;
    }
   
   while(vol[11]<=battery_individual_max)
    {
		printf("charing 1st battery:\n\r");

		output_low(mux_b_sel[3]);output_high(mux_b_sel[2]);output_low(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:0101
		output_low(mux_a_sel[3]);output_high(mux_a_sel[2]);output_low(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:0101
		vol_measure();
		if(vol[11]>battery_individual_max)
            break;
    }
   
   while(vol[12]<=battery_individual_max)
    {
		printf("charing 12st battery:\n\r");

		output_high(mux_b_sel[3]);output_high(mux_b_sel[2]);output_low(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:1101
		output_high(mux_a_sel[3]);output_high(mux_a_sel[2]);output_low(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:1101
		vol_measure();
		if(vol[12]>battery_individual_max)
            break;
    }
   
   while(vol[13]<=battery_individual_max)
    {
		printf("charing 13st battery:\n\r");

		output_low(mux_b_sel[3]);output_low(mux_b_sel[2]);output_high(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:0011
		output_low(mux_a_sel[3]);output_low(mux_a_sel[2]);output_high(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:0011
		vol_measure();
		if(vol[13]>battery_individual_max)
            break;
    }
   
    while(vol[14]<=battery_individual_max)
    {
		printf("charing 14st battery:\n\r");

		output_high(mux_b_sel[3]);output_low(mux_b_sel[2]);output_high(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:1011
		output_high(mux_a_sel[3]);output_low(mux_a_sel[2]);output_high(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:1011
		vol_measure();
		if(vol[14]>battery_individual_max)
            break;
    }
   
   while(vol[15]<=battery_individual_max)
    {
		printf("charing 15st battery:\n\r");

		output_low(mux_b_sel[3]);output_high(mux_b_sel[2]);output_high(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:0111
		output_low(mux_a_sel[3]);output_high(mux_a_sel[2]);output_high(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:0111
		vol_measure();
		if(vol[15]>battery_individual_max)
            break;
    }
   
   while(vol[16]<=battery_individual_max)
    {
		printf("charing 16st battery:\n\r");

		output_high(mux_b_sel[3]);output_high(mux_b_sel[2]);output_high(mux_b_sel[1]);output_high(mux_b_sel[0]);//muxB:1111
		output_high(mux_a_sel[3]);output_high(mux_a_sel[2]);output_high(mux_a_sel[1]);output_high(mux_a_sel[0]);//muxA:1111
		vol_measure();
		if(vol[16]>battery_individual_max)
            break;
    }
   return;
}

#endif

