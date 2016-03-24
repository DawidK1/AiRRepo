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
	printf("\n\n min: %s %s, tel: %d\n", min->nazwisko, min->imie, min->numer_telefonu);
	node* max=find_max(&root);
	printf("\n\n max: %s %s, tel: %d\n", max->nazwisko, max->imie, max->numer_telefonu);
	
}
