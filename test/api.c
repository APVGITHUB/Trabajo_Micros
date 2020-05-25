#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bit_utils.h"
#include "api.h"


// BLOQUEO SOFTWARE
void delay(int ms){
	for(int p=0; p<ms; p++){
		for(volatile int q= 0; q<444; q++);
	}
}


void setupComm()
{
	delay(50);
	/*
	//CONF USART en modo asincrono
	clrBit(UCSR0C,UMSEL00);
	clrBit(UCSR0C,UMSEL01);
	//envia datos de 8 bits
	setBit(UCSR0C,UCSZ00);
	setBit(UCSR0C,UCSZ01);
	clrBit(UCSR0B,UCSZ02);
	
	//calculo de baud rate
	setBit(UCSR0A,U2X0); //escoger ecuacion para calcular UBRR0
	UBRR0 = (F_CPU/16/BAUD) - 1;
	
	setBit(UCSR0B,TXEN0); //enable transmision comm
	setBit(UCSR0B,RXEN0);//enable reception comm
	*/
}




void sendMoney(char * total[])
{
		/*
		for(volatile int i =0 ; i<strlen(*total) ; i++)
		{
			while ( !(getBit(UCSR0A,UDRE0)) ); //esperar a que el buffer de transmision este vacio
			
			UDR0 = *total[i]; //cargo el buffer con el dato
		}
		*/
		delay(50);
}

char * receiveData()
{	
	char * data = malloc(sizeof(char)*4);
	/*
	for(volatile int i =0 ; i < 4 ; i++)
	{
		while ( !(getBit(UCSR0A,RXC0)) ); //esperar a que el buffer de transmision este vacio
		
		*(data + i) = UDR0;
	}
	*/
	sprintf(data,"1234");
	delay(50);
	return data;
}
