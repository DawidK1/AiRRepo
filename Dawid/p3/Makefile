main: main.o
	g++ main.o -o main

main.o: MyVector.h main.cpp
	g++ -Wall -c main.cpp -o main.o

.Phony: clean
clean:
	rm -f *.o
