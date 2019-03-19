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
void T1delayUs(unsigned int delay){
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

void initTimer3(){
TCCR3A &= ~(1 << WGM30); // Set timer to be in CTC mode 
TCCR3A &= ~(1 << WGM31);
TCCR3B |= (1 << WGM32);
TCCR3B &= ~(1<< WGM33);

TCCR3B |= (1 << CS30); // Sets the prescaler to 1
  TCCR3B &= ~(1<< CS31);
  TCCR3B &= ~(1<< CS32);

  OCR3A = 16;     
}

void T3delayUs(unsigned int delay){
  TIFR3 |= (1 << OCF3A); // sets the flag down
TCNT3 = 0;
unsigned int Count = 0;


    while(Count < delay){                //Runs until we get the delay we want 
        if(TIFR3 & (1 << OCF3A)){           
            Count++;
            TIFR3 |= (1 << OCF3A);          
        }
    }

}


void initTimer4(){
TCCR4A &= ~(1 << WGM40); // Set timer to be in CTC mode 
TCCR4A &= ~(1 << WGM41);
TCCR4B |= (1 << WGM42);
TCCR4B &= ~(1<< WGM43);

TCCR4B |= (1<< CS40);
TCCR4B & ~( 1<<CS41 | 1<<CS42);

OCR4A = 16;     
}

void T4delayUs(unsigned int delay){
  TIFR4 |= (1 << OCF4A); // sets the flag down
TCNT4 = 0;
unsigned int Count = 0;


    while(Count < delay){                //Runs until we get the delay we want 
        if(TIFR4 & (1 << OCF4A)){           
            Count++;
            TIFR4 |= (1 << OCF4A);          
        }
    }

}

