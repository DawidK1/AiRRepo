main: main.o workers.o
	g++ main.o workers.o -Wall -o main
main.o: main.cpp
	g++ -c main.cpp -Wall
workers.o: workers.h workers.cpp
	g++ -c workers.cpp -Wall
