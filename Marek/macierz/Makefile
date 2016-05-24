all: main

main: wektor.o macierz.o main.o
	g++ wektor.o macierz.o main.o -o main

wektor.o: wektor.cpp wektor.h
	g++ -c -Wall wektor.h wektor.cpp

macierz.o: macierz.cpp macierz.h
	g++ -c -Wall macierz.h macierz.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

clean:
	rm -rf *o main
