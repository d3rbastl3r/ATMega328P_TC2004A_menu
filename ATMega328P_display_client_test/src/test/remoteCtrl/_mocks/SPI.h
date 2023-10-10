#ifndef _SPI__H_
#define _SPI__H_

#include "avr_io.h"

// Helper stuff for the test
extern uint8_t test_sendData[256];
extern uint8_t test_bytesSend;

// Mocked methods
void SPI_sendByte(uint8_t data);

#endif
