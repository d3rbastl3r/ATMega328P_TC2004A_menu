# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -Wall

ROOT_DIR = $(realpath ../../..)
OBJ_MAIN_DIR = $(ROOT_DIR)/obj/main
OBJ_TEST_DIR = $(ROOT_DIR)/obj/test/remoteCtrl

# Flags for unit testing
UTFLAGS += -DENABLE_UTEST=1

$(ROOT_DIR)/test_RemoteCtrl: $(OBJ_TEST_DIR)/_test.o \
                             $(OBJ_TEST_DIR)/_mocks/SPI.o \
                             $(OBJ_TEST_DIR)/RemoteCtrl.o \
	                         $(OBJ_MAIN_DIR)/Assertions.o \
	                         $(OBJ_MAIN_DIR)/Test.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TEST_DIR)/_test.o: _test.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

$(OBJ_TEST_DIR)/_mocks/SPI.o: _mocks/SPI.cpp _mocks/SPI.h
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

$(OBJ_TEST_DIR)/RemoteCtrl.o: RemoteCtrl.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

refresh:
	rm --force RemoteCtrl.cpp
	cp $(ROOT_DIR)/../ATMega328P_display_client/src/RemoteCtrl.cpp ./
	mkdir --parents $(OBJ_TEST_DIR)
	mkdir --parents $(OBJ_TEST_DIR)/_mocks
	rm --force $(OBJ_TEST_DIR)/*.o
