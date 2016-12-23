main: main.o toy.o shop.o firm.o
	g++ main.o toy.o shop.o firm.o -o main

main.o: tvector.h iterator.h main.cpp
	g++ -Wall -c main.cpp -o main.o

toy.o: toy.h toy.cpp
	g++ -Wall -c toy.cpp -o toy.o

shop.o: shop.cpp shop.h
	g++ -Wall -c shop.cpp -o shop.o

firm.o: firm.cpp firm.h
	g++ -Wall -c firm.cpp -o firm.o

.Phony: clean

clean:
	rm -f *.o
