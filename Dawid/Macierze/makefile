mainm: mainm.o wektor.o matrix.o
	g++ mainm.o wektor.o matrix.o -o mainm
wektor.o: wektor.cpp wektor.h
	g++ -c wektor.cpp
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

mainm.o: mainm.cpp
	g++ -c mainm.cpp
