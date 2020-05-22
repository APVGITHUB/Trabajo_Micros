/*
 * coin_size.h
 *
 * Created: 5/8/2020 10:55:38 AM
 *  Author: alexp
 */ 


#ifndef COIN_SIZE_H_
#define COIN_SIZE_H_


#define EURO_MIN 1.0
#define EURO_MAX 1.1

#define FIFTY_CENT_MIN 1.15
#define FIFTY_CENT_MAX 1.25

#define TWENTY_CENT_MIN 0.85
#define TWENTY_CENT_MAX 0.95

#define TEN_CENT_MIN 0.65
#define TEN_CENT_MAX 0.75

void setup_optics();

volatile uint16_t t1fall, t1rise, t2fall, t2rise, t1, t2, t3;
volatile uint16_t t_1;
volatile uint16_t t_2;
volatile float period; 
volatile long frequency;
volatile uint8_t cross_so1, cross_so2;
//capture Flag
volatile uint8_t flag;
#endif /* COIN_SIZE_H_ */