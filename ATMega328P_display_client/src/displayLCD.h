#ifndef __DISPLAY_LCD_H__
#define __DISPLAY_LCD_H__

#include <avr/io.h>

void DISPLAY_LCD_setupMCU();
void DISPLAY_LCD_init();

void DISPLAY_LCD_command(uint8_t command);
void DISPLAY_LCD_writeString(const char *str);

void DISPLAY_LCD_writeRow(uint8_t rowNumber, uint8_t colNumber, const char *rowString);

void DISPLAY_LCD_clearDisplay();

#endif
