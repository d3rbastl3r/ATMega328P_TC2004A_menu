# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -Wall

# Flags for unit testing
UTFLAGS += -DENABLE_UTEST=1

# ...
testMain: ./obj/_main.o \
          ./obj/Test_utils.o \
		  ./obj/framework/Test.o \
		  ./obj/framework/Assertions.o \
          ./obj/test/utils.o \

	$(CC) $(CFLAGS) -o $@ $^

./obj/_main.o: ./src/_main.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

./obj/Test_utils.o: ./src/Test_utils.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

# Compile test framework files
./obj/framework/Test.o: ./src/framework/Test.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

./obj/framework/Assertions.o: ./src/framework/Assertions.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

# Compile files to test
./obj/test/utils.o: ./src/test/utils.cpp ./src/test/utils.h
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

clean:
	rm --force ./obj/*.o
	rm --force ./obj/framework/*.o
	rm --force ./obj/test/*.o
	rm --force testMain

clean_sources:
	rm --force ./src/test/*.cpp
	rm --force ./src/test/*.h

cp_sources:
	cp ../ATMega328P_display_client/src/utils.h ./src/test/
	cp ../ATMega328P_display_client/src/utils.cpp ./src/test/