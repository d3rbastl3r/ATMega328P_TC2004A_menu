#ifndef _TEST__H_
#define _TEST__H_

#include <functional>
#include <string>

class Test {
    public:
    Test(const std::string& name, const std::function<void()>& function);
    
    /**
     * @brief Provide the name of the test
     * 
     * @return std::string Provides the name of the test
     */
    std::string getName();

    /**
     * @brief Run the test
     */
    void execute();

    private:
    std::string name;
    std::function<void(void)> function;
};

#endif