CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
VPATH = src:lib
OBJECTS = test.o main.o 

assignment9: $(OBJECTS)
	$(CC) $(OBJECTS) -o assignment9

debug: FLAGS += -g
debug: assignment9

test.o: test.cpp WeightedGraph.h
	$(CC) $(FLAGS) -Ilib -c src/test.cpp

main.o: main.cpp
	$(CC) $(FLAGS) -Ilib -c src/main.cpp

clean:
	rm assignment9 *.o
