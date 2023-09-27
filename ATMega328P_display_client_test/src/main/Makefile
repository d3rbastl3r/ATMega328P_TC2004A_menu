# Compiler and compiler flags
CC = g++
CFLAGS = -std=c++11 -Wall
# LIBFLAGS = -shared

ROOT_DIR = $(realpath ../..)
OBJ_MAIN_DIR = $(ROOT_DIR)/obj/main

compile_objects: $(OBJ_MAIN_DIR)/Assertions.o \
                 $(OBJ_MAIN_DIR)/Test.o

$(OBJ_MAIN_DIR)/Assertions.o: Assertions.cpp Assertions.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_MAIN_DIR)/Test.o: Test.cpp Test.h
	$(CC) $(CFLAGS) -c -o $@ $<

refresh:
	mkdir --parents $(OBJ_MAIN_DIR)
	rm --force $(OBJ_MAIN_DIR)/*.o
