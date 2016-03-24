#include "game.h"
#include "array.h"

void check_board(cell** board, int col, int row)
{
	int i, j;
	//sprawdzam rogi tablicy, poza tablica sa tylko martwe komorki
	
	board[0][0].surround=board[0][1].status //lewy gorny rog
			    +board[1][0].status
			    +board[1][1].status;
			    
	board[row-1][0].surround=board[row-2][0].status //lewy dolny rog
				+board[row-2][1].status
				+board[row-1][1].status;
	
	board[0][col-1].surround=board[0][col-2].status //prawy gorny rog
				+board[1][col-2].status
				+board[1][col-1].status;
	
	board[row-1][col-1].surround=board[row-1][col-2].status //prawy dolny rog
				    +board[row-2][col-2].status
				    +board[row-2][col-1].status;
	
	//sprawdzam krawedzie tablicy bez rogow!
	
	for(i=1; i<row-1; i++) //lewa krawedz
	{
		board[i][0].surround=board[i-1][0].status
				    +board[i-1][1].status
				    +board[i][1].status
				    +board[i+1][1].status
				    +board[i+1][0].status;
	}
	for(j=1; j<col-1; j++) //dolna krawedz
	{
		board[row-1][j].surround=board[row-1][j-1].status 
					+board[row-2][j-1].status
					+board[row-2][j].status
					+board[row-2][j+1].status
			        	+board[row-1][j+1].status;
	}
	for(i=1; i<row-1; i++) //prawa krawedz
	{
		board[i][col-1].surround=board[i-1][col-1].status
					+board[i-1][col-2].status
					+board[i][col-2].status
					+board[i+1][col-2].status
					+board[i+1][col-1].status;
	}
	for(j=1; j<col-1; j++) //gorna krawedz
	{
		board[0][j].surround=board[0][j-1].status
				    +board[1][j-1].status
				    +board[1][j].status
				    +board[1][j+1].status
				    +board[0][j+1].status;	
	}
	
	//sprawdzam srodek tablicy
	
	for(i=1; i<row-1; i++)
	{
		for(j=1; j<col-1; j++)
		{
			board[i][j].surround=board[i-1][j-1].status
					    +board[i-1][j].status
					    +board[i-1][j+1].status
					    +board[i][j+1].status
					    +board[i+1][j+1].status
					    +board[i+1][j].status
					    +board[i+1][j-1].status
					    +board[i][j-1].status;
		}
	}
}

void change_status(cell** board, int col, int row)
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(board[i][j].status==1)
			{
				switch(board[i][j].surround)
				{
					case 2:
					board[i][j].status=1;
					break;
					
					case 3:
					board[i][j].status=1;
					break;
					
					default:
					board[i][j].status=0;
					break;
				}
			}
			if(board[i][j].status==0)
			{
				switch(board[i][j].surround)
				{
					case 3:
					board[i][j].status=1;
					break;
					
					default:
					board[i][j].status=0;
					break; 
				}
			}
		}
	}
}
	
	
	/*int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(board[i][j].status==1) 			
			{
				if(board[i][j].surround==2 || board[i][j].surround==3)
				{
					board[i][j].status=1;		
				}
				else                                    
				{
					board[i][j].status=0;
				}
			}
			else                                             				
			{
				if(board[i][j].surround==3)		
				{
					board[i][j].status=1;
				}
			}
			
		}
	}*/

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
					fprintf(plik, "%d ", j);
					fprintf(plik, "%d ", i);
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
			
			
			
			
			
			
			
			
			
			
			
			
	
