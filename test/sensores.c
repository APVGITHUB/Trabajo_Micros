
#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "sensores.h"
#include "almacenar.h"



void setupOpticos(){
	
	clrBit(DDRD,DDD4);  //PIND4 INPUT
	clrBit(DDRE,DDE7); //PINE7 INPUT
	clrBit(DDRL,DDL0);	//PINL0 INPUT
	
	//TIMER1 CONF PARA S01
	clrBit(TCCR1B,ICES1); //INPUT CAPTURE ICP1 associated to PD4, capture when falling edge
	setBit(TIMSK1,ICIE1); //enable interrupt for TIMER1
	TIFR1 = (1<<ICF1); //clear possible flag
	setBit(TCCR1B,CS11); //prescalado 8
	
	
	//TIMER3 CONF PARA S02
	clrBit(TCCR3B,ICES3); //INPUT CAPTURE ICP3 associated to PE7, capture when falling edge
	setBit(TIMSK3,ICIE3);//enable interrupt
	TIFR3 = (1<<ICF3);  //clear possible flag
	setBit(TCCR3B,CS31);//prescalado 8
	
	
	//TIMER4 CONF PARA EM1
	setBit(TCCR4B,ICES4); //Input capture on RISING edge
	setBit(TIMSK4,ICIE4);	//enable interrupt
	TIFR4 = (1<<ICF4);	//clear possible flag
	setBit(TCCR4B,CS41); // timer 1 setup with a pre-scalar of 8

}


uint16_t t1fall, t1rise, t2fall, t2rise, t1, t2, t3;
uint16_t t_1 = 0;
uint16_t t_2 = 0;

float r = 0;
long f = 0;

long f_actual = 0;
uint8_t i = 0;


// EN EL main()
extern uint16_t deposito;
extern int8_t estado;




void calculateFrequency()
{
	float period;
	period= (t_2 - t_1);
	t_1 = t_2;
	f_actual = (8000000UL/(8*period));
}

void calculateRatio()
{
	r = (float)t2/(t1 - t3);
}

void sumarMoneda(uint8_t moneda)  {
	deposito += moneda;
}

void identificaMoneda () {
	if ((r > MIN_RATIO_10 && MAX_RATIO_10 > r) && (f > MIN_FREQ_10 && MAX_FREQ_10 > f))	//validación monedaa de 10 cent
	{
		estado = VALIDA;
		sumarMoneda(DIEZ);
	}
	else if ((r > MIN_RATIO_20 && MAX_RATIO_20 > r) && (f > MIN_FREQ_20 && MAX_FREQ_20 > f)) // validación moneda de 20 cent
	{
		estado = VALIDA;
		sumarMoneda(VEINTE);
	}
	else if ((r > MIN_RATIO_50 && MAX_RATIO_50 > r) && (f > MIN_FREQ_50 && MAX_FREQ_50 > f)) // validación moneda de 50 cent
	{
		estado = VALIDA;
		sumarMoneda(CINCUENTA);
	}
	else if ((r > MIN_RATIO_100 && MAX_RATIO_100 > r) && (f > MIN_FREQ_100 && MAX_FREQ_100 > f)) // validación moneda de 100 cent
	{
		estado = VALIDA;
		sumarMoneda(EURO);
	}
	else
	{
		estado = NO_VALIDA;
	}
}


ISR(TIMER1_CAPT_vect){
	if (getBit(TCCR1B, ICES1)) //input capture by rising edge
	{
		clrBit(TCCR1B, ICES1);	//change to falling edge
		t1rise = ICR1;
		t1= t1rise - t1fall;
	}
	else { //input capture by falling edge
		setBit(TCCR1B, ICES1);	//change to rising edge
		t1fall = ICR1;
	}
}


ISR(TIMER3_CAPT_vect){
	if (getBit(TCCR3B, ICES3)) //input capture by rising edge
	{
		clrBit(TCCR3B, ICES3);	//change to falling edge
		t2rise = ICR3;
		t2= t2rise - t2fall;
		t3 = (t2fall - t1fall);
	}
	else { //input capture by falling edge
		setBit(TCCR3B, ICES3); //change to rising edge
		t2fall = ICR3;
	}
}


ISR(TIMER4_CAPT_vect){
	t_2= ICR4;
	calculateFrequency();
	
	// filtrar primeros periodos
	if (f_actual < 1800)
	{
		if (i < FILTRO)
		i++;
		else
		f = f_actual;
	}
	
	if((t2 != 0) && (f != 0))	//ha pasado por los sensores ópticos y por el electromagnético
	{
		calculateRatio();
		identificaMoneda();
		almacenar(estado);
		
		t2 = 0;
		f = 0;
		i = 0;
	}
}




