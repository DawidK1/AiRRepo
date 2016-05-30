main: main.o Stack.o Calc.o
	g++ main.o Stack.o -o main
main.o: main.cpp
	g++ -c -Wall main.cpp 
Stack.o: Stack.cpp Stack.h
	g++ -c -Wall Stack.cpp Stack.h
Calc.o: Calc.h Calc.cpp Stack.o
	g++ -c -Wall Calc.cpp Calc.h
