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

printf("\n\nSpis:\n");
print_tree(root);

printf("MAX\n");
print_tree(find_max(root));
printf("MIN\n");
print_tree(find_min(root));

printf("Ile wezlow %d\n", count_nodes(root));

printf("Wysokosc drzewa: %d", count_height(root));


printf("Szukam elementu o nazwisku Aaa:\n");
print_node(find_node(root, "Aaa"));

printf("Szukam elementu o nazwisku Kowalski:\n");
print_node(find_node(root, "Kowalski"));

delete_tree(root);
root = NULL;

return 0;
}
