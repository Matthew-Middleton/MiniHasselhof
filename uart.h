#ifndef UART_H
#define UART_H
#include <msp430.h>
#include <stdint.h>

static uint32_t baudrate = 0;
static volatile unsigned char *CSCTL0_H_ = CSCTL0_H;
static volatile unsigned int *CSCTL1_ = CSCTL1;
static volatile unsigned int *CSCTL2_ = CSCTL2;
static volatile unsigned int *CSCTL3_ = CSCTL3;

void begin(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz);

void initUART(uint32_t baud, unsigned int srcClk, uint32_t srcClkHz);

#endif
