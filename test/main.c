/*
 * monedero.c
 *
 * Created: 5/6/2020 1:20:57 PM
 * Author : alexp
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>

#include "bit_utils.h"
#include "leds.h"
#include "display.h"
#include "buzzer.h"
#include "almacenar.h"
#include "identificarMoneda.h"
#include "sensores.h"
void setup(){
	cli();
	
	setupLeds();
	setupDisplay();
	setupCompuerta();
	setupBuzzer();
	setup_optics();		//activar el preescalado al final
	
	sei();
}

int8_t estado = VACIO;
uint16_t deposito = 0;

int main(void)
{
    setup();
    while (1) 
    {
		while(frequency > 1800)
		{
			//LED ROJO PARPADEA CADA 3 SEG
		}
 		if ((cross_so1 == 1) && (cross_so2 == 1) && (frequency < 1800))
		{	
			flag ++; //flag = 2;
			while (flag == 2)
			{
					
			}
			identificaMoneda();
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
}