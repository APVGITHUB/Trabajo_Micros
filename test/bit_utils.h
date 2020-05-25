#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_

#define setBit(P, B)	(P |= (1 << B))
#define clrBit(P, B)	(P &= ~(1 << B))
#define toggleBit(P, B)	(P ^= (1 << B))
#define getBit(P, B)	(P & (1 << B))

#endif /* BIT_UTILS_H_ */
