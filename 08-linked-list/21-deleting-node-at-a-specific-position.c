/*
    Title : deleteAtPosition
    Author: Inam Ul Haq
    Description: 
	Deletion of a Node at a Given Position.

    Deleting a node from a singly linked list is performed by modifying
    the links between nodes rather than shifting data values, since
    linked list nodes are stored in non-contiguous memory locations.

    The deletion process follows these steps:

    1. Validate the given position to ensure it lies within the
       valid range of the linked list. If the list is empty or the
       position is invalid, deletion cannot be performed.

    2. If the node to be deleted is the first node (position 0),
       update the head pointer to point to the next node and free
       the memory of the removed node.

    3. If the node to be deleted is at any other position, traverse
       the linked list while maintaining two pointers:
       - One pointer refers to the current node.
       - Another pointer refers to the previous node.

       Once the target node is reached, update the previous node's
       next pointer to bypass the target node.

    4. Free the memory allocated to the deleted node to prevent
       memory leaks.

    Key Points:
    - Only pointers are adjusted; no data shifting is involved.
    - Special handling is required when deleting the first node.
    - Proper memory deallocation is essential.
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

	while(p){ // Traverse to find correct position to insert new node.
		if(p->data > newNode->data){ // the current targeted node data is greater than new node.
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

int count(struct Node* head){
	int count=0;
	while(head){
		count++;
		head=head->next;
	}
	return count;
}

int deleteAtPosition(struct Node **head, int position){
	
	if(position<0 || position >=count(*head)){
		printf("Invalid position!\n");
		return -1;
	}
	
	int x=0;
	struct Node *p=*head;
	struct Node *q=NULL;
	
	if(position==0){
		
		*head=(*head)->next;
		x=p->data;
		free(p);
		
	}else{
		
		for(int i=0;i<position;i++){
			
			q=p;
			p=p->next;
		}
		
		q->next=p->next;
		x=p->data;
		free(p);
		
	}
	
	return x;
	
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
        printf("Enter value for Node(%d): ", i);
        scanf("%d", &value);
        insertAtSorted(&head, value); // Insert new node at last.
    }
    
    display(head);
    
    int pos;
    printf("\nEnter Position: ");
    scanf("%d",&pos);
    
    int deleted=deleteAtPosition(&head, pos);
    
    if(deleted!=-1){
    	printf("%d is deleted\n",deleted);
	}
	
	display(head);
	
    // Free allocated memory.
    freeNodes(head);
    head=NULL; // avoid pointer dangling.
    return 0;
}
