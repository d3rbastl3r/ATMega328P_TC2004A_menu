#ifndef _TEST_UTILS__CPP_
#define _TEST_UTILS__CPP_

#include <iostream>
#include <vector>
#include <functional>

#include <inttypes.h>
#include <string.h>

#include "framework/Test.cpp"

#include "test/utils.h"

class Test_utils {
    public:
    std::vector<Test> tests;

    Test_utils() {
        tests.push_back(Test(
            "toChar_should_convert_single_digit_number_to_char_with_two_leading_zeros",
            [](void) {
                // given
                uint8_t numberToConvert = 12;
                char result[3] = {};

                // when
                UTILS_toChar(numberToConvert, result);

                // then
                if (strncmp(result, "012", 3) == 0) {
                    std::cout << "Matches" << std::endl;
                }

                else {
                    std::cout << "NOT Matches! " <<  std::endl;
                    std::cout << "Value: " << result <<  std::endl;
                    std::cout << "Expected: " << "012" <<  std::endl;
                }
            }
        ));

        tests.push_back(Test(
            "toChar_should_convert_dual_digit_number_to_char_with_one_leading_zero",
            [](void) {
                // given
                // when
                // then
                std::cout << "Two Digits test ..." << std::endl;
            }
        ));

        tests.push_back(Test(
            "toChar_should_convert_three_digit_number_to_char_with_no_leading_zeroes",
            [](void) {
                // given
                // when
                // then
                std::cout << "Three Digits test ..." << std::endl;
            }
        ));
    }
};

#endif