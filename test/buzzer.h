#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_SETUP	DDRL
#define B1				4

#define SONIDO			300   // tiempo sonando en ms
#define SILENCIO		400   // tiempo en silencio en ms

#define PERIODO			1000    // periodo del buzzer en ms
#define DUTY_CYCLE		0.5		

void setupBuzzer();
void pitidos(uint8_t n);

#endif /* BUZZER_H_ */
