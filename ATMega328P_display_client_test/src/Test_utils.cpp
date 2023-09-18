#ifndef _TEST_UTILS__CPP_
#define _TEST_UTILS__CPP_

#include <iostream>
#include <vector>
#include <functional>

#include <inttypes.h>
#include <string.h>

#include "framework/Test.cpp"
#include "framework/Assertions.cpp"

#include "test/utils.h"

class Test_utils {
    public:
    std::vector<Test> tests;

    Test_utils() {
        tests.push_back(Test(
            "toChar_should_convert_single_digit_number_to_char_with_two_leading_zeros",
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
            "toChar_should_convert_dual_digit_number_to_char_with_one_leading_zero",
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
            "toChar_should_convert_three_digit_number_to_char_with_no_leading_zeroes",
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
    }
};

#endif
