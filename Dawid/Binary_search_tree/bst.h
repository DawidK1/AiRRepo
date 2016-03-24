#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct node{
struct node* left;
struct node* right;

int number;

char f_name[30];
char l_name[30];
} node;

void insert_node(node* root, node new_data);


#endif // BST_H_INCLUDED