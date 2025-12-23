/*
    Title   : Search an Element in a Singly Linked List
    Author  : Inam Ul Haq

    Description:
        This program creates a singly linked list and searches for a given
        key using a simple linear search technique. Nodes are inserted at
        the end of the list, and the search operation checks each node
        sequentially until the key is found or the list ends.

    Working:
        - Nodes are dynamically allocated and inserted at the end of the list.
        - The search function starts from the head node.
        - Each node's data is compared with the given key.
        - If a match is found, the function returns 1.
        - If the entire list is traversed without finding the key,
          the function returns 0.

    Time Complexity:
        In the worst case, the linked list is traversed completely.
        For n nodes, the time complexity is O(n).

    Space Complexity:
        No additional data structures are used during the search.
        Only a few pointer variables are required.
        Therefore, the space complexity is O(1).
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	int data;
	struct Node *next;
};

void initNode(struct Node *newNode,int value){
	newNode->data=value;
	newNode->next=NULL;
}

void insertAtLast(struct Node **head,int value){
	struct Node *newNode=malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	initNode(newNode,value);
	
	struct Node *current=*head;
	if(*head==NULL){
		*head=newNode;
		return;
	}
	
	while(current->next){
		current=current->next;
	}
	
	current->next=newNode;
}

struct Node* search(struct Node *head,int key){
	while(head){
		if(key==head->data)
			return head;
		head=head->next;
	}
	return 0;
}

void freeNodes(struct Node *head){
	if(head!=NULL){
		freeNodes(head->next);
		free(head);
	}
}
int main(){
	struct Node *head=NULL;
	int size;
	printf("Enter size of linked list: ");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		int value;
		printf("Enter value for Node(%d): ",i+1);
		scanf("%d",&value);
		insertAtLast(&head,value);
	}
	int key;
	printf("Enter key: ");
	scanf("%d",&key);
	if(search(head,key))
		printf("Key found!\n");
	else
		printf("Key not found!");
		
	freeNodes(head);
	return 0;
}