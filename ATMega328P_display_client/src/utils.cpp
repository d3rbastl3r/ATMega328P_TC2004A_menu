#include <avr/io.h>

#include "utils.h"

void UTILS_toChar(uint8_t from, char result[3]) {
    int singleNum = (from % 10) + 48;
    result[2] = (char)singleNum;

    from = from / 10;
    singleNum = (from % 10) + 48;
    result[1] = (char)singleNum;

    from = from / 10;
    singleNum = (from % 10) + 48;
    result[0] = (char)singleNum;
}