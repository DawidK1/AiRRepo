all: main

main: stack.o calc.o main.o
	g++ stack.o calc.o main.o -o main

stack.o: stack.cpp stack.h
	g++ -c -Wall stack.h stack.cpp

calc.o: calc.cpp calc.h
	g++ -c -Wall calc.h calc.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

clean:
	rm -rf *o main
