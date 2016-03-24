#include <stdio.h>
#include <stdlib.h>
#include "bst.c"

int main()
{

node data0 =  {
NULL, NULL, 1344, "zzzz"
};
node data1 =  {
NULL, NULL, 1344, "zzz1z"
};
node data2 =  {
NULL, NULL, 1344, "azzzz"
}
;node data3 =  {
NULL, NULL, 1344, "bzzzz"
}
;node data4 =  {
NULL, NULL, 1344, "czzzz"
}
;node data5 =  {
NULL, NULL, 1344, "dzzzz"
}
;
node* root;

root = (node*)malloc(sizeof(node));

insert_node(root, data1);
insert_node(root, data2);
insert_node(root, data3);
insert_node(root, data4);
printf("%s", root->l_name);





return 0;
}
