#ifndef _PROGRAM_VIEW__CPP_
#define _PROGRAM_VIEW__CPP_

#include "_atmega328PConf.h"

#include <avr/io.h>

#include "displayLCD.h"
#include "utils.h"
#include "AbstractView.cpp"

class ProgramView : public AbstractView {
  public:
    // TODO: to private and read values from eeprom
    uint16_t maxTemperature; // In °C
    uint16_t heatingTime; // In seconds

    ProgramView(const char *title, const uint8_t configIndex): title(title), configIndex(configIndex) {
        pos = 1;
        renderedPos = 255;
        prevViewPtr = NULL;
        nextViewPtr = NULL;

        // Initialize the temp string
        tmpNumStr[0] = '9';
        tmpNumStr[1] = '9';
        tmpNumStr[2] = '9';
        tmpNumStr[3] = '\0'; // Indicates the end of the string
    }

    void setBackPtr(AbstractView *viewPtr) {
      prevViewPtr = viewPtr;
    }

    void setStartPtr(AbstractView *viewPtr) {
      nextViewPtr = viewPtr;
    }

    virtual AbstractView *performUp() {return this;}
    virtual AbstractView *performDown() {return this;}

    virtual AbstractView *performRight() {
      pos = 2;
      return this;
    }

    virtual AbstractView *performLeft() {
      pos = 1;
      return this;
    }

    virtual AbstractView *performEnter() {
      switch(pos) {
        case 1:
          if (prevViewPtr != NULL) {
            return prevViewPtr;
          }
          break;

        case 2:
          if (nextViewPtr != NULL) {
            return nextViewPtr;
          }
          break;
      }

      return this;
    }

    virtual void render(bool force=true) {
      if (!force && renderedPos == pos) {
          return;
      }

      DISPLAY_LCD_clearDisplay();

      DISPLAY_LCD_writeRow(0, 0, title);

      UTILS_toChar(maxTemperature, tmpNumStr);
      DISPLAY_LCD_writeRow(1, 2, "Temp:");
      DISPLAY_LCD_writeRow(1, 8, tmpNumStr); // TODO: Replace with "maxTemperature" value
      DISPLAY_LCD_writeRow(1, 12, "C"); // use °C

      UTILS_toChar(heatingTime, tmpNumStr);
      DISPLAY_LCD_writeRow(2, 2, "Time:");
      DISPLAY_LCD_writeRow(2, 8, tmpNumStr); // TODO: Replace with "heatingTime" value
      DISPLAY_LCD_writeRow(2, 12, "sec");

      DISPLAY_LCD_writeRow(3, 0, "|   BACK   START    ");

      switch(pos) {
        case 1:
          renderBackSelection();
          break;

        case 2:
          renderStartSelection();
          break;
      }

      renderedPos = pos;
    }

    /**
     * DEBUG FUNCTION, REMOVE
     */
    virtual void debug() {};

  private:
    const char *title;
    const uint8_t configIndex;

    char tmpNumStr[4];// Temp string to hold converted numbers for printing

    int8_t pos; // Cursor position in the view. 1: BACK, 2: START
    int8_t renderedPos; // Actually rendered position. Default value different to pos for rendering initial frame

    AbstractView *prevViewPtr; // Pointer to the previous view. Will be called on BACK select.
    AbstractView *nextViewPtr; // Pointer to the next view. Will be called on START select.

    void renderBackSelection() {
      DISPLAY_LCD_writeRow(3, 3, "[");
      DISPLAY_LCD_writeRow(3, 8, "]");
    }

    void renderStartSelection() {
      DISPLAY_LCD_writeRow(3, 10, "[");
      DISPLAY_LCD_writeRow(3, 16, "]");
    }
};

#endif
