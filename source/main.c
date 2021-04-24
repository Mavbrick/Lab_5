/*	Author: lab
 *  Partner(s) Name: Maverick
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
	/* Insert your solution below */
        unsigned char tmpA = 0x00;
        unsigned char tmpC = 0x00;

    while (1) {
        tmpA = ~PINA;
        tmpC = 0x00;

        if (tmpA <= 4) {
                tmpC = tmpC | 0x40;
        }

	if (tmpA == 0x01 || tmpA == 0x02) {
		tmpC = tmpC | 0x20;
	}
	else if (tmpA == 0x03 || tmpA == 0x04) {
		tmpC = tmpC | 0x30;
	}
	else if (tmpA == 0x05 || tmpA == 0x06) {
		tmpC = tmpC | 0x38;
	}
	else if (tmpA >= 7 && tmpA <= 9) {
		tmpC = tmpC | 0x3C;
	}
	else if (tmpA >= 10 && tmpA <= 12) {
		tmpC = tmpC | 0x3E;
	}
	else if (tmpA >= 13 && tmpA <= 15) {
		tmpC = tmpC | 0x3F;
	}
	else if (tmpA > 15) {
		tmpC = tmpC | 0x70;
	}

	PORTC = tmpC;

    }
    return 1;
}
