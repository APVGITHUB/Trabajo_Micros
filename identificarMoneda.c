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



// SE INCLUYE AL FINAL DE LA INTERRUPCIÓN DE SENSOR EM1 SIEMPRE QUE t1 Y t2 SEAN DISTINTAS DE CERO
	// PRIMERO SE CALCULAN t1, t2, t3 
	// DESPUÉS SE LLAMA A LA FUNCIÓN identificaMoneda()

// EN EL main()
extern uint16_t deposito;
extern int8_t estado;

//EN sensores.c
extern uint16_t t1;
extern uint16_t t2;
extern uint16_t t3;
extern uint16_t f;


void sumarMoneda(uint8_t moneda)  {
	deposito += moneda;
}

uint16_t calculateRatio() {
	float ratio;
	ratio = (float)(t2/(t1 - t3));
	return ratio;
}

void identificaMoneda () {	
	uint16_t r;
	r = calculateRatio();
	//r = t2 / (t1 - t3);
	//r = calculateRatio();
		
	// validación moneda de 10 cent
	if ((r > min_ratio_10 && max_ratio_10 > r) && (f > min_freq_10 && max_freq_10 > f))
	{
		estado = VALIDA;
		sumarMoneda(DIEZ);
	}
	else
	{
		// validación moneda de 20 cent
		if ((r > min_ratio_20 && max_ratio_20 > r) && (f > min_freq_20 && max_freq_20 > f))
		{
			estado = VALIDA;
			sumarMoneda(VEINTE);
		}
		else
		{
			// validación moneda de 50 cent
			if ((r > min_ratio_50 && max_ratio_50 > r) && (f > min_freq_50 && max_freq_50 > f))
			{
				estado = VALIDA;
				sumarMoneda(CINCUENTA);
			}
			else
			{
				// validación moneda de 100 cent
				if ((r > min_ratio_100 && max_ratio_100 > r) && (f > min_freq_100 && max_freq_100 > f))
				{
					estado = VALIDA;
					sumarMoneda(EURO);
				}
				else
				{
					estado = NO_VALIDA;
				}
			}
		}
	}
}
