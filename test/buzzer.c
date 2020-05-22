/*
 * buzzer.c
 *
 * Created: 18/05/2020 14:27:41
 *  Author: Guille
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "bit_utils.h"
#include "buzzer.h"

 void setupBuzzer () {
	 
	 // ESTABLECER BUZZER COMO SALIDA
	 setBit(BUZZER_SETUP, B1);
	 
	//UTILIZAR TIMER5 16bits MODO FAST PWM POR OCRA
	 setBit(TCCR5B, WGM53);
	 setBit(TCCR5B, WGM52);
	 setBit(TCCR5A, WGM51);
	 setBit(TCCR5A, WGM50);  
	 
	 OCR5A = (PERIODO - 1);				// periodo del PWM
	 OCR5B = DUTY_CYCLE*(PERIODO - 1);
	 setBit(TCCR5B, CS51);		// preescalado de 8
	 
 }
 
 
 uint8_t j = 0;
 uint8_t rep = 0;	//numero de repeticiones del pitido
 uint16_t contPitido = 0;
 uint16_t tiempoBuzzer = SILENCIO;
 
 
 void pitidos(uint8_t n) {
	// Set en BOTTOM // Clear en OCRB (duty cycle PWM)
	setBit(TCCR5A, COM5B1);	
	tiempoBuzzer = SONIDO;
	rep = n;
	setBit(TIMSK5, OCIE5A);	// activar interrupcion por OCRA 
 }
 
 //INTERRUPCION CADA ms
 ISR (TIMER5_COMPA_vect) {
	 if (j < rep) 
	 {			
		if (contPitido < tiempoBuzzer)
		{
			contPitido++;
		}
		else 
		{
			if(getBit(TCCR5A, COM5B1)) //SI ESTÁ SONANDO
			{
				clrBit(TCCR5A, COM5B1);	// silencio
				contPitido = 0;
				tiempoBuzzer = SILENCIO;
				j++;
			}
			else  //SI ESTÁ EN SILENCIO
			{
				setBit(TCCR5A, COM5B1);	//sonido
				contPitido = 0;
				tiempoBuzzer = SONIDO;		
			}	
		}
	}
	else
	{
		clrBit(TIMSK5, OCIE5A);	// desactivar interrupcion por OCRA 
	}		
 }