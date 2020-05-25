#ifndef LEDS_H_
#define LEDS_H_

#define LEDS_SETUP	DDRA
#define LEDS		PORTA
#define VERDE		0
#define ROJO		1

#define TIEMPO_ON	2000 // tiempo que permanece el led encendido cuando entra moneda en ms

#define PARPADEO_ON		500   // tiempo de encendido en el parpadeo en ms
#define PARPADEO_OFF	3000    // tiempo de apagado en el parpadeo en ms



void setupLeds();
void ledVerde_ON();
void ledVerde_OFF();
void ledRojo_ON();
void ledRojo_OFF();



#endif /* LEDS_H_ */
