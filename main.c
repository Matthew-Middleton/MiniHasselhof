#include "uart.h"

/**
 * main.c
 */
int main(void)
{
    unsigned int rate = 9600;

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//Use the rate as baudrate sourcing SMCLK as the clock
	//with a frequency of 1MHz
	beginInit(rate, UCSSEL_2, 1000000);

	PM5CTL0 &= ~LOCKLPM5;
	return 0;
}
