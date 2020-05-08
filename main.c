/*
 * monedero.c
 *
 * Created: 5/6/2020 1:20:57 PM
 * Author : alexp
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "coin_size.h"
//#define EURO_MIN 1.0
//#define EURO_MAX 1.1
//
//#define FIFTY_CENT_MIN 1.15
//#define FIFTY_CENT_MAX 1.25
//
//#define TWENTY_CENT_MIN 0.85
//#define TWENTY_CENT_MAX 0.95
//
//#define TEN_CENT_MIN 0.65
//#define TEN_CENT_MAX 0.75
//
//void setup_optics(){
	//cli();
	//
	////TIMER1 CONF PARA S01
	//DDRD &= ~(1<<DDD4); //PIND4 INPUT
	////TCCR1A |= (1<<WGM12);//enable CTC mode
	////TCCR1B |= (1<<WGM13);//with ICR1 interrupt
	//TCCR1B &= ~(1<<ICES1); //INPUT CAPTURE ICP1 associated to PD4, capture when falling edge
	//TIMSK1 |= (1<<ICIE1); //enable interrupt for TIMER1
	//TIFR1 = (1<<ICF1); //clear possible flag
	//
	////TIMER3 CONF PARA S02
	//DDRE &= ~(1<<DDE7); //PINE7 INPUT
	////TCCR3B &= ~(1<<ICES3); //INPUT CAPTURE ICP3 associated to PE7, capture when falling edge
	//TIMSK3 &= ~(1<<ICIE3); //disable interrupt
	//TIFR3 = (1<<ICF3);  //clear possible flag
	//
	//sei();
//}
//
//
//volatile uint8_t tA = 0 , tB = 0;
//float ratio;
//
//int8_t coin_classifier(float ratio){
	//if(ratio > EURO_MIN && ratio < EURO_MAX)
	//return 1;
	//
	//else if(ratio > FIFTY_CENT_MIN && ratio < FIFTY_CENT_MAX)
	//return 2;
	//
	//else if(ratio > TWENTY_CENT_MIN && ratio < TWENTY_CENT_MAX)
	//return 3;
	//
	//else if(ratio > TEN_CENT_MIN && ratio < TEN_CENT_MAX)
	//return 4;
	//else{
		//return -1; //ERROR
	//}
//}




int main(void)
{
	setup_optics();
    while (1) 
    {
    }
}

//ISR(TIMER1_CAPT_vect){
	//tA = ICR1;
	//while(PINE &= 0X80){}
	//tB = ICR3;
	//ratio = (float)tB/tA;
	//coin_classifier(ratio);
//}
