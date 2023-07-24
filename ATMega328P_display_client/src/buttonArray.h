#ifndef __BUTTON_ARRAY_H__
#define __BUTTON_ARRAY_H__

#include <avr/interrupt.h>
#include <avr/io.h>

#include "AbstractView.cpp"

void BUTTON_ARRAY_setupMCU();

AbstractView* BUTTON_ARRAY_execute(AbstractView *viewPtr);

#endif
