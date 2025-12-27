/*
    Title : Reversing Linked List using Sliding Pointers
    Author : Inam Ul Haq
    Description :
        
*/


#include <stdio.h>
#include <stdlib.h>

/* Structure definition for a singly linked list node */
struct Node{
    int data;              // Stores data of the node
    struct Node *next;     // Pointer to the next node
};

/* Initializes a newly created node */
void initNode(struct Node *newNode, int value){
    newNode->data = value;
    newNode->next = NULL;
}

void insertAtLast(struct Node **head, struct Node **last, int value){
	
	struct Node *newNode=malloc(sizeof(struct Node)); // creating new node.
	if(!newNode){
		printf("Memory allocation failed!\n");
		return;
	}
	
	initNode(newNode,value); // intializing new node.
	
	if(*head==NULL){ // when linked is empty.
		*head=*last=newNode; // head and last pointing to the same node.
	}else{	// when linked list is not empty.
		(*last)->next=newNode; // Linke the new node in linked list.
		(*last)=newNode; // Update the last pointer.
	}
}

// Displaying all the nodes
void display(struct Node *head){
	while(head){
		printf("%d -> ",head->data);
		head=head->next;
	}
	printf("NULL");
}

/* Frees all nodes of the linked list */
void freeNodes(struct Node *head){
    if(head != NULL){
        freeNodes(head->next);
        free(head);
    }
}

void reverseLinkedList(struct Node **head){
	struct Node *r=NULL;
	struct Node *q=NULL;
	struct Node *p=*head;
	while(p){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	*head=q;
	
}

int main(){
    struct Node *head = NULL;
    struct Node *last = NULL;
    int size;

    // Read size of the linked list
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    // Insert elements into the linked list
    for(int i = 0; i < size; i++){
        int value;
        printf("Enter value for Node(%d): ", i + 1);
        scanf("%d", &value);
        insertAtLast(&head, &last, value); // Insert new node at last.
    }
    
    printf("Before reversing the linked list: ");
    display(head); // Display all the nodes of linked list.

	reverseLinkedList(&head);
	
	printf("\nAfter reversing linked list:  ");
	display(head);


    // Free allocated memory.
    freeNodes(head);
    head=last=NULL; // avoid pointer daingling.
    return 0;
}
