/*
 Title: Remove Duplicates from Sorted Linked List
 Author: Inam Ul Haq

 Description:
    This program demonstrates how to remove duplicate elements
    from a sorted singly linked list using C.

    Each node of the linked list contains:
    - An integer data value
    - A pointer to the next node

    Since the linked list is sorted, duplicate values always
    appear consecutively. The program removes duplicates by
    comparing adjacent nodes only, without using extra memory.

 Working:
    1. The linked list is created by inserting nodes at the end.
    2. The list is displayed before removing duplicates.
    3. Two pointers are used:
       - One pointer points to the current node.
       - The second pointer points to the next node.
    4. If both nodes contain the same value, the duplicate node
       is removed and its memory is freed.
    5. If the values are different, the pointers move forward.
    6. The updated list (without duplicates)



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

void removeDuplicates(struct Node *head){
	if(head==NULL){
		printf("Linked list is empty");
		return;
	}
	struct Node *p=head;
	struct Node *q=head->next;
	while(q){
		if(p->data!=q->data){
			p=q;
			q=q->next;
		}else{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
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
    
    printf("Before removing the duplicates: ");
    display(head); // Display all the nodes of linked list.

	removeDuplicates(head);
	
	printf("\nAfter removing duplicates:  ");
	display(head);


    // Free allocated memory.
    freeNodes(head);
    head=last=NULL; // avoid pointer daingling.
    return 0;
}
