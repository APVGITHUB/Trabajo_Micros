#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "display.h"

void setupDisplay() {
	
	setBit(SELECTOR_SETUP, SEL0);	// Establece SEL0 como salida
	setBit(SELECTOR_SETUP, SEL1);	// Establece SEL1 como salida
	SEGMENTOS_SETUP = 0b01111111;	// Establece segmentos como salida
	setBit(TIMSK1, OCIE1C);
	OCR1C = REFRESCO; // FRECUENCIA DE REFRESCO DEL SELECTOR 
	
}

uint8_t display = 0;
uint16_t num = 0;
extern uint16_t deposito;


void select () {
	uint8_t b0;
	uint8_t b1;
	// bit 0 de display
	b0 = display%2;
	if(b0)
	setBit(SELECTOR, SEL0);
	else
	clrBit(SELECTOR, SEL0);
	
	// bit 1 de display
	b1 = display/2;
	b1 %= 2
	;
	if(b1)
	setBit(SELECTOR, SEL1);
	else
	clrBit(SELECTOR, SEL1);
}

void segment () {
	switch(num) {
		
		case 0:
		SEGMENTOS = 0b00111111;
		break;
		case 1:
		SEGMENTOS = 0b00000110;
		break;
		case 2:
		SEGMENTOS = 0b01011011;
		break;
		case 3:
		SEGMENTOS = 0b01001111;
		break;
		case 4:
		SEGMENTOS = 0b01100110;
		break;
		case 5:
		SEGMENTOS = 0b01101101;
		break;
		case 6:
		SEGMENTOS = 0b01111101;
		break;
		case 7:
		SEGMENTOS = 0b00000111;
		break;
		case 8:
		SEGMENTOS = 0b01111111;
		break;
		case 9:
		SEGMENTOS = 0b01101111;
		break;
		default:
		break;			
	}
}
	

ISR(TIMER1_COMPC_vect) {
	OCR1C += REFRESCO;
	select();	
	
	// coger cifra correspondiente al selector en este instante
	num = deposito;
	for(volatile int k=0; k<display; k++) {
		num /= 10;
	}
	num %= 10;
	segment();	
	
	// cambiar el selector
	if (display < 3)
		display++;
	else
		display = 0;
		
}

