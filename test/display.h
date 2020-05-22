#ifndef DISPLAY_H_
#define DISPLAY_H_

#define SELECTOR_SETUP	DDRG
#define SELECTOR		PORTG
#define SEL0			0
#define SEL1			1

#define SEGMENTOS_SETUP	DDRA
#define SEGMENTOS		PORTA

#define REFRESCO		250		// periodo en ms de la frecuencia de refresco del selector:	f = 4kHz	=>	T = 250 ms

void setupDisplay();



#endif /* DISPLAY_H_ */