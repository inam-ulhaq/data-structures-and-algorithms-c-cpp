/*
    Title : insertAtSorted
    Author        : Inam Ul Haq
    Description   :
        Inserts a new node into a singly linked list in sorted order.
        The function traverses the list to find the correct position
        such that the list remains in ascending order.

        - If the linked list is empty, the new node becomes the head.
        - If the new node value is smaller than the head node,
          it is inserted at the beginning.
        - Otherwise, the new node is inserted between two nodes
          or at the end to maintain sorted order.

    Parameters    :
        head  - Double pointer to the head of the linked list
        value - Integer value to be stored in the new node

    Time Complexity  : O(n)
        - Must traverse the list to find the insertion point in the worst case.
    Space Complexity : O(1)
        - Only a single new node is allocated; no additional memory is used.
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

// Insert in sorted list.

void insertAtSorted(struct Node **head, int value){
	struct Node *newNode=malloc(sizeof(struct Node)); // Create new node.
	if(!newNode){ // Check memory allocation.
		printf("Memory allocation failed!\n");
		return; // If not allocated terminate the fucntion.
	}
	
	initNode(newNode, value);
	
	struct Node *p=*head; // pointer for traversing the linked list.
	struct Node *q=NULL; // pointer to follow the p pointer.
	if(p==NULL){ // If the linked list is empty.
		*head=newNode; // make the new node is head.
		return;
	}

	while(p){ // Traverse to find correct poistion to insert new node.
		if(p->data > newNode->data){ // the current targeted node data is grater than new node.
			if(q == NULL){ // And q is NULL mean the current node is first and insert before it.
				newNode->next=p; // Linking the new node.
				*head=newNode; // Updating the head pointer.
				return;
			}else{ // If the current node is not the first node.
				newNode->next=p; // Linking the new node.
				q->next=newNode; // Adjusting the new node.
				return;
			}
		}
		q=p; // Updating q pointer.
		p=p->next; // Move to next node.
	}
	q->next=newNode; // Insert at last.
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
        insertAtSorted(&head, value); // Insert new node at last.
    }
    
    display(head); // Display all the nodes of linked list.


    // Free allocated memory.
    freeNodes(head);
    head=NULL; // avoid pointer dangling.
    return 0;
}
