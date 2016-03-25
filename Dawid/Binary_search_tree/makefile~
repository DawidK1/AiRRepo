main: main.o bst.o
	gcc -o main main.o bst.o

main.o: main.c
	gcc -Wall -c main.c -o main.o

game.o: bst.c bst.h
	gcc -Wall -c bst.c 

.Phony: clean

clean:
	rm -f main.o bst.o
