#ifndef PRACOWNIK
#define PRACOWNIK

using namespace std;

class pracownik {
	string imie;
	string nazwisko;
	int nip;
	int pesel;
public:
	pracownik();
	pracownik(string im, string nazw, int ni, int pes);
	virtual void print();
	virtual ~pracownik();
	virtual float wylicz_zarobki();
	string podaj_imie();
	string podaj_nazwisko();
	int podaj_nip();
	int podaj_pesel();
};






class staly: public pracownik {
protected:
	int pensja;
public:
	staly (string im, string nazw, int ni, int pes, int placa);
	staly (const pracownik & osoba, int placa);
	virtual void print();
	virtual float wylicz_zarobki();
};






class zlecenie: public pracownik {
protected:
	int stawka;
	int godziny;
public:
	zlecenie (string im, string nazw, int ni, int pes, int staw, int godz);
	zlecenie (const pracownik & osoba, int staw, int godz);
	virtual void print();
	virtual float wylicz_zarobki();
	int podaj_stawke();
	int podaj_godziny();
};







class handel: public pracownik {
protected:
	float sprzedaz;
	int procent;
public:
	handel (string im, string nazw, int ni, int pes, float sprzed, int proc);
	handel (const pracownik & osoba, float sprzed, int proc);
	virtual void print();
	virtual float wylicz_zarobki();
	int podaj_sprzedaz();
	int podaj_procent();
};


#endif
