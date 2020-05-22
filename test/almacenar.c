/*
 * almacenar.c
 *
 * Created: 18/05/2020 0:00:05
 *  Author: Guille
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "almacenar.h"

void setupCompuerta() {
	
	setBit(COMPUERTA_SETUP, E1);	//se establece como salida
	clrBit(COMPUERTA, E1);			//inicio cerrada

}

uint16_t contCompuerta = 0;


void abrirCompuerta() {
	setBit(COMPUERTA, E1);
}

void cerrarCompuerta() {
	clrBit(COMPUERTA, E1);
}

//añadir en el archivo de IDENTIFICARMONEDA
/*
void actualizar (uint8_t moneda) {
	deposito += moneda;
}
*/


// DEBEN INCLUIRSE ESTAS DOS FUNCIONES A CONTINUACIÓN DE identificaMoneda()
void almacenar(int8_t estado) {	// RECIBE EL ESTADO DE LA MÁQUINA
	if(estado)
		abrirCompuerta();
		OCR1A = TCNT1 + 1000;
		setBit(TIMSK1, OCIE1A);	//	desenmascarar interrupciones por OCR1A	
		contCompuerta = 0;	// reinicia el tiempo abierta la compuerta en caso de que entre otra moneda mientras la compuerta sigue abierta	
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

	
		
		 