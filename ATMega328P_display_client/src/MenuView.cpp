#ifndef _MENU_VIEW__CPP_
#define _MENU_VIEW__CPP_

#include "_atmega48Conf.h"

#include <avr/io.h>

#include "displayLCD.h"

#include "AbstractView.cpp"
#include "MenuEntry.cpp"

template<uint8_t menuSize>
class MenuView : public AbstractView {
  public:
    //MenuView(LiquidCrystal &lcd, const MenuEntry (&menuValues)[6]): lcd(lcd), menu(menuValues) {}
    MenuView(const MenuEntry (&menuValues)[6]): menu(menuValues) {
      this->pos = 1;
      this->renderedPos = 255;
    }

    virtual AbstractView *performUp() {
      if (pos > 1) {
        --pos;
      }
      
      return this;
    }

    virtual AbstractView *performDown() {
      if (pos < menuSize - 1) {
        ++pos;
      }

      return this;
    }

    virtual AbstractView *performRight() {return this;}
    virtual AbstractView *performLeft() {return this;}

    virtual AbstractView *performEnter() {
      if (menu[pos].nextPtr != NULL) {
        return menu[pos].nextPtr;
      }

      return this;
    }

    virtual void render(bool force=true) {
      if (!force && renderedPos == pos) {
          return;
      }

      DISPLAY_LCD_clearDisplay();

      DISPLAY_LCD_writeRow(0, 0, getTitle());
      DISPLAY_LCD_writeRow(1, 2, getText(0));
      DISPLAY_LCD_writeRow(2, 2, getText(1));
      DISPLAY_LCD_writeRow(3, 2, getText(2));

      DISPLAY_LCD_writeRow(1, 0, "|");

      renderedPos = pos;
    }

    /**
     * DEBUG FUNCTION, REMOVE
     */
    virtual void debug() {};

  private:
    const MenuEntry menu[6];
    int8_t pos; // Position of the menu element pointer. Min pos is 1 because 0 is the title.
    int8_t renderedPos; // Actually rendered position. Default value different to pos for rendering initial frame
    //LiquidCrystal &lcd;

    /**
     * Returns the title of this menu.
     */
    const char *getTitle() {
      return menu[0].entryText;
    }

    /**
     * Get the menu text from the position of the pointer considering the given offset. If the position with the
     * offset addresses not valid menu row, dash character will be returned.
     */
    const char *getText(uint8_t offset) {
      uint8_t currentPos = pos + offset;
      if (currentPos >= menuSize) {
        return "-";
      }

      return menu[currentPos].entryText;
    }


};

#endif
