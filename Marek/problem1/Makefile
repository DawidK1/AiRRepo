all: main

main: strtype.o main.o
	g++ strtype.o main.o -o main

strtype.o: strtype.cpp strtype.h
	g++ -c -Wall strtype.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

clean:
	rm -rf *o main
