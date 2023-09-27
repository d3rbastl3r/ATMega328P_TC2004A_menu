#ifndef _ASSERTIONS__H_
#define _ASSERTIONS__H_

#include <inttypes.h>

class Assertions {
    public:
    static bool assertEqual(const char* toTest, const char* expectedResult, uint8_t size);
};

#endif