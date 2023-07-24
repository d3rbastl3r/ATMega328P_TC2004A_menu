#ifndef _ABSTRACT_VIEW__CPP_
#define _ABSTRACT_VIEW__CPP_

#include <avr/io.h>

class AbstractView {
  public:

  /**
   * Perform actions according to the up button click
   */
  virtual AbstractView *performUp() {};

  /**
   * Perform actions according to the down button click
   */
  virtual AbstractView *performDown() {};

  /**
   * Perform actions according to the right button click
   */
  virtual AbstractView *performRight() {};

  /**
   * Perform actions according to the down button click
   */
  virtual AbstractView *performLeft() {};

  /**
   * Perform actions according to the enter button click
   */
  virtual AbstractView *performEnter() {};

  /**
   * Perform rendering of the menu to the display
   */
  virtual void render(bool force=false) {};

  /**
   * DEBUG FUNCTION, REMOVE
   */
  virtual void debug() {};
};

#endif
