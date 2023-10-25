#ifndef _ASSERTIONS__H_
#define _ASSERTIONS__H_

#include <vector>
#include <functional>

#include <inttypes.h>
#include <string.h>

class Assertions {
    private:
    std::vector<std::function<void()>> failOutputs;

    public:
    void showFails(std::string testDescription);

    void assertEqual(const char* toTest, const char* expectedResult, uint8_t size);
    void assertEqual(uint8_t toTest, uint8_t expectedResult);
    void assertEqual(uint8_t* toTest, uint8_t* expectedResult, uint8_t size);
};

#endif