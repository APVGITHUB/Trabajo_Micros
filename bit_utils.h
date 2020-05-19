/*
 * bit_utils.h
 *
 * Created: 09/05/2020 19:51:01
 *  Author: Guille
 */ 


#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#define setBit(P, B)	(P |= (1 << B))
#define clrBit(P, B)	(P &= ~(1 << B))
#define toggleBit(P, B)	(P ^= (1 << B))
#define getBit(P, B)	(P & (1 << B))

#endif /* BIT_UTILS_H_ */