#ifndef BIBLIO
#define BIBLIO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node* ojciec;
	struct node* lewy_syn;
	struct node* prawy_syn;
	
	char nazwisko[30];
	char imie[30];
	int numer_telefonu;
}root;

void insert(node* root, node* new_node);
void in_order(node* root);
node* find_min(node* root);
node* find_max(node* root);
//node* find_key(node* root, char* key); // uznaje, ze kluczem jest nazwisko


#endif