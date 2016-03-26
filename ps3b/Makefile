CC=g++
OFLAGS= -c -lsfml-graphics -lsfml-window -lsfml-system -ansi -pedantic -lboost_unit_test_framework
CFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -ansi -pedantic -lboost_unit_test_framework
SOURCEMAIN=ring_buffer_itr_test
SOURCE2=ring_buffer_class
EXECUTABLE=ps3b

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCEMAIN).o $(SOURCE2).o
	$(CC) $(SOURCEMAIN).o $(SOURCE2).o $(CFLAGS) -o $(EXECUTABLE)
	
$(SOURCEMAIN).o: $(SOURCEMAIN).cpp $(SOURCE2).hpp
	$(CC) $(OFLAGS) $(SOURCEMAIN).cpp

$(SOURCE2).o: $(SOURCE2).cpp $(SOURCE2).hpp
	$(CC) $(OFLAGS) $(SOURCE2).cpp


permissions: all
	chmod o+x $(EXECUTABLE)

clean:
	rm *.o
