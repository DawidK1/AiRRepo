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
	printf("\n\nmin: %s %s, tel: %d\n", min->nazwisko, min->imie, min->numer_telefonu);
	node* max=find_max(&root);
	printf("\n\nmax: %s %s, tel: %d\n", max->nazwisko, max->imie, max->numer_telefonu);
	
	int a=0;
	a=nodes(&root);
	printf("\nliczba wezlow: %d\n", a);
	
	node* szukany=find_key(&root, "Nowak");
	printf("\n\n szukany: %s %s, tel: %d\n", szukany->nazwisko, szukany->imie, szukany->numer_telefonu);
	
	
	return 0;
	
	
}
