#include <iostream>
#include <vector>
#include <functional>

#include <string.h>

#include "../../main/Test.h"
#include "../../main/Assertions.h"

#include "_mocks/SPI.h"

#include "RemoteCtrl.cpp"

int main(void) {
    std::vector<Test> tests;

    tests.push_back(Test(
        "send: should send given command code followed by given data",
        [](void) {
            // given
            RemoteCommandCode commandCode = RemoteCommandCode::SEND_HEATING_PARAMETER;
            uint8_t data[8] = {commandCode, 10, 20, 30, 40, 50, 60, 70};
            RemoteCtrl remoteCtrl;

            // when
            remoteCtrl.send(commandCode, data+1);

            // then
            Assertions::assertEqual(test_bytesSend, 8);
            Assertions::assertEqual(test_sendData, data, 8);
        }
    ));

    tests.push_back(Test(
        "send: should send command first and wait until ...",
        [](void) {
            // given
            // when
            // then
        }
    ));

    for (Test test : tests) {
        // TODO: Move this print in to the assertion class, so it is possible to print "pass" or "fail"
        // TODO: [ PASSED ] test description
        // TODO: [ FAILED ] testt description
        std::cout << "- " << test.getName() << std::endl;
        test.execute();
    }

    return 0;
}
