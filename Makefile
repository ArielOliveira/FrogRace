corridaSapo = ./bin/corridaSapo

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11

objs = ./build/main.o ./build/sapos.o

corridaSapo: $(corridaSapo)

$(corridaSapo): CPPFLAGS += -I. -I./include/
$(corridaSapo): $(objs)
	$(CC) $^ $(CPPFLAGS) -o $@

./build/main.o: ./src/main.cpp 
	$(CC) -c $(CPPFLAGS) $< -o $@

./build/sapos.o: ./src/sapos.cpp ./include/sapos.h
	$(CC) -c $(CPPFLAGS) $< -o $@	

dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test
	
	
