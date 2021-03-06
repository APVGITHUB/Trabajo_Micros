/*
 * identificaMoneda.h
 *
 * Created: 17/05/2020 21:37:42
 *  Author: Guille
 */ 


#ifndef IDENTIFICAMONEDA_H_
#define IDENTIFICAMONEDA_H_ 

// INTERVALOS DE RATIO

#define max_ratio_10	4310
#define min_ratio_10	3810

#define max_ratio_20	2900
#define min_ratio_20	2770

#define max_ratio_50	2640
#define min_ratio_50	2550

#define max_ratio_100	2470
#define min_ratio_100	2390

// INTERVALOS DE FRECUENCIAS

#define max_freq_10		1598
#define min_freq_10		1404

#define max_freq_20		1070
#define min_freq_20		901

#define max_freq_50		546
#define min_freq_50		460

#define max_freq_100	418
#define min_freq_100	385

// ESTADOS POSIBLES EN LA M�QUINA

#define VALIDA 1
#define NO_VALIDA -1
#define VACIO	0

// VALORES POSIBLES DE LAS MONEDAS

#define DIEZ		1
#define VEINTE		2
#define	CINCUENTA	5	
#define EURO		10

void identificaMoneda();

#endif /* IDENTIFICAMONEDA_H_ */