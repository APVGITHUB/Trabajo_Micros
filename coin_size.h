/*
 * coin_size.h
 *
 * Created: 5/8/2020 10:55:38 AM
 *  Author: alexp
 */ 


#ifndef COIN_SIZE_H_
#define COIN_SIZE_H_

//Coin ratio tb/ta range

#define EURO_MIN 1.0
#define EURO_MAX 1.1

#define FIFTY_CENT_MIN 1.15
#define FIFTY_CENT_MAX 1.25

#define TWENTY_CENT_MIN 0.85
#define TWENTY_CENT_MAX 0.95

#define TEN_CENT_MIN 0.65
#define TEN_CENT_MAX 0.75

void setup_optics();
int8_t coin_classifier(float ratio);
ISR(TIMER1_CAPT_vect);

#endif /* COIN_SIZE_H_ */