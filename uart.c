
#include "uart.h"

//Baud Rate calculation:
//SourceClk/(16*desiredBaud)
//Example:
//8000000/(16*115200) = 4.34
//Fractional Part = 0.34 so UCBRSx = 0x4 according to Table 30-4. USBRSx Settings for Fractional Portion of N=fBRCLK/Baud Rate (Family User's Guide)
//UCAxBRW = 4
//UCBRFx = int( (4.34-4)*16) = 5
// The steps here are from Section 30.3.10 of the Family User's Guide

void begin(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz)
{
    P5DIR = BIT1|BIT0;
    PM5CTL0 &= ~LOCKPM5;

    baudrate = baud;

    initUART(baud, srcClk, srcClkHz);
}

void initUART(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz)
{

}







