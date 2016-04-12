#include "biblio.h"

int main()
{

	node root={NULL, NULL, NULL, "Nowak", "Jan", 123};
	node new={NULL, NULL, NULL, "Piekarz", "Marek", 456};
	node new2={NULL, NULL, NULL, "Aaa", "Nie wiem jakie imie ..", 789};
	
	insert(&root, &new);
	insert(&root, &new2);
	in_order(&root);
	node* min=find_min(&root);
	
	int a=0;
	a=nodes(&root);
	printf("\nliczba wezlow: %d\n", a);
	
	node* szukany=find_key(&root, "Nowak");
	print_node(szukany);
	
	a=tree_height(&root);
	printf("\nwysokosc: %d\n", a);
	return 0;
	
	
}
