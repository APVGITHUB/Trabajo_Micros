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

#define max_ratio_10	4.31
#define min_ratio_10	3.81

#define max_ratio_20	2.90
#define min_ratio_20	2.77

#define max_ratio_50	2.64
#define min_ratio_50	2.55

#define max_ratio_100	2.47
#define min_ratio_100	2.39

// INTERVALOS DE FRECUENCIAS

#define max_freq_10		1598
#define min_freq_10		1404

#define max_freq_20		1070
#define min_freq_20		901

#define max_freq_50		546
#define min_freq_50		460

#define max_freq_100	418
#define min_freq_100	385

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