#include <pwm.h>

void pwm_init() {
	// Set PD5 and PD6 as outputs
	DDRD |= (1 << PORTD5);
	DDRD |= (1 << PORTD6);

	// Set duty cycle to 0 to start
	OCR0A = pwm_calc_duty(0);
	OCR0B = pwm_calc_duty(0);

	// Set Waveform Generation mode to Fast PWM
	TCCR0A |= ((1 << WGM01) | (1 << WGM00));
	TCCR0B |= ((1 << WGM01) | (1 << WGM00));

	// Set Compare Output Mode to Non-Inverting
	TCCR0A |= (1 << COM0A1);
	TCCR0B |= (1 << COM0B1);

	// Select 8KHz clock
	TCCR0A |= (1 << CS01); 
	TCCR0B |= (1 << CS01); 
	
}

uint8_t pwm_calc_duty(int percent) {
	// Clip the percentage at 100
	percent = (percent > 100) ? 100 : percent;
	// Clip the percentage at 0
	percent = (percent < 0) ? 0 : percent;
	return (255 / (100 / percent));
}

