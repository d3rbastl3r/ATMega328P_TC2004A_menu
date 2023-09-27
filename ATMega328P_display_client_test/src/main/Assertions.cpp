#include <iostream>

#include <inttypes.h>
#include <string.h>

#include "Assertions.h"

bool Assertions::assertEqual(const char* toTest, const char* expectedResult, uint8_t size){
    if (strncmp(toTest, expectedResult, size) == 0) {
        return true;
    }

    std::cout << "expected: " << expectedResult <<  std::endl;
    std::cout << "but was: " << toTest <<  std::endl;
    return false;
}
