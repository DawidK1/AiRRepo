main: main.o Toy.o Shop.o Firm.o
	g++ main.o Toy.o Shop.o Firm.o -o main

main.o: MyVector.h Iterator.h main.cpp
	g++ -Wall -c main.cpp -o main.o

Toy.o: Toy.h Toy.cpp
	g++ -Wall -c Toy.cpp -o Toy.o

Shop.o: Shop.cpp Shop.h
	g++ -Wall -c Shop.cpp -o Shop.o

Firm.o: Firm.cpp Firm.h
	g++ -Wall -c Firm.cpp -o Firm.o
.Phony: clean
clean:
	rm -f *.o
