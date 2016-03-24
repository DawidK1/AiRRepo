#include "game.h"
#include "array.h"

void file_open(cell*** board, int* col, int* row, char* name)
{
	int kolumny=*col, wiersze=*row, c=0, r=0;
	cell alive={1, 0};
	FILE *plik=NULL;
	plik=fopen(name, "r"); // drugi argument to tryb dostępu r-odczyt
	if(plik==NULL)
	{
		printf("wystapil blad podczas otwarcia pliku");
	}
	
	while(feof(plik)==0) //feof zwraca wartosc rowna 0 gdy osiagniety zostal koniec pliku
	{
		fscanf(plik, "%d", &c);
		fscanf(plik, "%d", &r);
		
		printf("wiersze %d kolumny %d\n", r, c);
		if(r>wiersze)
		{
			resize(board, kolumny, wiersze, kolumny, r+1);
			wiersze=r+1;
		}
		if(c>kolumny)
		{
			resize(board, kolumny, wiersze, c+1, kolumny);
			kolumny=c+1;
		}
		insert(*board, r, c, alive);
	}
	fclose(plik);
	*col=kolumny;
	*row=wiersze;
}

void file_save(cell** board, int col, int row, char* name)
{
	int i, j;
	FILE *plik=NULL;
	plik=fopen(name, "w"); //tryb dostepu w - zapis
	if(plik==NULL)
	{
		printf("wystapil blad podczas otwarcia pliku");
	}
	
	if(board==NULL)
	{
		printf("wystapil blad, tablica nie istnieje");
	}
	else
	{
		for(i=0; i<row; i++)
		{
			for(j=0; j<col; j++)
			{
				if(board[i][j].status==1)
				{
					fprintf(plik, "%d ", i);
					fprintf(plik, "%d ", j);
					fprintf(plik, "\n");
				}
			}
		}
	}
	fprintf(plik, "\n");
	fclose(plik);
}	
			
void rand_data(cell** board, int col, int row)
{
	srand(time(NULL));
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			board[i][j].status=(rand())%2;
		}
	}
}	
			
			
			
			
			
			
			
			
			
			
			
			
	
