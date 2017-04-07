#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <avr/io.h>

/*
 * Pin Documentation
 *     PB5 --> Onboard LED
 *     PD4 --> Motor 1 Direction
 *     PD7 --> Motor 2 Direction
 */

/*
 * Initializes GPIO pins as inputs and outputs
 */
void gpio_init();

#endif
