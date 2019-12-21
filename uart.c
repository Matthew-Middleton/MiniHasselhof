
#include "uart.h"

//Baud Rate calculation:
//SourceClk/(16*desiredBaud)
//Example:
//8000000/(16*115200) = 4.34
//Fractional Part = 0.34 so UCBRSx = 0x4 according to Table 30-4. USBRSx Settings for Fractional Portion of N=fBRCLK/Baud Rate (Family User's Guide)
//UCAxBRW = 4
//UCBRFx = int( (4.34-4)*16) = 5
// The steps here are from Section 30.3.10 of the Family User's Guide

void beginInit(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz)
{
    P5DIR = BIT1|BIT0;
    PM5CTL0 &= ~LOCKPM5;

    baudrate = baud;

    initUART(baud, srcClk, srcClkHz);
}

static void initUART(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz)
{

    UCA0BRW_Val = srcClkHz/(16*baud);
    /*Sets eUSCI to use no parity, send LSB first, use 8-bits for the packet
     * with one stop bit in UART mode. This will be done in asynchronous mode
     * using SMCLK with interrupts disabled. All characters received set UCRXIFG
     * with all frames as data using no breaks. Software resets are disabled.
     */
    *(UART.UCA0CTLW0_) = UCPEN_0 | UCMSB_0 | UC7BIT_0 | UCSPB_0 |
            UCMODE_0 | UCSYNC_0 | UCSSEL_2 | UCRXEIE_0 | UCBRKIE_0 |
            UCDORM_0 | UCTXADDR_0 | UCTXBRK_0 | UCSWRST_0;
    //Sets glitch time to 2ns. Anything received that is below this glitch period
    //is considered erroneous and discarded.
    *(UART.UCA0CTLW1_) = UCGLIT_0;

}

static void setClk(unsigned int srcClk, uint32_t)
{

}







