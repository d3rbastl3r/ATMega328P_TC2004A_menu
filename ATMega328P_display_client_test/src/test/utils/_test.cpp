#include <iostream>
#include <vector>
#include <functional>

#include <inttypes.h>
#include <string.h>

#include "../../main/Test.h"
#include "../../main/Assertions.h"

#include "utils.h"

int main(void) {
    std::vector<Test> tests;
    tests.push_back(Test(
        "toChar: should convert single digit number to char with two leading zeros",
        [](void) {
            // given
            uint8_t numberToConvert = 1;
            char result[3] = {};

            // when
            UTILS_toChar(numberToConvert, result);

            // then
            Assertions::assertEqual(result, "001", 3);
        }
    ));

    tests.push_back(Test(
        "toChar: should convert dual digit number to char with one leading zero",
        [](void) {
            // given
            uint8_t numberToConvert = 13;
            char result[3] = {};

            // when
            UTILS_toChar(numberToConvert, result);

            // then
            Assertions::assertEqual(result, "013", 3);
        }
    ));

    tests.push_back(Test(
        "toChar: should convert three digit number to char with no leading zeroes",
        [](void) {
            // given
            uint8_t numberToConvert = 128;
            char result[3] = {};

            // when
            UTILS_toChar(numberToConvert, result);

            // then
            Assertions::assertEqual(result, "128", 3);
        }
    ));
    for (Test test : tests) {
        std::cout << "- " << test.getName() << std::endl;
        test.execute();
    }

    return 0;
}
