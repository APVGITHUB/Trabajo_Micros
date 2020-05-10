#include <avr/io.h>
#include <avr/interrupt.h>
#include "coin_size.h"

void setup_optics(){
	cli();
	
	//TIMER1 CONF PARA S01
	DDRD &= ~(1<<DDD4); //PIND4 INPUT
	//TCCR1A |= (1<<WGM12);//enable CTC mode
	//TCCR1B |= (1<<WGM13);//with ICR1 interrupt
	TCCR1B |= (1<<CS10); //prescalado 1
	TCCR1B &= ~(1<<ICES1); //INPUT CAPTURE ICP1 associated to PD4, capture when falling edge
	TIMSK1 |= (1<<ICIE1); //enable interrupt for TIMER1
	TIFR1 = (1<<ICF1); //clear possible flag
	
	//TIMER3 CONF PARA S02
	DDRE &= ~(1<<DDE7); //PINE7 INPUT
	TCCR3B |= (1<<CS10); //prescalado 1
	TCCR3B &= ~(1<<ICES3); //INPUT CAPTURE ICP3 associated to PE7, capture when falling edge
	TIMSK3 |= (1<<ICIE3); //enable interrupt
	TIFR3 = (1<<ICF3);  //clear possible flag
	
	sei();
}


volatile uint16_t t1fall, t1rise, t2fall, t2rise, t3;
float ratio;

int8_t coin_classifier(float ratio){
	if(ratio > EURO_MIN && ratio < EURO_MAX)
		return 1;
	
	else if(ratio > FIFTY_CENT_MIN && ratio < FIFTY_CENT_MAX)
		return 2;
	
	else if(ratio > TWENTY_CENT_MIN && ratio < TWENTY_CENT_MAX)
		return 3;
	
	else if(ratio > TEN_CENT_MIN && ratio < TEN_CENT_MAX)
		return 4;
	else{
		return -1; //ERROR
	}
}


ISR(TIMER1_CAPT_vect){
	if (TCCR1B & (1<<ICES1)) //input capture by rising edge 
	{	
		TCCR1B &= ~(1<<ICES1); //change to falling edge
		t1rise = ICR1;
	} else { //input capture by falling edge
		TCCR1B |= (1<<ICES1); //change to rising edge
		t1fall = ICR1;
	}
}


ISR(TIMER3_CAPT_vect){
	if (TCCR3B & (1<<ICES3)) //input capture by rising edge 
	{	
		TCCR3B &= ~(1<<ICES3); //change to falling edge
		t2rise = ICR3;
		ratio = (float)(t2fall - t2rise)/((t1fall - t1rise) - t3);
	} else { //input capture by falling edge
		TCCR3B |= (1<<ICES3); //change to rising edge
		t2fall = ICR3;
		t3 = (t2fall - t1fall);
	}
}
