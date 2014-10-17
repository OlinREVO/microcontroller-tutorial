#define F_CPU (1000000L) //pre-defining CPU speed
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <stdlib.h>
//#include "uart.h"



// Set up external interrupts for INT0 for any logical change
int initButton() {
    EICRA = _BV(ISC00);
    EIMSK = _BV(INT0);
    return(0);
}

void buttonScript(int target, int val, uint8_t x, uint8_t y){
    char cSREG = SREG; //Store SREG
    PORTB &= _BV(PB4); //set pin PB4 low (turns off LED)
    SREG = cSREG;
}


ISR(INT0_vect) {
    buttonScript(NODE_TARGET_1, PIND & _BV(PD6), 0b01, 0b00); //button presses enabled only on pin PD6
}


int main (void) {
    DDRB |= 0xFF; // set all PORTB pins for output
    PORTB |= _BV(PB4); //set pin PB4 high
    

    /*Your code for tuning on multiple LEDs*/



    sei(); // enable global interrupts    
    initButton(); // intitialize button interrupts

    for (;;) {
        // listen for button presses forever
    }
}