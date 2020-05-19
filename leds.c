/*
 * leds.c
 *
 * Created: 18/05/2020 0:46:17
 *  Author: Guille
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "leds.h"

void setupLeds() {
	
	setBit(LEDS_SETUP,VERDE);
	setBit(LEDS_SETUP,ROJO);
	clrBit(LEDS,VERDE);	
	clrBit(LEDS,ROJO);
	
	setBit(TIMSK1, OCIE1B);
	OCR1B = 1000;	// interrupcion cada ms
	
}

uint16_t contLed = 0;
uint16_t tiempoParpadeo = PARPADEO_OFF;
uint8_t entraMoneda = 0;


void ledVerde_ON (){
	setBit(LEDS, VERDE);
	OCR1B = TCNT1 + 1000;
	entraMoneda = 1;
	contLed = 0;
}

void ledRojo_ON (){
	setBit(LEDS, ROJO);
	OCR1B = TCNT1 + 1000;
	entraMoneda = 1;
	contLed = 0;	
}

void ledVerde_OFF (){
	clrBit(LEDS, VERDE);
	
}

void ledRojo_OFF (){
	clrBit(LEDS, ROJO);
}

ISR (TIMER1_COMPB_vect) {
	OCR1B += 1000;
	if(entraMoneda) {
		if (contLed < (TIEMPO_ON - 1))
			contLed++;
		else {
			ledVerde_OFF();
			ledRojo_OFF();
			contLed = 0;
			entraMoneda = 0;
		}
	}
	
	else
	{
		if (contLed < (tiempoParpadeo - 1))
			contLed++;
		else 
		{
			toggleBit(LEDS, ROJO);
			if(tiempoParpadeo == PARPADEO_ON)
			tiempoParpadeo = PARPADEO_OFF;
			else
			tiempoParpadeo = PARPADEO_ON;
			contLed = 0;
		}
	}

}

