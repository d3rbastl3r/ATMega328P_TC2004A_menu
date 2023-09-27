#ifndef _UTILS__H_
#define _UTILS__H_

#ifndef ENABLE_UTEST
    #include <avr/io.h>
#else
    #include "_mocks/avr_io.h"
#endif

/**
 * Converts an integer to a char*.
 * 
 * @param from integer with maximal three digits
 * @param result char array of size three. Lower index represents the higher digit
 */
void UTILS_toChar(uint8_t from, char result[3]);

#endif