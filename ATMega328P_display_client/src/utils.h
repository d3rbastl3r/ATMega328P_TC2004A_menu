#ifndef _UTILS__CPP_
#define _UTILS__CPP_

#include <avr/io.h>

/**
 * Converts an integer to a char*.
 * 
 * @param from integer with maximal three digits
 * @param result char array of size three. Lower index represents the higher digit
 */
void UTILS_toChar(uint8_t from, char result[3]);

#endif