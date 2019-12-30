#include "uart.h"
#define BUFFSIZE 64

int main(void)
{
    uint8_t buff[BUFFSIZE];
    unsigned int rate = 9600;
    uint8_t c = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//Use the rate as baudrate sourcing SMCLK as the clock
	//with a frequency of 1MHz
	beginInit(rate, UCSSEL_2, 1000000, buff, BUFFSIZE);

	PM5CTL0 &= ~LOCKLPM5;

	USCIA0_ISR();
	_bis_SR_register(GIE);
	//program loop
	for(;;)
	{
	    //transmission has started

	}
	return 0;
}
