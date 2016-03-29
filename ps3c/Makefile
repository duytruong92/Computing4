CC=g++
OFLAGS= -c -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -ansi -pedantic -lboost_unit_test_framework
CFLAGS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -ansi -pedantic -lboost_unit_test_framework
SOURCEMAIN=guitar_hero
SOURCE2=guitar_string_class
EXECUTABLE=GuitarHero

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCEMAIN).o $(SOURCE2).o ring_buffer_class.o
	$(CC) $(SOURCEMAIN).o $(SOURCE2).o ring_buffer_class.o $(CFLAGS) -o $(EXECUTABLE)
	
$(SOURCEMAIN).o: $(SOURCEMAIN).cpp $(SOURCE2).hpp
	$(CC) $(OFLAGS) $(SOURCEMAIN).cpp

$(SOURCE2).o: $(SOURCE2).cpp $(SOURCE2).hpp
	$(CC) $(OFLAGS) $(SOURCE2).cpp

ring_buffer_class.o: ring_buffer_class.cpp ring_buffer_class.hpp
	$(CC) $(OFLAGS) ring_buffer_class.cpp
    
permissions: all
	chmod o+x $(EXECUTABLE)

clean:
	rm *.o
