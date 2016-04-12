#include "biblio.h"

/* Funkcja strcoll zwraca: 
		zero, jezeli str1=str2
		liczbe mniejsza od zero <0 , jezeli str1<str2
		liczbe wieksza od zero >0 , jezelu str1>srt2
*/

void insert(node* root, node* new_node)
{
	node* temp=root;
	int not_success=1;
	
	while(not_success)
	{
		if(strcoll(temp->nazwisko, new_node->nazwisko)>0)
		{			
			if(temp->lewy_syn == NULL)
			{
				temp->lewy_syn=(node*)malloc(sizeof(node));
				if(temp->lewy_syn != NULL)
				{
					temp->lewy_syn=new_node;
					not_success=0;
					return;
				}
			}
			else
			{
				temp=temp->lewy_syn;
			}
		}
	
		if(strcoll(temp->nazwisko, new_node->nazwisko)<=0)
		{			
			if(temp->prawy_syn == NULL)
			{
				temp->prawy_syn=(node*)malloc(sizeof(node));
				if(temp->prawy_syn != NULL)
				{
					temp->prawy_syn=new_node;
					not_success=0;
					return;
				}
			}
			else
			{
				temp=temp->prawy_syn;
			}
		}
	}
}

void in_order(node* root)
{
	if(root!=NULL)
	{
		in_order(root->lewy_syn);
		printf("%s %s, tel: %d\n", root->nazwisko, root->imie, root->numer_telefonu);
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
	
	if(strcoll(temp->nazwisko, key)==0)
		return temp;

	if(strcoll(temp->nazwisko, key)>0)	
	{
		temp=temp->lewy_syn;
		return find_key(temp, key);		
	}
	
	if(strcoll(temp->nazwisko, key)<0)
	{
		temp=temp->prawy_syn;
		return find_key(temp, key);
	}
}















































