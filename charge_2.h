#ifndef HEADER_FILE_CHARGE
#define HEADER_FILE_CHARGE

#include <stdio.h>

void set_mux_AB(int,int,int,int);

void charge()
{
	struct mux
	{
	  int mux_3;
	  int mux_2;
	  int mux_1;
	  int mux_0;
	};
	typedef struct mux mux;

	mux muxlist[] =
	  {
		0,0,0,0,//battery 1
		1,0,0,0,//battery 2
		0,1,0,0,//battery 3
		1,1,0,0,//battery 4
		0,0,1,0,//battery 5
		1,0,1,0,//battery 6
		0,1,1,0,//battery 7
		1,1,1,0,//battery 8
		0,0,0,1,//battery 9
		1,0,0,1,//battery 10
		0,1,0,1,//battery 11
		1,1,0,1,//battery 12
		0,0,1,1,//battery 13
		1,0,1,1,//battery 14
		0,1,1,1,//battery 15
		1,1,1,1,//battery 16
	  };

	mux *muxPtr;

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
	
	muxPtr = muxlist;

	for(i=1;i==16;i++,muxPtr++)
	{
	   while(vol[i]<=battery_individual_max)
		{
			printf("charing %ist battery:\n\r",i);
			set_mux_AB(muxPtr->mux_3,muxPtr->mux_2,muxPtr->mux_1,muxPtr->mux_0);
			/*
			output_low(mux_b_sel[3]);output_low(mux_b_sel[2]);output_low(mux_b_sel[1]);output_low(mux_b_sel[0]);//muxB:0000
			output_low(mux_a_sel[3]);output_low(mux_a_sel[2]);output_low(mux_a_sel[1]);output_low(mux_a_sel[0]);//muxA:0000
			*/
			vol_measure();
			if(vol[i]>battery_individual_max)
				break;
		}
	}
	return;
 }

void set_mux_AB(bit_3,bit_2,bit_1,bit_0)
{
	if(bit_3)
	{
		output_high(mux_b_sel[3]);
		output_high(mux_a_sel[3]);
	}
	else 
	{
		output_low(mux_b_sel[3]);
		output_low(mux_a_sel[3]);
	}
////////////////////////////////
	if(bit_2)
	{
		output_high(mux_b_sel[2]);
		output_high(mux_a_sel[2]);
	}
	else 
	{
		output_low(mux_b_sel[2]);
		output_low(mux_a_sel[2]);
	}
////////////////////////////////
	if(bit_1)
	{
		output_high(mux_b_sel[1]);
		output_high(mux_a_sel[1]);
	}
	else 
	{
		output_low(mux_b_sel[1]);
		output_low(mux_a_sel[1]);
	}	
/////////////////////////////////
	if(bit_0)
	{
		output_high(mux_b_sel[0]);
		output_high(mux_a_sel[0]);
	}
	else 
	{
		output_low(mux_b_sel[0]);
		output_low(mux_a_sel[0]);
	}
	
	
}

#endif



