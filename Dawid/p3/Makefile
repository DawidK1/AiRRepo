main: main.o Toy.o Shop.o
	g++ main.o Toy.o Shop.o -o main

main.o: MyVector.h Iterator.h main.cpp
	g++ -Wall -c main.cpp -o main.o

Toy.o: Toy.h Toy.cpp
	g++ -Wall -c Toy.cpp -o Toy.o

Shop.o: Shop.cpp Shop.h
	g++ -Wall -c Shop.cpp -o Shop.o
.Phony: clean
clean:
	rm -f *.o
