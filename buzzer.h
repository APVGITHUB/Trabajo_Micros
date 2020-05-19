/*
 * buzzer.h
 *
 * Created: 18/05/2020 16:08:37
 *  Author: Guille
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_SETUP	DDRL
#define B1				4

#define SONIDO			300
#define SILENCIO		400

#define PERIODO			1000
#define DUTY_CYCLE		0.5		

void setupBuzzer();
void pitidos(uint8_t n);

#endif /* BUZZER_H_ */