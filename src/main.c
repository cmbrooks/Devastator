#include <avr/io.h>
#include <util/delay.h>

#include <gpio.h>
#include <move.h>

int main () {

	gpio_init();
	move_init();

	// Turn LED on
	PORTB |= (1 << PORTB5);
	
	while (1) {
		move(50, 100);
	}

	return 0;

}
