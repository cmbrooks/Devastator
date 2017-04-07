#include <gpio.h>

void gpio_init() {
	// Outputs
	DDRB |= (1 << PORTB5);
	DDRD |= (1 << PORTD4);
	DDRD |= (1 << PORTD7);
}
