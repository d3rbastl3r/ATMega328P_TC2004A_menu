#include <avr/interrupt.h>
#include <avr/io.h>

#include "buttonArray.h"

#define BUTTON_ARRAY_CODE_NO_ACTION 0b000 // No button clicked
#define BUTTON_ARRAY_CODE_DEBUG_1 0b001 // Not In Use
#define BUTTON_ARRAY_CODE_DEBUG_2 0b010 // Not In Use
#define BUTTON_ARRAY_CODE_RIGHT 0b011
#define BUTTON_ARRAY_CODE_DOWN 0b100
#define BUTTON_ARRAY_CODE_ENTER 0b101
#define BUTTON_ARRAY_CODE_UP 0b110
#define BUTTON_ARRAY_CODE_LEFT 0b111

volatile uint8_t buttonCode = 0; // Code 0 means nothig was clicked

/**
 * Setup the MCU for button actions
 */
void BUTTON_ARRAY_setupMCU() {
    // Activate "Pin Change Interrupts" for PCINT11 (PC3)
    PCMSK1 |= (1 << PCINT11);

    // Activate of te interrupts for port c (PCIE1)
    PCICR |= (1 << PCIE1);

    // Global enable of interrupts
    sei();
}

/**
 * Check the button code and perform action on the given object. Returns result value of the called method.
 */
AbstractView* BUTTON_ARRAY_execute(AbstractView* viewPtr) {
    AbstractView* tempPtr = viewPtr;
    // Check button code and perform action
    switch (buttonCode) {
        case BUTTON_ARRAY_CODE_RIGHT:
            tempPtr = viewPtr->performRight();
            break;

        case BUTTON_ARRAY_CODE_DOWN:
            tempPtr = viewPtr->performDown();
            break;

        case BUTTON_ARRAY_CODE_ENTER:
            tempPtr = viewPtr->performEnter();
            break;

        case BUTTON_ARRAY_CODE_UP:
            tempPtr = viewPtr->performUp();
            break;

        case BUTTON_ARRAY_CODE_LEFT:
            tempPtr = viewPtr->performLeft();
            break;

        case BUTTON_ARRAY_CODE_DEBUG_1:
            break;

        case BUTTON_ARRAY_CODE_DEBUG_2:
            viewPtr->debug();
            break;
    }

    buttonCode = 0b00000000;

    return tempPtr;
}

// Interrupt-Service-Routine (ISR) for the Pin Change Interrupt
ISR(PCINT1_vect) {
     // Überprüfung, ob der PC3-Pin aktiviert wurde
    if (PINC & (1 << PC3)) {
        buttonCode = PINC & ((1 << PC2) | (1 << PC1) | (1 << PC0));
    }
}