#include <functional>
#include <string>

#include "Test.h"

Test::Test(const std::string& name, const std::function<void()>& function)
: name(name), function(function)  {}

std::string Test::getName() {
    return name;
}

void Test::execute() {
    function();
}
