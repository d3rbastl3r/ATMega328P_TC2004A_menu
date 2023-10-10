#include "avr_io.h"

#include "SPI.h"

// Helper stuff for the test
uint8_t test_sendData[256] = {};
uint8_t test_bytesSend = 0;

// Mocked methods
void SPI_sendByte(uint8_t data) {
    test_sendData[test_bytesSend] = data;
    test_bytesSend++;
}