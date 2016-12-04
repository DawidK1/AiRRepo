all: main

main: main.o toy.o shop.o company.o
		g++  main.o toy.o shop.o company.o -o main
toy.o: toy.cpp toy.h
		g++ -c -Wall toy.cpp
shop.o: shop.cpp shop.h
		g++ -c -Wall shop.cpp
company.o: company.cpp company.h
		g++ -c -Wall company.cpp

clean:
	rm -rf *o main
