#ifndef _TEST__CPP_
#define _TEST__CPP_

#include <functional>
#include <iostream>
#include <string>

/*
 * Class provide a holder for simple void test methods without parameter.
 */
class Test {
    public:
    Test(const std::string& name, const std::function<void()>& function) : name(name), function(function) {}

    std::string name;
    std::function<void(void)> function;
};

#endif