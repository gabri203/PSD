#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){

	Item item;
	int pos;
	List list=newList ();
	for (int i=0; i<5; i++){
		Item item = inputItem();
		addHead (list, item);
	}
	printList (list);
	printf("Inserisci la posizione dell'item da eliminare : ");
	scanf("%d",&pos);
	removeListPos(list,pos);
	printList (list);
	return 0;
}