#include "adc.h"
#include <avr/io.h>

void initADC0(){
  // set voltage references to be AVCC
  ADMUX |= (1 << REFS0);
  ADMUX &= ~(1 << REFS1);

  // ADLAR = 0 (RIGHT JUSTIFIED)
  ADMUX &= ~(1 << ADLAR);

  // Set ADC0 as single-ended input with MUX[5:0] = 0b000000
  ADMUX &= ~(1 << MUX2) | (1 << MUX1) | (1 << MUX0) | (1<< MUX3) | (1<<MUX4);
  ADCSRB &= ~(1<<MUX5);


  // set Auto Trigger Source Selection
  // set to free-running mode ADTS[2:0] = 0b000
  // 
  ADCSRB &= ~(1 << ADTS2 | 1 << ADTS1 | 1 << ADTS0);

  // enable auto-triggering turn-on ADC
  ADCSRA |= (1 << ADATE);

  //Set event to trigger ADC sample
  ADCSRB &= ~(1<<ADTS2 | 1<<ADTS1 | 1<<ADTS0); //Change as needed
  //Currently in free-running mode

  //Enable Interrupt Flag
  ADCSRA |= (1<<ADIF);

  //Turn on ADC
  ADCSRA |= (1 << ADEN);
  // set the pre-scaler to 128
  // ADC clock frequency is 16 Mhz divided by pre-scaler = 125KHz
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  // disable ADC0 pin digital input - pin A0 on board
  DIDR0 |= (1 << ADC0D);

  // start the first conversion
  ADCSRA |= (1 << ADSC);
}