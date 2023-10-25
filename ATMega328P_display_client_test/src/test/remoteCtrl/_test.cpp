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
    Assertions assertions;
    
    tests.push_back(Test(
        "send: should send given command code followed by given data",
        [&](void) {
            // given
            RemoteCommandCode commandCode = RemoteCommandCode::SEND_HEATING_PARAMETER;
            uint8_t data[8] = {commandCode, 10, 20, 30, 40, 50, 60, 70};
            RemoteCtrl remoteCtrl;

            // when
            remoteCtrl.send(commandCode, data+1);

            // then
            assertions.assertEqual(test_bytesSend, 8);
            assertions.assertEqual(test_sendData, data, 8);
        }
    ));

    tests.push_back(Test(
        "send: should send command first and wait until ...",
        [&](void) {
            // given
            // when
            // then
        }
    ));

    for (Test test : tests) {
        test.execute();
        assertions.showFails(test.getName());
    }

    return 0;
}
