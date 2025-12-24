/*
    Function Name : isSorted
    Author        : Inam Ul Haq
    Description   :
        Checks whether a singly linked list is sorted in ascending order.

        The function traverses the linked list from the head node and
        compares each node's data with its next node's data.

        - If the linked list is empty, it is considered not sorted.
        - If any node's data is greater than its next node's data,
          the list is not sorted.
        - If all nodes satisfy the ascending order, the list is sorted.

    Parameters    :
        head - Pointer to the head of the linked list

    Return Value  :
        1 - The linked list is sorted in ascending order
        0 - The linked list is not sorted or is empty

    Time Complexity  : O(n)
        - Each node is visited exactly once.
    Space Complexity : O(1)
        - No extra memory is used.
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

int isSorted(struct Node *head){
	if(head==NULL){
		printf("Linked list is empty!\n");
		return 0;
	}
	while(head->next!=NULL){
		if(head->data > head->next->data){
			return 0;
		}
		head=head->next;
	}
	return 1;
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
    
    display(head); // Display all the nodes of linked list.

	if(isSorted(head)){
		printf("\nLinked list is sorted.\n");
	}else{
		printf("\nLinked list is not sorted.\n");
	}


    // Free allocated memory.
    freeNodes(head);
    head=last=NULL; // avoid pointer daingling.
    return 0;
}
