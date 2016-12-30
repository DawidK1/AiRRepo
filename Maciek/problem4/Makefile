all: main

main: main.o puzzle.o
		g++  main.o puzzle.o -o main
puzzle.o: puzzle.cpp puzzle.h
		g++ -c -Wall puzzle.cpp

clean:
	rm -rf *o main
