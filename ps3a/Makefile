FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -Wall -Werror -ansi -pedantic -lboost_unit_test_framework
CC = g++


all: RingBuffer

RingBuffer: ring_buffer_class.o ring_buffer_test.o
	$(CC) -o ps3a ring_buffer_test.o ring_buffer_class.o $(FLAGS)

ring_buffer_class.o: ring_buffer_class.cpp ring_buffer_class.hpp
	$(CC) -c ring_buffer_class.cpp $(FLAGS)

ring_buffer_test.o: ring_buffer_test.cpp ring_buffer_class.cpp ring_buffer_class.hpp
	$(CC) -c ring_buffer_test.cpp ring_buffer_class.cpp ring_buffer_class.hpp $(FLAGS)
	
clean:
	rm *.o
	rm *~
