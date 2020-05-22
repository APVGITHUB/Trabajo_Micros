/*
 * identificarMoneda.c
 *
 * Created: 17/05/2020 21:36:34
 *  Author: Guille
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "identificarMoneda.h"
#include "sensores.h"


 //SE INCLUYE AL FINAL DE LA INTERRUPCIÓN DE SENSOR EM1 SIEMPRE QUE t1 Y t2 SEAN DISTINTAS DE CERO
////	 PRIMERO SE CALCULAN t1, t2, t3 
//	 DESPUÉS SE LLAMA A LA FUNCIÓN identificaMoneda()

 //EN EL main()
extern uint16_t deposito;
extern int8_t estado;

//EN sensores.c
//extern uint16_t t1;
//extern uint16_t t2;
//extern uint16_t t3;
//extern uint16_t f;


void sumarMoneda(uint8_t moneda)  {
	deposito += moneda;
}

float calculateRatio() {
	t1= t1rise - t1fall;
	t2= t2rise - t2fall;
	t3 = (t2fall - t1fall);
	
	return (float)t2/(t1 - t3);
}


void identificaMoneda () {
	cross_so1 = 0;
	cross_so2 = 0;	
	float r;
	long f;
	r = calculateRatio();
	f = frequency;	
	// validación moneda de 10 cent
	if ((r > min_ratio_10 && max_ratio_10 > r) && (f > min_freq_10 && max_freq_10 > f))
	{
		estado = VALIDA;
		sumarMoneda(DIEZ);
	}
	else if ((r > min_ratio_20 && max_ratio_20 > r) && (f > min_freq_20 && max_freq_20 > f)) // validación moneda de 20 cent
		{
			estado = VALIDA;
			sumarMoneda(VEINTE);
		}
	else if ((r > min_ratio_50 && max_ratio_50 > r) && (f > min_freq_50 && max_freq_50 > f)) // validación moneda de 50 cent
		{
			estado = VALIDA;
			sumarMoneda(CINCUENTA);
		}
	else if ((r > min_ratio_100 && max_ratio_100 > r) && (f > min_freq_100 && max_freq_100 > f)) // validación moneda de 100 cent
		{
			estado = VALIDA;
			sumarMoneda(EURO);
		}
	else
		{
			estado = NO_VALIDA;
		}
}

