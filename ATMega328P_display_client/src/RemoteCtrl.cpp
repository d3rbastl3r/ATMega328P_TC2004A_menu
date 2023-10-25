#ifndef _REMOTE_CTRL__CPP_
#define _REMOTE_CTRL__CPP_

#ifndef ENABLE_UTEST
    #include <avr/io.h>
    
    #include "SPI.h"
#else
    #include "_mocks/avr_io.h"
    #include "_mocks/SPI.h"
#endif

/**
 * Command codes for remote communication between "display"- and "main"-module
 * 
 * Bits 3..0 : Specify the command (in combination with bit 7)
 * Bits 6..4 : Defines hom much data bytes will follow. 001 = 1Byte, 111 = 7Byte, 000 = 0Byte (Actually command with no payload).
 * Bit 7     : Command send by the "display"-module need to set this bit to 0. Commands send by the "main"-module need to set this bit to 1. 
 * 
 * TODO: Specifie command code 0b00000000 and 0b10000000 as a health check / availability command?
 */
enum RemoteCommandCode {
    /**
     * Code defines that heating configuration parameter will follow
     * TODO: Specifie fixed payload size
     */
    SEND_HEATING_PARAMETER = 0b00000001,

    /**
     * Code defines the heating progress followed by the progress value
     * TODO: Specifie fixed payload size
     */
    RECEIVE_HEATING_PROGRESS = 0b10000001
};

class RemoteCtrl {
    private:
    RemoteCommandCode commandCode;
    uint8_t* data;
    int8_t byteToSend = -1; // -1 means the command itself need to be send

    public:
    /**
     * Sends the given command and data via remote interface
     * 
     * @param commandCode the command for the receiver
     * @param data the data which should be send to the receiver
     */
    void send(RemoteCommandCode commandCode, uint8_t data[7]) {
        this->commandCode = commandCode;
        this->data = data;
        this->byteToSend = -1;

        while(sendNext());
    }

    /**
     * Setd the next byte via remote interface if available
     * 
     * @return true if next byte could be send, false if no data available / everythink is send 
     */
    bool sendNext() {
        if (this->byteToSend >= 7) {
            return false;
        }

        if (this->byteToSend < 0) {
            SPI_sendByte(this->commandCode);
            this->byteToSend = 0;
        }

        else {
            SPI_sendByte(this->data[this->byteToSend]);
            this->byteToSend++;
        }

        return true;
    }
};

#endif