drzewo: main.o biblio.o
	gcc -lm -o drzewo main.o biblio.o

main.o: main.c
	gcc -Wall -c main.c -o main.o

biblio.o: biblio.c biblio.h
	gcc -Wall -c biblio.c 

.Phony: clean

clean:
	rm -f main.o biblio.o
