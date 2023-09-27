# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -Wall

ROOT_DIR = $(realpath ../../..)
OBJ_MAIN_DIR = $(ROOT_DIR)/obj/main
OBJ_TEST_DIR = $(ROOT_DIR)/obj/test/utils

# Flags for unit testing
UTFLAGS += -DENABLE_UTEST=1

$(ROOT_DIR)/test_utils: $(OBJ_TEST_DIR)/_test.o \
      $(OBJ_TEST_DIR)/utils.o \
	  $(OBJ_MAIN_DIR)/Assertions.o \
	  $(OBJ_MAIN_DIR)/Test.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_TEST_DIR)/_test.o: _test.cpp
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

$(OBJ_TEST_DIR)/utils.o: utils.cpp utils.h
	$(CC) $(CFLAGS) $(UTFLAGS) -c -o $@ $<

refresh:
	rm utils.cpp
	rm utils.h
	cp $(ROOT_DIR)/../ATMega328P_display_client/src/utils.cpp ./
	cp $(ROOT_DIR)/../ATMega328P_display_client/src/utils.h ./
	mkdir --parents $(OBJ_TEST_DIR)
	rm --force $(OBJ_TEST_DIR)/*.o
