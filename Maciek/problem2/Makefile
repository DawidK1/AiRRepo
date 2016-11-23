all: main

main: pracownik.o main.o
			g++ pracownik.o main.o -o main

pracownik.o: pracownik.cpp pracownik.h
			g++ -c -Wall pracownik.cpp

main.o: main.cpp
			g++ -c -Wall main.cpp

clean:
	rm -rf *o main
