/*
 Title: More About Linked List
 Author: Inam Ul Haq
 Description:
    - q = p
      q receives the address stored in p, therefore both pointers point to
      the same node in memory.

    - q = p->next
      q receives the address of the next node of p, so q now points to the
      second node in the linked list.

    - p = p->next
      p moves forward to the next node and no longer points to the previous node.

    - if (p != NULL)
      checks whether p is pointing to some memory location and not to NULL.

    - if (p != 0)
      checks whether p is not equal to zero, which is equivalent to checking
      p against NULL.

    - if (p)
      checks whether p is non-zero; this is the shortest way to check if p
      is pointing to a valid node.

    - if (p->next == NULL)
      checks whether the current node is the last node of the linked list.

    - if (p == NULL)
      checks whether p is pointing to nothing (NULL pointer).

    - if (p == 0)
      checks whether p is equal to zero, which also represents NULL in C.

    - if (!p)
      checks whether p is NULL using logical NOT operator.
*/



#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

int main(){
	struct Node *p,*q,*ptr;
	p=malloc(sizeof(struct Node));
	
	p->data=20;
	p->next=NULL;
	
	ptr=malloc(sizeof(struct Node));
	ptr->data=40;
	ptr->next=NULL;
	p->next=ptr;
	ptr=NULL;
	
	q=p;	// on whatever the p is pointing q is also pointing on that now.
	printf("\nAfter q=p:\n");
	printf("\npointer p:\n");
	
	printf("p->data: %d\n",p->data);
	printf("p->next: %d\n",p->next->data);
	
	printf("\npointer q: \n");
	printf("q->data: %d\n",q->data);
	printf("q->next: %d\n",q->next->data);
	
	printf("\nAfter q=p->next: \n\n");
	q=p->next; // Now q is pointing on the next node of p;
	
	printf("\npointer p: \n");
	printf("p->data: %d\n",p->data);
	printf("p->next-data: %d\n",p->next->data);
	
	printf("\npointer q: \n");
	printf("q->data: %d\n",q->data);
	printf("q->next: %p\n",(void *)q->next);
	
	ptr=p;
	p=p->next;
	free(ptr);
	ptr=NULL;
	
	// Now p is pointing on the next node to p.
	
	printf("\nAfter p=p->next;\n");
	printf("p->data: %d\n",p->data);
	printf("p->next: %p\n",(void *)p->next);
	
	
	//i.e p is pointing to Nod. How to check that p is pointing on valid Node?
	if(p!=NULL);// return true;
	if(p!=0); 	// return true;
	if(p);		// return true;
	
	// to cheack weather the p->next is pointing to a valid node or NULL.
	if(p->next==NULL); //true if pointing to NULL or false if pointing to Node.

	
	// if p is pointing to NULL. How to check it.
	free(p);
	p=NULL;
	q=NULL;
	
	if(p==NULL);	// return true;
	if(p==0);		// return true;
	if(!p);			// return true;
	
	
	return 0;
}