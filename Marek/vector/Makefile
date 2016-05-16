vector: main.o vector.o
	g++ -lm -o vector main.o vector.o

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o

vector.o: vector.cpp vector.h
	g++ -Wall -c vector.cpp vector.h

.Phony: clean

clean:
	rm -f program1 main.o vector.o
