all: main

main: StrType.o main.o
			g++ StrType.o main.o -o main

StrType.o: StrType.cpp StrType.h
			g++ -c -Wall StrType.cpp

main.o: main.cpp
			g++ -c -Wall main.cpp

clean:
	rm -rf *o main
