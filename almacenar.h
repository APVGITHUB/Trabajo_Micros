/*
 * almacenar.h
 *
 * Created: 17/05/2020 23:59:52
 *  Author: Guille
 */ 


#ifndef ALMACENAR_H_
#define ALMACENAR_H_

#define COMPUERTA_SETUP	DDRB
#define COMPUERTA		PORTB		
#define E1				4

#define TIEMPO_ABIERTA 500	// tiempo que dura abierta la compuerta en ms

void setupCompuerta();
void almacenar(int8_t estado);


#endif /* ALMACENAR_H_ */