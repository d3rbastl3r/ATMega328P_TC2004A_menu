#ifndef _MENU_ENTRY__CPP_
#define _MENU_ENTRY__CPP_

#include "AbstractView.cpp"

class MenuEntry {
  public:
  const char *entryText;
  AbstractView *nextPtr;

  MenuEntry(const char *entryText, AbstractView *nextPtr): entryText(entryText), nextPtr(nextPtr) {}
};

#endif
