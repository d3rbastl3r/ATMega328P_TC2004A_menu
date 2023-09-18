#ifndef _ASSERTIONS__CPP_
#define _ASSERTIONS__CPP_

#include <iostream>

#include <inttypes.h>
#include <string.h>

class Assertions {
    public:
    static bool assertEqual(const char* toTest, const char* expectedResult, uint8_t size){
        if (strncmp(toTest, expectedResult, size) == 0) {
            return true;
        }

        std::cout << "expected: " << expectedResult <<  std::endl;
        std::cout << "but was: " << toTest <<  std::endl;
        return false;
    }
};

#endif
