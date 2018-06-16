FrogRace = ./bin/FrogRace

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
DAT_DIR = ./data
LIB_DIR = ./lib

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11

objs = ./build/main.o ./build/sapo.o ./build/corrida.o ./build/fileHandler.o

FrogRace: $(FrogRace)

$(FrogRace): CPPFLAGS += -I. -I./include/
$(FrogRace): $(objs)
	$(CC) $^ $(CPPFLAGS) -o $@

./build/main.o: ./src/main.cpp ./include/lista.h ./include/dataManager.h
	$(CC) -c $(CPPFLAGS) $< -o $@

./build/sapo.o: ./src/sapo.cpp ./include/sapo.h
	$(CC) -c $(CPPFLAGS) $< -o $@	

./build/corrida.o: ./src/corrida.cpp ./include/corrida.h
	$(CC) -c $(CPPFLAGS) $< -o $@	

./build/fileHandler.o: ./src/fileHandler.cpp ./include/fileHandler.h
	$(CC) -c $(CPPFLAGS) $< -o $@	

debug: CPPFLAGS += -g -O0
debug: FrogRace

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p data
	mkdir -p lib
	mkdir -p test

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	
	
