#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "leds.h"

void setupLeds() {
	
	setBit(LEDS_SETUP,VERDE);	// establece led verde como salida
	setBit(LEDS_SETUP,ROJO);	// establece led rojo como salida
	clrBit(LEDS,VERDE);		// inicio led verde apagado
	clrBit(LEDS,ROJO);		// inicio led rojo apagado
		
	setBit(TIMSK1, OCIE1B);
	OCR1B = 1000;	// interrupcion cada ms
	
}

uint16_t contLed = 0;
uint16_t tiempoParpadeo = PARPADEO_OFF;
uint8_t entraMoneda = 0;	// bandera que indica cuando ha entrado una moneda


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
			tiempoParpadeo = PARPADEO_OFF;
			entraMoneda = 0;
		}
	}
	
	else
	{
		if (contLed < (tiempoParpadeo - 1))
			contLed++;
		else 
		{
			if(getBit(LEDS, ROJO))
			{
				clrBit(LEDS, ROJO);
				tiempoParpadeo = PARPADEO_OFF;
			}
			else 
			{
				setBit(LEDS, ROJO);
				tiempoParpadeo = PARPADEO_ON;
			}
			
			contLed = 0;
		}
	}

}

