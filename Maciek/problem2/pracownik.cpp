#include <iostream>
#include "pracownik.h"


using namespace std;


pracownik :: pracownik() {
	imie = "brak";
	nazwisko = "brak";
	nip = 0;
	pesel = 0;
}

pracownik :: pracownik(string im, string nazw, int ni, int pes) {
	imie = im;
	nazwisko = nazw;
	nip = ni;
	pesel = pes;
}

string pracownik :: podaj_imie() {
	return imie;
}

string pracownik :: podaj_nazwisko() {
	return nazwisko;
}

int pracownik :: podaj_nip() {
	return nip;
}

int pracownik :: podaj_pesel() {
	return pesel;
}

void pracownik :: print() {
	cout << imie << " " << nazwisko << endl << nip << endl << pesel << endl;
	return;	
}

float pracownik :: wylicz_zarobki() {
	return 0;
}

pracownik :: ~pracownik() {
}

// metody do staly


staly :: staly (string im, string nazw, int ni, int pes, int placa) : pracownik (im, nazw, ni, pes) {
	pensja = placa;
}

staly :: staly (const pracownik & osoba, int placa) : pracownik(osoba) {
	pensja = placa;
}

void staly :: print() {
	pracownik :: print();
	cout << "pensja: " << pensja << endl;
	cout << "zarobki: " << wylicz_zarobki() << endl;
	return;
}

float staly :: wylicz_zarobki() {
	return pensja;
}


//metody do zlecenie


zlecenie :: zlecenie (string im, string nazw, int ni, int pes, int staw, int godz) : pracownik (im, nazw, ni, pes) {
	stawka = staw;
	godziny = godz;
}

zlecenie :: zlecenie (const pracownik & osoba, int staw, int godz) : pracownik (osoba) {
	stawka = staw;
	godziny = godz;
}

void zlecenie :: print () {
	pracownik :: print ();
	cout << "godziny: " << godziny << endl;
	cout << "stawka: " << stawka << endl;
	cout << "zarobki: " << wylicz_zarobki()<< endl;
	return;
}

float zlecenie :: wylicz_zarobki() {
	float zarobki;
	float nadgodziny;
	if(godziny >40) {
		nadgodziny = (godziny - 40)*1.5*stawka;
		zarobki = 40 * stawka + nadgodziny;
	}
	else {
		zarobki = godziny * stawka;
	}
	return zarobki;
}

int zlecenie :: podaj_stawke() {
	return stawka;
}

int zlecenie :: podaj_godziny() {
	return godziny;
}

// metody do procent


handel :: handel (string im, string nazw, int ni, int pes, float sprzed, int proc) : pracownik (im, nazw, ni, pes) {
	sprzedaz = sprzed;
	procent = proc;
}

handel :: handel (const pracownik & osoba, float sprzed, int proc) : pracownik(osoba) {
	sprzedaz = sprzed;
	procent = proc;
}

void handel :: print() {
	pracownik :: print ();
	cout << "sprzedaz: " << sprzedaz << endl;
	cout << "procent: " << procent << "%" << endl;
	cout << "zarobki: " << wylicz_zarobki() << endl;
	return;
}

float handel :: wylicz_zarobki() {
	float zarobki;
	zarobki = sprzedaz * procent / 100;
	return zarobki;
}

int handel :: podaj_sprzedaz() {
	return sprzedaz;
}

int handel :: podaj_procent() {
	return procent;
}









