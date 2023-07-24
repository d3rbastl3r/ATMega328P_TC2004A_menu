PROJECT=atmega48_based_user_interface
PARTNO=m48
MCU=atmega48
BITCLOCK=32 # Adjust the Frequency of the Programmer. Use 1 on >=4MHz, 32 >=128KHz
PORT=usb
PROGRAMMER_ID=avrisp2

AVRDUDE_FLAGS=-p $(PARTNO) -c $(PROGRAMMER_ID) -P $(PORT) -B $(BITCLOCK)

$(PROJECT).hex: ./obj/_main.o \
				./obj/utils.o \
				./obj/buttonArray.o \
				./obj/displayLCD.o \
				./obj/AbstractView.o \
				./obj/MenuEntry.o \
				./obj/MenuView.o \
				./obj/ProgramView.o \
				./obj/ProgressView.o
	avr-gcc $^ -mmcu=$(MCU) -Os -o $(PROJECT).hex
	avr-size -B $(PROJECT).hex

./obj/_main.o: ./src/_main.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/utils.o: ./src/utils.cpp ./src/utils.h
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/buttonArray.o: ./src/buttonArray.cpp ./src/buttonArray.h
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@
    
./obj/displayLCD.o: ./src/displayLCD.cpp ./src/displayLCD.h
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/AbstractView.o: ./src/AbstractView.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/MenuEntry.o: ./src/MenuEntry.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/MenuView.o: ./src/MenuView.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/ProgramView.o: ./src/ProgramView.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

./obj/ProgressView.o: ./src/ProgressView.cpp
	avr-gcc -c $< -mmcu=$(MCU) -Os -o $@

flash:
	avrdude $(AVRDUDE_FLAGS) -U flash:w:$(PROJECT).hex

eep_r:
	avrdude $(AVRDUDE_FLAGS) -U eeprom:r:$(PROJECT).eep:r

eep_w:
	avrdude $(AVRDUDE_FLAGS) -U eeprom:w:$(PROJECT).eep:r

fuse_r:
	avrdude $(AVRDUDE_FLAGS) -U hfuse:r:$(PROJECT).hfuse:r -U lfuse:r:$(PROJECT).lfuse:r -U efuse:r:$(PROJECT).efuse:r

fuse_w:
	avrdude $(AVRDUDE_FLAGS) -U hfuse:w:$(PROJECT).hfuse:r -U lfuse:w:$(PROJECT).lfuse:r -U efuse:r:$(PROJECT).efuse:r

clean:
	rm -f ./obj/*.o
