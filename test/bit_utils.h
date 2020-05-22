/*
 * IncFile1.h
 *
 * Created: 5/20/2020 11:34:04 AM
 *  Author: alexp
 */ 


#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#define setBit(P, B)	(P |= (1 << B))
#define clrBit(P, B)	(P &= ~(1 << B))
#define toggleBit(P, B)	(P ^= (1 << B))
#define getBit(P, B)	(P & (1 << B))

#endif /* BIT_UTILS_H_ */
