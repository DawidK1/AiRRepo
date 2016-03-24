#include "array.h"



cell** create(int col, int row)
{
	int i,j;
	cell** tab=NULL;
	tab=(cell**)malloc(sizeof(cell*)*row);
	if(tab==NULL)
	{
		printf("\nalokacja pamieci nieudana");
		return NULL;
	}
	for(i=0; i<row; i++)
	{
		tab[i]=(cell*)malloc(sizeof(cell)*col);
		if(tab[i]==NULL)
		{
			printf("\nalokacja pamieci nieudana");
			return NULL;
		}
	}
	
	for(i=0; i<row; i++)		//wypelnianie zerami calej tablicy
	{
		for(j=0; j<col; j++)
		{
			tab[i][j].status=0;
			tab[i][j].surround=0;
		}
	}				//
	return tab;
}

void delet(cell*** tab, int row)
{
	int i;
	for(i=0; i<row; i++)
	{
		free((*tab)[i]);
		(*tab)[i]=NULL;
	}
	free(*tab);
	(*tab)=NULL;
}

cell** resize(cell*** tab, int old_col, int old_row, int new_col, int new_row)
{
	int i,j;
	cell** new_tab=NULL;
	new_tab=create(new_col,new_row); //caly new_tab jest juz wypelniony zerami
	
	if(new_col>old_col && new_row>old_row)
	{
		for(i=0; i<old_row; i++)
		{
			for(j=0; j<old_col; j++)
			{
				new_tab[i][j].status=(*tab)[i][j].status;
				new_tab[i][j].surround=(*tab)[i][j].surround;
			}
		}
	}
	
	if(new_col<old_col && new_row<old_row)
	{
		for(i=0; i<new_row; i++)
		{
			for(j=0; j<new_col; j++)
			{
				new_tab[i][j].status=(*tab)[i][j].status;
				new_tab[i][j].surround=(*tab)[i][j].surround;
			}
		}
	}				//
	
	if(new_col>old_col && new_row<old_row)
	{
		for(i=0; i<new_row; i++)
		{
			for(j=0; j<old_col; j++)
			{
				new_tab[i][j].status=(*tab)[i][j].status;
				new_tab[i][j].surround=(*tab)[i][j].surround;
			}
		}
	}
	
	if(new_col<old_col && new_row>old_row)
	{
		for(i=0; i<old_row; i++)
		{
			for(j=0; j<new_col; j++)
			{
				new_tab[i][j].status=(*tab)[i][j].status;
				new_tab[i][j].surround=(*tab)[i][j].surround;
			}
		}
	}
	
	delet(tab, old_row); //usuwam stara tablice
	return new_tab;
}



void insert(cell** tab, int col, int row, cell new_element)
{
	tab[row][col].status=new_element.status;
	tab[row][col].surround=new_element.surround;
}

int at(cell** tab, int col, int row)
{
	return tab[row][col].status;
}

void show_array(cell** tab, int col, int row)
{
	int i,j;
	if(tab==NULL)
	{
		printf("tablica nie istnieje");
	}
	else
	{
		for(i=0; i<row; i++)
		{
			for(j=0; j<col; j++)
			{
				if(tab[i][j].status)
				{
					printf("%2c", 'O');
				}
				else
				{
					printf("%2c", '.');
				}
			}
			printf("\n");
		}
	}
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
