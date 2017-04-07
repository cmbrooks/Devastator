#include <move.h>
#include <pwm.h>

void move_init() {
	pwm_init();
	DDRD |= (1 << PORTD4) | (1 << PORTD7);
	set_speed(LEFT, 0);
	set_speed(RIGHT, 0);
}

void set_speed(motor_t motor, int speed) {
	switch (motor) {
		case LEFT:
			OCR0B = pwm_calc_duty(speed);
			break;
		case RIGHT:
			OCR0A = pwm_calc_duty(speed);
			break;
		default:
			break;
	}	
}

void move_forward(int speed) {
	PORTD |= (1 << PORTD4) | (1 << PORTD7);
	set_speed(LEFT, speed);
	set_speed(RIGHT, speed);
}	

void move_backward(int speed) {
	PORTD &= (0 << PORTD4) & (0 << PORTD7);
	set_speed(LEFT, speed);
	set_speed(RIGHT, speed);
}

void move_stop() {
	set_speed(LEFT, 0);
	set_speed(RIGHT, 0);
}

void move(int left_speed, int right_speed) {
	// Configure direction based on sign of the speeds
	if (left_speed >= 0) {
		DDRD |= (1 << PORTD4);
	} else {
		DDRD &= (0 << PORTD4);
	}
	if (right_speed >= 0) {
		DDRD |= (1 << PORTD7);
	} else {
		DDRD &= (0 << PORTD7);
	}
	set_speed(LEFT, abs(left_speed));
	set_speed(RIGHT, abs(right_speed));
}
