#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{

node data0 =  {
NULL, NULL, 6, "zzzz", "haa"
};
node data1 =  {
NULL, NULL, 1, "zzzjz", "jaa"
};
node data2 =  {
NULL, NULL, 2, "azzzz", "faa"
}
;node data3 =  {
NULL, NULL, 3, "bzzzz", "daa"
}
;node data4 =  {
NULL, NULL, 4, "czzzz", "baa"
}
;node data5 =  {
NULL, NULL, 5, "dzzzz", "Aaa"
}
;


node* root;

root = (node*)malloc(sizeof(node));

*root = data0;
insert_node(root, data1);
insert_node(root, data4);
insert_node(root, data2);
insert_node(root, data3);
insert_node(root, data5);
print_tree(root);

printf("MAX\n");
print_tree(find_max(root));
printf("MIN\n");
print_tree(find_min(root));

delete_tree(root);
root = NULL;

return 0;
}
