#include "uart.h"

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	PM5CTL0 &= ~LOCKLPM5;
	return 0;
}
