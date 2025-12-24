/*
    Title   : Insert a New Node at a Specified Position in a Singly Linked List.
    Author  : Inam Ul Haq

    Insert Function Description:
        The insert function is used to insert a new node at a specified
        position in a singly linked list. The position is zero-based,
        where position 0 represents insertion at the beginning of the list.

        The function first validates the given position by comparing it
        with the total number of nodes in the list. If the position is
        invalid, the insertion is aborted. If the position is valid, a
        new node is created and linked at the specified position by
        adjusting the pointers appropriately.

    Time Complexity:
        - Best Case: O(1)
          When the node is inserted at position 0 (beginning of the list).
        - Worst Case: O(n)
          When the node is inserted at the end or at the last position,
          requiring traversal of the list.
        - Average Case: O(n)

    Space Complexity:
        - Only one new node is created for insertion.
        - No additional data structures are used.
        - Therefore, the auxiliary space complexity is O(1).
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/* Frees all nodes of the linked list */
void freeNodes(struct Node *head){
    if(head != NULL){
        freeNodes(head->next);
        free(head);
    }
}

/* Inserts a new node at the end of the linked list */
void create(struct Node **head, int value){
    struct Node *newNode = malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    initNode(newNode, value);

    // If the list is empty, make new node the head
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *current = *head;
    while(current->next){
        current = current->next;
    }

    // Attach new node at the end
    current->next = newNode;
}

// Function to count number of nodes.
int count(struct Node *head){
	int count=0; // for counting nodes.
	while(head){
		count++; // Updating count.
		head=head->next; // Moving to next node.
	}
	return count; // return counts.
}

// Function to insert new node at a specific position.
void insert(struct Node **head,int value,int pos){
	// Valid if position is not less than 0 and not greater then total number of nodes.
	if(pos < 0 || pos > count(*head)){ 
		printf("Invalid position!\n");
		return; // if the position is not valid the function will abrobt.
	}
	struct Node *newNode=malloc(sizeof(struct Node)); // create new node.
	struct Node *temp=NULL; // Moving pointer
	initNode(newNode,value); // intailizing new node
	
	
	if(pos==0){ // if position is zero then insert at very start
		newNode->next=*head; // linking the new node to linked list.
		*head=newNode; // updating head pointer.
		return; // terminate the function.
	}else if(pos>0){ // if position is after any node.
		temp=*head; // set moving pointer
		for(int i=0;i<pos-1 && temp ;i++){ // move till the target position.
			temp=temp->next; // move to next node.
		}
		newNode->next=temp->next; // linking the new node.
		temp->next=newNode; // linking with new node.
	}
}


void display(struct Node *head){
	while(head){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}

int main(){
    struct Node *head = NULL;
    int size;

    // Read size of the linked list
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    // Insert elements into the linked list
    for(int i = 0; i < size; i++){
        int value;
        printf("Enter value for Node(%d): ", i + 1);
        scanf("%d", &value);
        create(&head, value);
    }
	display(head);
	
	insert(&head,3,0);
	insert(&head,9,2);
	insert(&head,5,5);
	display(head);

    // Free allocated memory
    freeNodes(head);
    return 0;
}
