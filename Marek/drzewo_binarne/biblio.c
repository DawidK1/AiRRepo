#include "biblio.h"

/* Funkcja strcoll zwraca: 
		zero, jezeli str1=str2
		liczbe mniejsza od zero <0 , jezeli str1<str2
		liczbe wieksza od zero >0 , jezelu str1>srt2
*/

void insert(node* root, node new_node)
{
	node* temp=root;
	int not_success=1;
	
	while(not_success)
	{
		if(strcoll(temp->nazwisko, new_node.nazwisko)>0)
		{			
			if(temp->lewy_syn == NULL)
			{
				temp->lewy_syn=(node*)malloc(sizeof(node));
				if(temp->lewy_syn != NULL)
					*(temp->lewy_syn)=new_node;
				not_success=0;
			}
			else
			{
				temp=temp->lewy_syn;
			}
		}
	
		if(strcoll(temp->nazwisko, new_node.nazwisko)<=0)
		{			
			if(temp->prawy_syn == NULL)
			{
				temp->prawy_syn=(node*)malloc(sizeof(node));
				if(temp->prawy_syn != NULL)
					*(temp->prawy_syn)=new_node;
				not_success=0;
			}
			else
			{
				temp=temp->prawy_syn;
			}
		}
	}
}

void print_node(node* root)
{
	if(root!=NULL)
	{
		printf("\n%s %s", root->nazwisko, root->imie);
		printf("	   %d", root->numer_telefonu);
	}
	else
		printf("\nBlad przy wypisaniu osoby, nie znaleziono rekordu.");
}

void in_order(node* root)
{
	if(root!=NULL)
	{
		in_order(root->lewy_syn);
		print_node(root);
		in_order(root->prawy_syn);
	}
}

node* find_min(node* root)
{
	
	if(root!=NULL)
	{
		if(root->lewy_syn==NULL)
			return root;
		else
			return find_min(root->lewy_syn);
	}
	else
		return NULL;
}

node* find_max(node* root)
{
	if(root!=NULL)
	{
		if(root->prawy_syn==NULL)
			return root;
		else
			return find_max(root->prawy_syn);
	}
	else
		return NULL;
}

int nodes(node* root)
{
	if(root!=NULL)
		return 1 + nodes(root->prawy_syn) + nodes(root->lewy_syn);
	else
		return 0;
}

node* find_key(node* root, char* key)
{
	node* temp=root;
	if(temp==NULL)
		return NULL;
	else
	{
		if(strcoll(temp->nazwisko, key)==0)
			return temp;

		if(strcoll(temp->nazwisko, key)>0)	
		{
			temp=temp->lewy_syn;
			return find_key(temp, key);		
		}
		else
		{
			temp=temp->prawy_syn;
			return find_key(temp, key);
		}
	}
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int tree_height(node* root)
{
	if(root!=NULL)
	{
		return 1 + max(tree_height(root->lewy_syn), tree_height(root->prawy_syn));
	}
	else
		return 0; 
}

void delete_tree(node* root)
{
	if(root != NULL)
	{
		delete_tree(root->lewy_syn);
		delete_tree(root->prawy_syn);
		free(root);
		root=NULL;
	}
}














































