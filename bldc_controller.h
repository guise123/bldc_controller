
#ifndef bldc_controller_h
#define bldc_controller_h

#include "Arduino.h"

// the pin the potentiometer is connected to
#define speed_pin A5

// Use the 256x prescaler for a 62.5khz frequency
#define PRESCALE 1<<CS12;
//LH - hard coded since 4 byte floats are dropping the precision
#define TIMER_MICROS 16

extern void next_commutation(void);

#define ALL_COMMUTATION_BITS_OFF B11000000

// diag_pin is the pin used for diagnostic signals
#define diag_pin 4
#define diag_pin_bit (1 << diag_pin)

__inline__ void raise_diag() {
  PORTD |= diag_pin_bit; // set the 'start of cycle' signal (turned off in loop())
}

__inline__ void drop_diag() {
  PORTD &= ~diag_pin_bit;
}

#endif
