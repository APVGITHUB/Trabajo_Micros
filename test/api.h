#ifndef API_H_
#define API_H_


#define BAUD 9600
#define F_CPU 8000000UL

void setupComm();
void sendMoney();
char * receiveData();

#endif /* API_H_ */
