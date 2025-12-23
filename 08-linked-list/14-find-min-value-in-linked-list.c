/*
 Title: Find Minimum Value in a Singly Linked List
 Author: Inam Ul Haq

 Description:
	This program finds the minimum value present in a singly linked list
	using an iterative approach. Nodes are inserted at the end of the list,
	and the list is traversed from the head node to the last node to
	determine the smallest value.

 Working:
	- A variable `minValue` is initialized with INT_MAX so that any value
	  in the linked list will be smaller than the initial value.
	- The linked list is traversed using a while loop.
	- For each node, the data value is compared with `minValue`.
	- If the current node’s value is smaller, `minValue` is updated.
	- After traversing all nodes, the minimum value is returned.

 Time Complexity:
	The linked list is traversed once.
	For n nodes, the loop executes n times.
	Therefore, the time complexity is O(n).

 Space Complexity:
	Only one extra variable is used to store the minimum value.
	No additional memory is allocated during traversal.
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

int	findMin(struct Node *head){
	int minValue=INT_MAX;
	while(head){
		if(minValue>head->data)
			minValue=head->data;
		head=head->next;
	}
	return minValue;
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
	
	int minValue=findMin(head);
	printf("Minimume value in linked list: %d\n",minValue);
	freeNodes(head);
	return 0;
}