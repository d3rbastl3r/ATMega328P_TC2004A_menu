#include <iostream>
#include <inttypes.h>
#include <string.h>

#include "Test_utils.cpp"

int main(void) {
    Test_utils testUtils;
    for (const Test& test : testUtils.tests) {
        std::cout << "- " << test.name << std::endl;
        test.function();
    }

    return 0;
}