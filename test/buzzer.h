/*
 * IncFile1.h
 *
 * Created: 5/20/2020 11:36:23 AM
 *  Author: alexp
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