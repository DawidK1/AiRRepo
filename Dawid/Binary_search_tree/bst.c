#include "bst.h"


/////////////////////////////////////////////////////
void insert_node(node* root, node new_data)
{
    node* temp_root = root;
	int not_added = 1;

while(not_added)
    {


    if(strcoll(temp_root->l_name, new_data.l_name) > 0)
    {
        if(temp_root->left == NULL)
        {
            temp_root->left = (node*)malloc(sizeof(node));

            if(temp_root->left != NULL)
                *(temp_root->left) = new_data;
            not_added = 0;

        }
        else
        {
            temp_root = temp_root->left;
        }

    }
    else
    {
        if(temp_root->right == NULL)
        {
            temp_root->right = (node*)malloc(sizeof(node));

            if(temp_root->right != NULL)
                *(temp_root->right) = new_data;
            not_added = 0;

        }
        else
        {
            temp_root = temp_root->right;
        }

    }

}
}
//////////////////////////////////////////////

void print_tree(node* root)
{
if(root != NULL)
	
	{
	print_tree(root->left);

	print_node(root);

	print_tree(root->right);
	}

}
//////////////////////////////////////////////
void delete_tree(node* root)
{
if(root != NULL)
	{
	delete_tree(root->left);
	delete_tree(root->right);

	printf("\nDeleting %s...", root->l_name);
	free(root);
	
	}
}
/////////////////////////////////////////////////////

node* find_min(node* root)
{
if(root->left != NULL)
	return find_min(root->left);
else
	return root;
}
//////////////////////////////////////////////////////

node* find_max(node* root)

{
node* temp_root = root;

while(temp_root->right != NULL)
	temp_root = temp_root->right;

return temp_root;
}
//////////////////////////////////////////////////////

int count_nodes(node* root)
{
if(root != NULL)
	return 1 + count_nodes(root->left) + count_nodes(root->right);
else 
	return 0;
}
/////////////////////////////////////////////////////

int max(int a, int b)
{
if(a>b)
	return a;
else
	return b;
}

int count_height(node* root)
{
if(root!=NULL)
	return 1 + max(count_height(root->left),count_height(root->right));
else 
	return 0;
}
/////////////////////////////////////////////////////
node* find_node(node* root, char* key)
{
if(root != NULL)
	{
	if(strcoll(root->l_name, key) == 0)
		return root;


	if(strcoll(root->l_name, key) > 0)
		{
		return find_node(root->left, key);
		}
	else
		{
		return find_node(root->right, key);
		}
	}
else
	return NULL;

}
////////////////////////////////////////////////////
void print_node(node* root)
{

if(root != NULL)
	{
	printf("Nazwisko: %s", root->l_name);

	printf("\nImie: %s",root->f_name);

	printf("\nNumer telefonu: %d\n-----------------\n", root->number);
	}
else 
	printf("Nie znaleziono elementu!");
}
///////////////////////////////////////////////////








