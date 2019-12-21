#ifndef UART_H
#define UART_H
#include <msp430.h>
#include <stdint.h>

static uint32_t baudrate = 0;
static unsigned int UCA0BRW_Val = 0;
/*------------------------------------------------------*/
//Clock registers
typedef static struct _CLKS
{
    volatile unsigned char *CSCTL0_H_ = CSCTL0_H;
    volatile unsigned int *CSCTL1_ = CSCTL1;
    volatile unsigned int *CSCTL2_ = CSCTL2;
    volatile unsigned int *CSCTL3_ = CSCTL3;
} CLKS;

/*------------------------------------------------------*/
//eUSCI UART registers
typedef static struct _UART
{
    volatile unsigned int *UCA0CTLW0_ = (volatile unsigned int *) &UCA0CTLW0;
    volatile unsigned int *UCA0CTLW1_ = (volatile unsigned int *) &UCA0CTLW1;
    volatile unsigned int *UCA0BRW_ = (volatile unsigned int *) &UCA0BRW;
    volatile unsigned int *UCA0MCTLW_ = (volatile unsigned int *) &UCA0MCTLW;
    volatile unsigned int *UCA0STATW_ = (volatile unsigned int *) &UCA0STATW;
    volatile unsigned int *UCA0RXBUF_ = (volatile unsigned int *) &UCA0RXBUF;
    volatile unsigned int *UCA0TXBUF_ = (volatile unsigned int *) &UCA0TXBUF;
    volatile unsigned int *UCA0IE_ = (volatile unsigned int *) &UCA0IE;
    volatile unsigned int *UCA0IFG_ = (volatile unsigned int *) &UCA0IFG;
    volatile unsigned int *UCA0IV_ = (volatile unsigned int *) &UCA0IV;
} UART;


void beginInit(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz);

static void initUART(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz);

static void setClk(unsigned int srcClk, uint32_t srcClkHz);

#endif
