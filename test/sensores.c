
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include "sensores.h"
#include "bit_utils.h"




void setup_optics(){
	//cli();
	
	//TIMER1 CONF PARA S01
	clrBit(DDRD,DDD4);  //PIND4 INPUT
	setBit(TCCR1B,CS11); //prescalado 8
	clrBit(TCCR1B,ICES1); //INPUT CAPTURE ICP1 associated to PD4, capture when falling edge
	setBit(TIMSK1,ICIE1); //enable interrupt for TIMER1
	TIFR1 = (1<<ICF1); //clear possible flag
	
	//TIMER3 CONF PARA S02
	clrBit(DDRE,DDE7); //PINE7 INPUT
	setBit(TCCR3B,CS31);//prescalado 8
	clrBit(TCCR3B,ICES3); //INPUT CAPTURE ICP3 associated to PE7, capture when falling edge
	setBit(TIMSK3,ICIE3);//enable interrupt
	TIFR3 = (1<<ICF3);  //clear possible flag
	
	//TIMER4 CONF PARA EM1
	clrBit(DDRL,DDL0);
	setBit(TCCR4B,CS41); // timer 1 setup with a pre-scalar of 8
	setBit(TCCR4B,ICES4); //Input capture on rising edge
	setBit(TIMSK4,ICIE4);
	TIFR4 = (1<<ICF4);
}

long calculateFrequency()
{
	flag = 0;
	period= (t_2-t_1);
	t_1 = t_2;
	return (8000000UL/(8*period));
}


ISR(TIMER1_CAPT_vect){
	if (TCCR1B & (1<<ICES1)) //input capture by rising edge 
	{	
		TCCR1B &= ~(1<<ICES1); //change to falling edge
		t1rise = ICR1;
		cross_so1 = 1; //cross sensor S02
		//if(t1rise < t1fall)//si hay ovf
		//{
			//t1 = (65535 - t1fall) + t1rise;
		//} else {
			//t1= t1rise - t1fall;
		//}
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
		cross_so2 = 1; //cross sensor S02
		//if(t2rise < t2fall)//si hay ovf
		//{
			//t2 = (65535 - t2fall) + t2rise;
		//} else {
			//t2= t2rise - t2fall;
		//}	
		//if (t2fall < t1fall) //overflow
		//{
			//t3 = (65335 - t1fall) + t2fall;
		//} else {
			//t3 = (t2fall - t1fall); //se puede hacer en la funcion calcular 	
		//}
		
		//ratio = (float)(t2fall - t2rise)/((t1fall - t1rise) - t3);
	} else { //input capture by falling edge
		TCCR3B |= (1<<ICES3); //change to rising edge
		t2fall = ICR3;
		
	}
}


ISR(TIMER4_CAPT_vect){
	if (flag==0)
	{
		t_1=ICR4;
	}
	else if (flag==1)
	{
		t_2= ICR4;
		frequency = calculateFrequency();
	}
	else if (flag==2)
	{
		t_2= ICR4;
		frequency = calculateFrequency();
	}
	flag ++;
}




//int main(void)
//{
	//// initialize timer
	//timer1_init();
//
	//// setting PB0 as input for
	//DDRL &= ~(1<DDL0);
	////Enable PB0 pull up resistor
	////PORTB = (1<<PB0);
//
	////set PD7 as an output
	////DDRD |= (1<<DDD7);
	////turns off all ports in port D
	////PORTD = 0b00000000;
//
	//while (1)
	//{
		//
		//if (flag==2)
		//{
			//flag =1;
			//period= (t_2-t_1);
			//TIFR4=(1<<ICF4);
			//
			//frequency= (8000000UL/(8*period));
			//t_1 = t_2;
		//}
		//
	//}
//}

