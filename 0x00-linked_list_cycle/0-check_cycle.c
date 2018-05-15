#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int check_cycle(listint_t *list) {

	listint_t *walk = list;
	while (walk) {
		printf("-->: %d\n", walk->n);
		walk = walk->next;
	}
	return 0;
}
