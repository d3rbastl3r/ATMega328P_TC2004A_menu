#ifndef _PROGRESS_VIEW__CPP_
#define _PROGRESS_VIEW__CPP_

#include "_atmega328PConf.h"

#include <avr/io.h>

#include "displayLCD.h"
#include "utils.h"
#include "AbstractView.cpp"

class ProgressView : public AbstractView {
  public:
    ProgressView(const char *title): title(title) {
        topTemperature = 0;
        botTemperature = 0;
        progressPercent = 0;
        valuesChanged = false;

        // Initialize the temp string
        tmpNumStr[0] = '9';
        tmpNumStr[1] = '9';
        tmpNumStr[2] = '9';
        tmpNumStr[3] = '\0'; // Indicates the end of the string
    }

    /**
     * Set the temperature of the top and bottom sensors
     */
    void setTemperature(uint16_t topTemperature, uint16_t botTemperature) {
      this->topTemperature = topTemperature;
      this->botTemperature = botTemperature;
      valuesChanged = true;
    }

    /**
     * Set the progress in percent. Allowed values are from 0 to 100
     */
    void setProgress(uint8_t progressPercent) {
      if (progressPercent > 100) {
        progressPercent = 100;
      }

      this->progressPercent = progressPercent;
      valuesChanged = true;
    }

    virtual AbstractView *performUp() { return this; }
    virtual AbstractView *performDown() { return this; }
    virtual AbstractView *performRight() { return this; }
    virtual AbstractView *performLeft() { return this; }
    virtual AbstractView *performEnter() { return this; }

    virtual void render(bool force=false) {
      if (!force && !valuesChanged) {
        return;
      }

      DISPLAY_LCD_clearDisplay();

      DISPLAY_LCD_writeRow(0, 0, title);

      renderProgressBar();

      UTILS_toChar(topTemperature, tmpNumStr);
      DISPLAY_LCD_writeRow(2, 0, "Top: ");
      DISPLAY_LCD_writeRow(2, 5, tmpNumStr); // TODO: topTemperature > 0 ? lcd.print(topTemperature) : lcd.print('-');
      DISPLAY_LCD_writeRow(2, 8, ", ");

      UTILS_toChar(botTemperature, tmpNumStr);
      DISPLAY_LCD_writeRow(2, 10, "Bot: ");
      DISPLAY_LCD_writeRow(2, 15, tmpNumStr); // TODO: botTemperature > 0 ? lcd.print(botTemperature) : lcd.print('-') ;

      valuesChanged = false;
    }

    /**
     * DEBUG FUNCTION, REMOVE
     */
    virtual void debug() {
      topTemperature += 12;
      botTemperature += 7;

      progressPercent += 5;
      if (progressPercent > 100) {
        progressPercent = 100;
      }

      valuesChanged = true;
    };

  private:
    const char *title;

    char tmpNumStr[4];// Temp string to hold converted numbers for printing

    // Current temperature of the top and bottom heating elements
    uint16_t topTemperature;
    uint16_t botTemperature;

    uint8_t progressPercent;

    bool valuesChanged;

    void renderProgressBar() {
      char progressBar[20] = {'[', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', ']'};

      uint8_t percentStep = 12;
      for (uint8_t i=1; i<=18; ++i) {
        if (progressPercent >= percentStep) {
          progressBar[i] = '#';
          percentStep += 5;
        }
      }

      DISPLAY_LCD_writeRow(1, 0, progressBar);
    }
};

#endif
