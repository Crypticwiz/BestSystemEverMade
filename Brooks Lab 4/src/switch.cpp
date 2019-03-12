#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
   DDRB &= ~(1<<DDB3);           //initializes the switch to be an input
   PORTB |= (PORTB3);              //initializes the pull-up resistor

  PCICR |= (1 << PCIE0);      // enable PCINT for 7-0
  PCMSK0 |= (1 << PCINT3);    // enable PCINT for PCINT5
}
