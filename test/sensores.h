/*
 * coin_size.h
 *
 * Created: 5/8/2020 10:55:38 AM
 *  Author: alexp
 */ 


#ifndef COIN_SIZE_H_
#define COIN_SIZE_H_

#define FILTRO		1

// INTERVALOS DE RATIO

#define MAX_RATIO_10	4.31
#define MIN_RATIO_10	3.81

#define MAX_RATIO_20	2.90
#define MIN_RATIO_20	2.77

#define MAX_RATIO_50	2.64
#define MIN_RATIO_50	2.55

#define MAX_RATIO_100	2.47
#define MIN_RATIO_100	2.39

// INTERVALOS DE FRECUENCIAS

#define MAX_FREQ_10		1598
#define MIN_FREQ_10		1404

#define MAX_FREQ_20		1070
#define MIN_FREQ_20		901

#define MAX_FREQ_50		546
#define MIN_FREQ_50		460

#define MAX_FREQ_100	418
#define MIN_FREQ_100	385

// ESTADOS POSIBLES EN LA MÁQUINA

#define VALIDA 1
#define NO_VALIDA -1
#define VACIO	0

// VALORES POSIBLES DE LAS MONEDAS

#define DIEZ		1
#define VEINTE		2
#define	CINCUENTA	5
#define EURO		10


void setupOpticos();


#endif /* COIN_SIZE_H_ */