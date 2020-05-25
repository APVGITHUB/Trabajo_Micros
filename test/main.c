#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "leds.h"
#include "display.h"
#include "buzzer.h"
#include "almacenar.h"
#include "sensores.h"
#include "api.h"

void setup(){
	cli();
	
	setupComm();
	setupLeds();
	setupDisplay();
	setupCompuerta();
	setupBuzzer();
	setupSensores();	
	
	sei();
}

int8_t estado = VACIO;	// estado de la moneda, se inicia en VACIO, no ha entrado moneda
uint16_t deposito = 0;	// indica el dinero almacenado tal como se mostrará en los display


int main(void)
{
	setup();
	deposito = atoi(receiveData());
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
		
		char total[4];
		sprintf(total,"%04d",deposito);
		int confirmar = 0;
		confirmar = atoi(total);
		sendMoney(total);
	}
}
