#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "almacenar.h"

void setupCompuerta() {
	
	setBit(COMPUERTA_SETUP, E1);	//se establece la compuerta como salida
	clrBit(COMPUERTA, E1);			//inicio cerrada

}

uint16_t contCompuerta = 0;


void abrirCompuerta() {
	setBit(COMPUERTA, E1);
}

void cerrarCompuerta() {
	clrBit(COMPUERTA, E1);
}

//ABRIR LA COMPUERTA SI LA MONEDA ES VÁLIDA
void almacenar(int8_t estado) {	
	if(estado)
		abrirCompuerta();
		OCR1A = TCNT1 + 1000;	//	programar interrupcion 1ms después de abrir compuerta
		setBit(TIMSK1, OCIE1A);	//	desenmascarar interrupciones por OCR1A	
		contCompuerta = 0;		
}


ISR (TIMER1_COMPA_vect) {
	OCR1A += 1000;
	if (contCompuerta < (TIEMPO_ABIERTA - 1))
		contCompuerta++;
	else {
		cerrarCompuerta();
		clrBit (TIMSK1, OCIE1A);	// enmascarar interrupciones por OCR1A
	}
}

	
		
		 
