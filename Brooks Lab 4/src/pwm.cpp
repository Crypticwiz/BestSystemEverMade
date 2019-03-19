#include "timer.h"
#include "pwm.h"
#include <avr/interrupt.h>

void updateDutuCycle(){
    OCR3A = 255*( ADCL + (ADCH << 0x08) /1024);
    OCR4A = 255*( 1 - (ADCL + (ADCH << 0x08) /1024) );
}
