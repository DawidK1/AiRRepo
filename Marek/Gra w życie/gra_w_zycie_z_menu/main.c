#include "array.h"
#include "game.h"

#include <unistd.h>


int main(int a, char** sciezka)
{


	int kolumny=80, wiersze=50;
	int i=1, opcja, pokolenia;
	//char* dane_wejsciowe = sciezka[1];
	char* dane_wyjsciowe = sciezka[2];
	
	cell** board=NULL;
	board=create(kolumny, wiersze);	
	
	//file_open(&board, &kolumny, &wiersze, dane_wejsciowe);
	rand_data(board, kolumny, wiersze);
	usleep(250000);
	system("clear");
	
	printf("\t\t\t\tWitaj w grze w zycie !\n\n\n\n");
	usleep(750000);
	printf("\t\t\tMenu:\n");
	printf("\t\t\t1. Gra o zadanej liczbie pokolen\n");
	printf("\t\t\t2. Gra o nieskonczonej liczbie pokolen\n");
	printf("\t\t\t3. Wypisanie danych wejsciowych\n\n");
	printf("\t\t\t\tWpisz odpowiedni numer aby przejsc dalej... ");
	opcja=getchar();
	
	
	switch(opcja)
	{
		case '1':
			printf("\t\t\tPodaj oczekiwana liczbe pokolen:\n");
			scanf("\t\t\t%d", &pokolenia);
			while(i<=pokolenia)
			{
				system("clear");
				printf("\nLicznik: %d \n", i);
				clear_surround(board, kolumny, wiersze);
				check_board(board, kolumny, wiersze);
				change_status(board, kolumny, wiersze);
				show_array(board, kolumny, wiersze);
				file_save(board, kolumny, wiersze, dane_wyjsciowe);
				i++;
				usleep(250000);	
			}
			break;	
	
		
		case '2':
			while(1)
			{	
				system("clear");
		
				printf("\nLicznik: %d \n", i);
				clear_surround(board, kolumny, wiersze);
				check_board(board, kolumny, wiersze);
				change_status(board, kolumny, wiersze);
				show_array(board, kolumny, wiersze);
				file_save(board, kolumny, wiersze, dane_wyjsciowe);
				i++;
				usleep(250000);
			}	
			break;	
		
		case '3':
			printf("Dane wejsciowe:\n");
			show_array(board, kolumny, wiersze);
			break;
		
		default:
			printf("Wpisales zly klawisz");
			break;
	}
	
	delet(&board,wiersze);
	return 0;
}
