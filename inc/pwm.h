#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

/*
 * Initializes all components necessary for PWM functionality
 */
void pwm_init();

/*
 * Calculates the raw value of a 8-bit duty cycle given a percentage
 */
uint8_t pwm_calc_duty(int percent);

#endif
