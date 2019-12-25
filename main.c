#include "uart.h"
#define MAXSIZE 8
/**
 * main.c
 */
int main(void)
{
    unsigned int rate = 9600;
    uint8_t c = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	//Use the rate as baudrate sourcing SMCLK as the clock
	//with a frequency of 1MHz
	beginInit(rate, UCSSEL_2, 1000000);

	PM5CTL0 &= ~LOCKLPM5;
	//program loop
	for(;;)
	{
	    //transmission has started
	    while(isInProgress())
	    {
	        //start bit has been received and the receive buffer is full
	        if(startRead() && isFull())
	        {
	            //read a character from the receive buffer and assign its bits to c
	            read(&c);
	        }
	    }
	}
	return 0;
}
