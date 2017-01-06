main: main.o Puzzle.o
	g++ -Wall main.o Puzzle.o -o main

main.o: main.cpp List.h Puzzle.o
	g++ -Wall -c main.cpp -o main.o

Puzzle.o: Puzzle.cpp Puzzle.h ListNode.h
	g++ -Wall -c Puzzle.cpp -o Puzzle.o

.Phony: clean
clean:
	rm -f *.o
