#include "timer.h"
#include "pwm.h"
#include <avr/interrupt.h>

void updateDutyCycle(){
    OCR3A = 255*( ADCL + (ADCH << 0x08) /1024);
    OCR4A = 255*( 1 - (ADCL + (ADCH << 0x08) /1024) );
}

void initTimer3(){
TCCR3A |= (1 << WGM30); // Set timer to be in Fast PWM, 8-bit mode 
TCCR3A &= ~(1 << WGM31);
TCCR3B |= (1 << WGM32);
TCCR3B &= ~(1<< WGM33);

TCCR3B |= (1 << CS30); // Sets the prescaler to 1
  TCCR3B &= ~(1<< CS31);
  TCCR3B &= ~(1<< CS32);

  OCR3A = 16;     
}
