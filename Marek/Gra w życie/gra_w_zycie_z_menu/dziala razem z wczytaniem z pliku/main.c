#include "array.h"
#include "game.h"

#include <unistd.h>
int main()
{
	int kolumny=80, wiersze=22;
	cell** board=NULL;
	board=create(kolumny, wiersze);	
	
	printf("przed zmianami kolumny %d wiersze %d\n", kolumny, wiersze);
	file_open(&board, &kolumny, &wiersze, "danewej.txt");
	printf("po zmianach kolumny %d wiersze %d\n", kolumny, wiersze);
	
	show_array(board, kolumny, wiersze);
	
	
	/*
	int i=0;
	while(i<10)
	{
	system("clear");
	printf("\n\n\n");
	rand_data(board, kolumny, wiersze);
	show_array(board, kolumny, wiersze);
	
	i++;
	printf("\n\n licznik:%d\n\n", i);
	
	usleep(1000000);
	}*/
	return 0;
}
