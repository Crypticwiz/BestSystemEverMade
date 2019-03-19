// Author:         
// Net ID:         
// Date:           
// Assignment:     Lab 4
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"
#include "timer.h"
#include "adc.h"
#include "switch.h"

typedef enum stateType_enum {
  Motor_On , debounce_On, Motor_Off, debounce_Off
}stateType;    //Set states

volatile stateType state = Motor_On; //Set initial state of the system

//Global Variable
int on = 1;



int main(){
 initTimer1();
 initSwitchPB3();
sei();

  while(1){
      if (on == 0)
      {
        OCR3A = 0;
        OCR4A = 0;
      }
      else 
      {
        initADC0();
        updateDutyCycle();
      }

    switch (state) {
        case Motor_On:
        break;

        case debounce_On:
        delayUs(100);
        state = Motor_Off;
        break;

        case Motor_Off:
        break;

        case debounce_Off:
        delayUs(100);
        state = Motor_On;
        break;

        default :
        state = Motor_On;


    }
  }

  return 0;
}

ISR(PCINT0_vect){
    if(state == Motor_On){
      state = debounce_On;
    }
    else if (state == Motor_Off){
      if (on == 1){
        on = 0;
      }
      else {
        on = 1;
      }
      state = debounce_Off;
    }


}