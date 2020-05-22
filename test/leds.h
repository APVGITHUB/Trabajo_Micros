/*
 * leds.h
 *
 * Created: 18/05/2020 0:47:51
 *  Author: Guille
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define LEDS_SETUP	DDRC
#define LEDS		PORTC
#define VERDE		0
#define ROJO		1

#define TIEMPO_ON	2000 // tiempo que permanece el led encendido en ms

#define PARPADEO_ON		500
#define PARPADEO_OFF	3000



void setupLeds();
void ledVerde_ON();
void ledVerde_OFF();
void ledRojo_ON();
void ledRojo_OFF();



#endif /* LEDS_H_ */