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
  Motor_On , devounce_On, Motor_Off, bebounce_Off
}stateType;    //Set states

volatile stateType state = Motor_On; //Set initial state of the system



int main(){
 initADC0();
 initTimer1();
 initSwitchPB3():
 updateDutyCycle();


  while(1){

  }

  return 0;
}
