#define F_CPU (1000000L) //pre-defining CPU speed
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main (void) {
    DDRB |= 0xFF; // set all PORTB pins for output
    /*Same as saying*/
    //DDRB = 11111111;

    PORTB |= _BV(PB4); //set pin PB4 high
    /*Same as saying*/
    //PORTB = 00001000;
    
    for (;;) {
        // keeps led on forever
    }
}