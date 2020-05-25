#ifndef DISPLAY_H_
#define DISPLAY_H_

#define SELECTOR_SETUP	DDRB
#define SELECTOR		PORTB
#define SEL0			0
#define SEL1			1

#define SEGMENTOS_SETUP	DDRC
#define SEGMENTOS		PORTC

#define REFRESCO		250		// periodo en ms de la frecuencia de refresco del selector:	  T = 250 ms => f = 4kHz	

void setupDisplay();



#endif /* DISPLAY_H_ */
