#define F_CPU (1000000L) //pre-defining CPU speed
#include <avr/io.h>
#define F_CPU (1000000L) //pre-defining CPU speed
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

ISR(INT0_vect) {
    PORTB ^= _BV(PB4); //toggle pin PB4 high  
}


int main (void) {
    //Refer back to LED tutorial to see why we do this
    DDRB |= 0xFF; // set all PORTB pins for output

    sei(); // enable global interrupts    
    initButton(); // intitialize button interrupts

    for (;;) {
        // keeps led on forever
    }
}