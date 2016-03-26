CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: 	ps2b

ps2b: lfsr_class.o PhotoMagic.o
	$(CC) PhotoMagic.o lfsr_class.o $(CFLAGS) $(LFLAGS)  -o PhotoMagic


PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(OFLAGS) $(LFLAGS) PhotoMagic.cpp

lfsr_class.o: lfsr_class.cpp lfsr_class.hpp
	$(CC) $(OFLAGS) lfsr_class.cpp

clean:
	\rm -f *.o  *~ PhotoMagic ps2b


