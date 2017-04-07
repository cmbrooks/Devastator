#ifndef MOVE_H
#define MOVE_H

#include <avr/io.h>
#include <stdlib.h>
#include <pwm.h>

typedef enum {
	LEFT,
	RIGHT
} motor_t;

/*
 * Initializes all subsystems for movement
 */
void move_init();

/*
 * @param motor_t motor: Specifies which motor to move
 * @param int speed: Percentage (0-100) of max speed
 * Sets the given motor to move at the given speed 
 */
void set_speed(motor_t motor, int speed);

void move_forward(int speed);

void move_backward(int speed);

void move_stop();

void move(int left_speed, int right_speed);

#endif
