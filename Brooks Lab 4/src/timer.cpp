#include "timer.h"

/* Initialize timer 1, you should not turn the timer on here. Use CTC mode  .*/
void initTimer1(){
TCCR1A &= ~(1 << WGM10); // Set timer to be in CTC mode 
TCCR1A &= ~(1 << WGM11);
TCCR1B |= (1 << WGM12);
TCCR1B &= ~(1<< WGM13);

  

  TCCR1B |= (1 << CS10); // Sets the prescaler to 1
  TCCR1B &= ~(1<< CS11);
  TCCR1B &= ~(1<< CS12);

  OCR1A = 16;                         //Gives a 1us delay

}

/* This delays the program an amount specified by unsigned int delay.
*/
void delayUs(unsigned int delay){
  TIFR1 |= (1 << OCF1A); // sets the flag down
TCNT1 = 0;
unsigned int Count = 0;


    while(Count < delay){                //Runs until we get the delay we want 
        if(TIFR1 & (1 << OCF1A)){           
            Count++;
            TIFR1 |= (1 << OCF1A);          
        }
    }

}
