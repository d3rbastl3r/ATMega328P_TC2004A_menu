#include "_atmega328PConf.h"

#include <avr/io.h>
#include <util/delay.h>

#include "displayLCD.h"

#define DISPLAY_LCD_DATA_PORT PORTD
#define DISPLAY_LCD_RS_PIN PB0
#define DISPLAY_LCD_EN_PIN PC5

// Private functions
void DISPLAY_LCD_command(uint8_t command);
void DISPLAY_LCD_writeChar(uint8_t data);
void DISPLAY_LCD_writeString(const char *str);

/**
 * Setup the MCU for LCD display connection
 */
void DISPLAY_LCD_setupMCU() {
    DDRD = 0xFF; // Set all the data pins as output
    DDRB |= (1 << DDB0); // RS on PB0
    DDRC |= (1 << DDC5); // EN on PC5
}

void DISPLAY_LCD_init() {
    _delay_ms(15);     // Wait for display to power up

    DISPLAY_LCD_command(0x38); // Function set: 8-bit mode, 2-line display, 5x8 font // TODO: Wrong comment on line?
    DISPLAY_LCD_command(0x38); // Function set: 8-bit mode, 2-line display, 5x8 font
    DISPLAY_LCD_command(0x38); // Function set: 8-bit mode, 2-line display, 5x8 font
    DISPLAY_LCD_command(0x06); // Entry mode set: increment cursor, no display shift
    DISPLAY_LCD_command(0x0C); // Display on/off control: display on, cursor off, blink off
    DISPLAY_LCD_command(0x01); // Clear display, cursor home
}

void DISPLAY_LCD_command(uint8_t command) {
    DISPLAY_LCD_DATA_PORT = command;
    PORTB &= ~(1 << DISPLAY_LCD_RS_PIN);    // RS low to indicate a command
    PORTC |= (1 << DISPLAY_LCD_EN_PIN);     // EN high for enable
    _delay_us(1);                           // Wait to enable signal to settle
    PORTC &= ~(1 << DISPLAY_LCD_EN_PIN);    // EN low for disable
    _delay_ms(2);                           // Wait for write to exeute
}

void DISPLAY_LCD_writeChar(uint8_t data) {
    DISPLAY_LCD_DATA_PORT = data;
    PORTB |= (1 << DISPLAY_LCD_RS_PIN);     // RS high to indicate data
    PORTC |= (1 << DISPLAY_LCD_EN_PIN);     // EN high for enable
    _delay_us(1);                           // Wait to enable signal to settle
    PORTC &= ~(1 << DISPLAY_LCD_EN_PIN);    // EN low for disable
    _delay_us(100);                         // Wait for write to exeute
}

void DISPLAY_LCD_writeString(const char *str) {
    while (*str) {
        DISPLAY_LCD_writeChar(*str++);
    }
}

/**
 * Write given string to the selected row.
 * 
 * @param rowNumber number of the row
 * @param colNumber number of the char in the row / column. Accept values from 0 to 19
 * @param rowString string which should be printed to the selected position
 */
void DISPLAY_LCD_writeRow(uint8_t rowNumber, uint8_t colNumber, const char *rowString) {
    if (colNumber > 19) {
        colNumber = 19;
    }

    // Perform row selection on the display
    switch(rowNumber) {
        case 0:
            DISPLAY_LCD_command(0x80 + colNumber);
            break;
        
        case 1:
            DISPLAY_LCD_command(0xC0 + colNumber);
            break;

        case 2:
            DISPLAY_LCD_command(0x94 + colNumber);
            break;

        case 3:
            DISPLAY_LCD_command(0xD4 + colNumber);
            break;

        default: // If an invalid row is given, given data should not be printed
            return;
    }

    DISPLAY_LCD_writeString(rowString);
}

void DISPLAY_LCD_clearDisplay() {
    DISPLAY_LCD_command(0x01); // Clear display, cursor home
}
