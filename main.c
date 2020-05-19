/*
 * monedero.c
 *
 * Created: 09/05/2020 19:05:43
 * Author : Guille
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "bit_utils.h"
#include "leds.h"
#include "display.h"
#include "buzzer.h"
#include "almacenar.h"
#include "identificarMoneda.h"

void setup(){
	cli();
	
	setupLeds();
	setupDisplay();
	setupCompuerta();
	setupBuzzer();
	//setupSensores();		activar el preescalado al final
	
	sei();
}

int8_t estado = VACIO;
uint16_t deposito = 0;

int main(void)
{
    setup();
    while (1) 
    {
		switch(estado) {
			case VALIDA:
				ledVerde_ON();
				pitidos(1);
				estado = VACIO;
				break;
				
			case NO_VALIDA:
				ledRojo_ON();
				pitidos(3);
				estado = VACIO;
				break;	
						
			default:
				break;
		}
    }
}
