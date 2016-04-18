#include "biblio.h"

int main()
{

	node new={NULL, NULL, NULL, "Nowak", "Jan", 123123458};
	node new1={NULL, NULL, NULL, "Placek", "Jacek", 456254651};
	node new2={NULL, NULL, NULL, "Drzewo", "Binarne", 789254659};
	node new3={NULL, NULL, NULL, "Nazwisko", "Imie", 456987752};
	node new4={NULL, NULL, NULL, "Kolejna", "Osoba", 125478965};
	
	node* root=(node*)malloc(sizeof(node));
	*root=new;
	insert(root, new1);
	insert(root, new2);
	insert(root, new3);
	insert(root, new4);
	
	printf("\nKsiazka telefoniczna:\n");
	in_order(root);
	
	printf("\n\nMinimum:");
	print_node(find_min(root));
	
	printf("\n\nMaksimum:");
	print_node(find_max(root));
	
	printf("\n\nLiczba wezlow: %d", nodes(root));
	
	printf("\n\nSzukam osoby o nazwisku Nowak:");
	print_node(find_key(root, "Nowak"));
	
	printf("\n\nSzukam osoby o nazwisku Jan:");
	print_node(find_key(root, "Jan"));
	
	printf("\n\nWysokosc drzewa: %d\n", tree_height(root));
	return 0;
	
	delete_tree(root);
}
