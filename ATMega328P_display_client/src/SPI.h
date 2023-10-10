#ifndef __SPI_H__
#define __SPI_H__

#include <avr/io.h>

void SPI_setupMCU();
void SPI_sendByte(uint8_t data);

#endif