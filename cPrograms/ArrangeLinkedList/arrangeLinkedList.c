#include <stdio.h>
#include <stdlib.h>
#include "tera.h"
int main() {
	//code
	struct Node * head = NULL ;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	print(head);
	
        head = rearrange(&head);

        printf("\n");
        print(head);
	return 0;
}
