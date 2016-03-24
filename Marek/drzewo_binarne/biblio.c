#include "biblio.h"


void insert(node* root, node* new_node)
{
	node* temp=root;
	
	if(strcoll(temp->nazwisko, new_node->nazwisko)>0)
	{
		temp->lewy_syn=(node*)malloc(sizeof(node));
		
		if(temp->lewy_syn != NULL)
		{
			temp->lewy_syn=new_node;
			return;
		}
	}
	
	if(strcoll(temp->nazwisko, new_node->nazwisko)<=0)
	{
		temp->prawy_syn=(node*)malloc(sizeof(node));
		
		if(temp->prawy_syn != NULL)
		{
			temp->prawy_syn=new_node;
			return;
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

//node* find_key(node* root, char* key)






























