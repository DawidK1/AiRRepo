#include "array.h"
#include "game.h"

#include <unistd.h>


int main(int a, char** sciezka)
{


	int kolumny=80, wiersze=22;
	int i=1;
	char* dane_wejsciowe = sciezka[1];
	char* dane_wyjsciowe = sciezka[2];

	cell** board=NULL;
	board=create(kolumny, wiersze);	
	
	file_open(&board, &kolumny, &wiersze, dane_wejsciowe);
	
	usleep(250000);
	system("clear");
	
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

	delet(&board,wiersze);
	return 0;
}
