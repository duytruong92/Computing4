CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework

all: 	ps2a test

ps2a: lfsr_class.o lfsr_test.o
	$(CC) lfsr_test.o lfsr_class.o $(CFLAGS)  -o ps2a

test: main.o lfsr_class.o
	$(CC) main.o lfsr_class.o $(CFLAGS)  -o main

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

lfsr_class.o: lfsr_class.cpp lfsr_class.hpp
	$(CC) $(OFLAGS) lfsr_class.cpp

lfsr_test.o: lfsr_test.cpp
	$(CC) $(OFLAGS) lfsr_test.cpp

clean:
	\rm -f *.o  *~ main lsfr_class test ps2 
