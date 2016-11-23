main: main.o Toy.o
	g++ main.o Toy.o -o main

main.o: MyVector.h main.cpp
	g++ -Wall -c main.cpp -o main.o

Toy.o: Toy.h Toy.cpp
	g++ -Wall -c Toy.cpp -o Toy.o
.Phony: clean
clean:
	rm -f *.o
