#ifndef COIN_SIZE_H_
#define COIN_SIZE_H_

#define FILTRO		1   // NUMERO DE PERIODOS A FILTRAR

// INTERVALOS DE RATIO

#define MAX_RATIO_10	4.32
#define MIN_RATIO_10	3.82

#define MAX_RATIO_20	2.91
#define MIN_RATIO_20	2.78

#define MAX_RATIO_50	2.48
#define MIN_RATIO_50	2.40

#define MAX_RATIO_100	2.67
#define MIN_RATIO_100	2.56

// INTERVALOS DE FRECUENCIAS

#define MAX_FREQ_10		1600
#define MIN_FREQ_10		1400

#define MAX_FREQ_20		1075
#define MIN_FREQ_20		900

#define MAX_FREQ_50		420
#define MIN_FREQ_50		380

#define MAX_FREQ_100	550
#define MIN_FREQ_100	450

// ESTADOS POSIBLES EN LA MÁQUINA

#define VALIDA 1
#define NO_VALIDA -1
#define VACIO	0

// VALORES POSIBLES DE LAS MONEDAS

#define DIEZ		1
#define VEINTE		2
#define	CINCUENTA	5
#define EURO		10


void setupSensores();


#endif /* COIN_SIZE_H_ */
