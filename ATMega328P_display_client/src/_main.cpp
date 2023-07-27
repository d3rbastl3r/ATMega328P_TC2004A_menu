/*
 * text: is what ends up in FLASH memory
 * data: initialization data. Ends up also in flash and sram?
 * bss : is ends up in ram
 * 
 * ATMega328P specs
 *  32K Bytes Flash
 *   2K Bytes SRAM
 *   1K Bytes EEPROM
 */

#include "_atmega328PConf.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "buttonArray.h"
#include "displayLCD.h"

#include "MenuView.cpp"
#include "MenuEntry.cpp"
#include "AbstractView.cpp"
#include "ProgramView.cpp"
#include "ProgressView.cpp"

ProgramView programViewSnPb("## Sn-Pb ##", 1);
ProgramView programViewSnAgCu("## Sn-Ag-Cu ##", 1);

ProgressView progressViewPreheat("Preheating ...");

MenuView<6> menuView(
  (MenuEntry[6]) {
    MenuEntry("## Program ##", NULL),
    MenuEntry("Sn-Pb", &programViewSnPb),
    MenuEntry("Sn-Ag-Cu", &programViewSnAgCu),
    MenuEntry("Custom 1", NULL),
    MenuEntry("Custom 2", NULL),
    MenuEntry("Custom 3", NULL)
  }
);

AbstractView *viewPtr = &menuView;

void setupMCU() {
    DISPLAY_LCD_setupMCU();
    BUTTON_ARRAY_setupMCU();
}

int main(void) {
    setupMCU();

    DISPLAY_LCD_init();

    int8_t renderedMainMenuPos = -1;

    // Move this setup to else where
    programViewSnPb.maxTemperature = 230; // In °C
    programViewSnPb.heatingTime = 240; // In seconds

    programViewSnAgCu.maxTemperature = 250; // In °C
    programViewSnAgCu.heatingTime = 240; // In seconds

    programViewSnPb.setBackPtr(&menuView);
    programViewSnAgCu.setBackPtr(&menuView);

    programViewSnPb.setStartPtr(&progressViewPreheat);
    programViewSnAgCu.setStartPtr(&progressViewPreheat);


    AbstractView *tempPtr = NULL; 
    while(1) {
        tempPtr = viewPtr;
        viewPtr = BUTTON_ARRAY_execute(viewPtr);

        // Force rentering the view if the view has changed
        viewPtr->render(tempPtr != viewPtr);
    }

    return 0;
}
