#include <18F4520.h>
#device ADC=16

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES WDT128                	//Watch Dog Timer uses 1:128 Postscale
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST               	//Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

#use pwm(CCP1,TIMER=2,FREQUENCY=500,DUTY=30)


//////define pin///////
/*
A
AN0:V測量的讀入腳
AN1:I測量的讀入腳
AN2:T測量的讀入腳??????temp_measure未打
A3:開關A的mux選擇腳位0
A4:開關A的mux選擇腳位1
A5:開關A的mux選擇腳位2
B
B0:Charge Interrupt(訊號)
B1:Protect interrupt(訊號)
D
D0:開關B的mux選擇腳位0
D1:開關B的mux選擇腳位1
D2:開關B的mux選擇腳位2
D3:開關B的mux選擇腳位3
D4:開關A的mux選擇腳位3
*/
//for balcance()


#define mux_b_sel[0]     PIN_D0
#define mux_b_sel[1]     PIN_D1
#define mux_b_sel[2]     PIN_D2
#define mux_b_sel[3]     PIN_D3

#define mux_a_sel[0]     PIN_A3
#define mux_a_sel[1]     PIN_A4
#define mux_a_sel[2]     PIN_A5
#define mux_a_sel[3]     PIN_C1

#define total_switch	 PIN_D4;
//for main.c
#define charge_signal PIN_B0
#define protect_signal PIN_B1

#define battery_whole_max		3.6
#define battery_individual_max	3.8