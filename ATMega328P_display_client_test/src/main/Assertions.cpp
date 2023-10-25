#include <iostream>
#include <vector>
#include <functional>

#include <inttypes.h>
#include <string.h>

#include "Assertions.h"

void Assertions::showFails(std::string testDescription) {
    if (this->failOutputs.size() > 0) {
        std::cout << std::endl << "\033[1;31m[ FAILED ]\033[0m " << testDescription << std::endl;
        for (std::function<void()> output : this->failOutputs) {
            output();
        }
        std::cout << std::endl;
    }

    else {
        std::cout << "\033[1;32m[ PASSED ]\033[0m " << testDescription << std::endl;
    }

    this->failOutputs.clear();
}

void Assertions::assertEqual(uint8_t toTest, uint8_t expectedResult) {
    if (toTest != expectedResult) {
        this->failOutputs.push_back([=]{
            std::cout << "    expected: " << unsigned(expectedResult) <<  std::endl;
            std::cout << "    but was: " << unsigned(toTest) <<  std::endl;
        });
    }
}

void Assertions::assertEqual(const char* toTest, const char* expectedResult, uint8_t size){
    if (strncmp(toTest, expectedResult, size) != 0) {
        this->failOutputs.push_back([=]{
            std::cout << "    expected: " << expectedResult <<  std::endl;
            std::cout << "    but was: " << toTest <<  std::endl;
        });
    }
}

void Assertions::assertEqual(uint8_t* toTest, uint8_t* expectedResult, uint8_t size) {
    bool isEqual = true;

    for (uint8_t i=0; i<size; i++) {
        if (toTest[i] != expectedResult[i]) {
            isEqual = false;
            break;
        }
    }

    if (!isEqual) {
        this->failOutputs.push_back([=]{
            std::cout << "    expected: [";
            for (uint8_t i=0; i<size; i++) {
                std::cout << unsigned(expectedResult[i]);
                if (i < size-1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;

            std::cout << "    but was: [";
            for (uint8_t i=0; i<size; i++) {
                std::cout << unsigned(toTest[i]);
                if (i < size-1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        });
    }
}
