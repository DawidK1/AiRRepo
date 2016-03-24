#include "bst.h"


void insert(node* root, node new_data)
{
    node* temp_root = root;
int not_added = 1;

while(not_added)
    {


    if(strcoll(temp_root->l_name, new_data.l_name) <= 0)
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
