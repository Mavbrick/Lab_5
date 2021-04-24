/* Author: 
 * Lab Section:
 * Assignment: Lab 5  Exercise 3
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code is my own original work.
 *
 *  Demo Link: https://youtu.be/S82qJrJHJBk
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States { Start, Off, Wait1, All, Wait2, Left, Wait3, Right, Wait4, Half1, Wait5, Half2, Wait6} State;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

void Tick() {

	switch(State) {
		
		case Start:
			State = Off;
		break;

		case Off:
			if(tmpA) {
				State = Wait1;
			}
			else {
				State = Off;
			}
		break;

		case Wait1:
			if(!tmpA) {
				State = All;
			}
			else {
				State = Wait1;
			}
		break;

		case All:
			if(tmpA) {
				State = Wait2;
			}
			else {
				State = All;
			}
		break;

		case Wait2:
			if(!tmpA) {
				State = Left;
			}
			else {
				State = Wait2;
			}
		break;

		case Left:
			if(tmpA) {
				State = Wait3;
			}
			else {
				State = Left;
			}
		break;

		case Wait3: 
			if(!tmpA) {
				State = Right;
			}
			else {
				State = Wait3;
			}
		break;

		case Right:
			if(tmpA) {
				State = Wait4;
			}
			else {
				State = Right;
			}
		break;

		case Wait4:
			if(!tmpA) {
				State = Half1;
			}
			else {
				State = Wait4;
			}
		break;

		case Half1:
			if(tmpA) {
				State = Wait5;
			}
			else {
				State = Half1;
			}
		break;

		case Wait5:
			if(!tmpA) {
				State = Half2;
			}
			else {
				State = Wait5;
			}
		break;

		case Half2:
			if(tmpA) {
				State = Wait6;
			}
			else {
				State = Half2;
			}
		break;

		case Wait6:
			if(!tmpA) {
				State = Off;
			}
			else {
				State = Wait6;
			}
		break;

		default:
		break;

	}

	switch(State) {
		case Start:
		break;

		case Off:
		tmpB = 0x00;
		break;

		case Wait1:
		tmpB = 0x00;
		break;

		case All:
		tmpB = 0x3F;
		break;

		case Wait2:
		tmpB = 0x3F;
		break;

		case Left:
		tmpB = 0x01;
		break;

		case Wait3:
		tmpB = 0x01;
		break;

		case Right:
		tmpB = 0x20;
		break;

		case Wait4:
		tmpB = 0x20;
		break;

		case Half1:
		tmpB = 0x07;
		break;

		case Wait5:
		tmpB = 0x07;
		break;

		case Half2:
		tmpB = 0x38;
		break;
		
		case Wait6:
		tmpB = 0x38;
		break;

		default:
		break;
	}

}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */

    State = Start;    

    while (1) {
	tmpA = ~PINA & 0x01;
	Tick();
	PORTB = tmpB;
    }
    return 1;
}
