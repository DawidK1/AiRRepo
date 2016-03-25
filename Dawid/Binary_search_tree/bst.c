#include "bst.h"


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

	printf("%s", root->l_name);
	printf(" ");
	printf("%s",root->f_name);
	printf(" %d\n", root->number);

	print_tree(root->right);
	}

}
//////////////////////////////////////////////
void delete_tree(node* root)
{

//do napisania
;
}







