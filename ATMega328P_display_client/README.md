# Pinouts
               ATMega48
             -----\_/-----
    !RESET -|  PC6   PC5  |- DE
       DB0 -|  PD0   PC4  |- ?
       DB1 -|  PD1   PC3  |- BT
       DB2 -|  PD2   PC2  |- B2
       DB3 -|  PD3   PC1  |- B1
       DB4 -|  PD4   PC0  |- B0
       VCC -|  VCC   GND  |- GND
       GND -|  GND   AREF |- AREF
     XTAL1 -|  PB6   AVCC |- AVCC
     XTAL2 -|  PB7   PB5  |- SCK
       DB5 -|  PD5   PB4  |- MISO
       DB6 -|  PD6   PB3  |- MOSI
       DB7 -|  PD7   PB2  |- !SS
       DRS -|  PB0   PB1  |- Data Ready
             -------------

# Display
Describe the dispay

# Button Array
Describe the button array

## Pins
PC0 - PC2: input for the button code
PC3: input for the button trigger (will trigger on each button)

# SPI

# Info AVRDUDE
- text + data = required flash memory
- data + bss = required sram memory

