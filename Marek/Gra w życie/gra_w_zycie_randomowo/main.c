#include "array.h"
#include "game.h"

#include <unistd.h>


int main()
{


	int kolumny=80, wiersze=50;
	int i=1;

	cell** board=NULL;
	board=create(kolumny, wiersze);	
	
	rand_data(board, kolumny, wiersze);
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
		file_save(board, kolumny, wiersze, "wyjscie.txt");
		i++;
		usleep(250000);
	}

	delet(&board,wiersze);
	return 0;
}
