/* 
 Title: Counting Nodes in Linked List
 Author: Inam Ul Haq

 Description:
    This program demonstrates how to count the number of nodes in a 
    singly linked list. To count the nodes, we traverse the linked list 
    starting from the head node and increment a counter for each node 
    encountered.

    The program performs the following operations:
    1. Creates a linked list by inserting nodes at the beginning.
    2. Accepts user input to populate the list.
    3. Traverses the list to count the total number of nodes.
    4. Displays the total count of nodes.
    5. Frees the allocated memory to avoid memory leaks.

    The traversal continues until the end of the list is reached 
    (i.e., when the next pointer becomes NULL).
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void initNode(struct Node *newNode,int value){
	newNode->data=value;
	newNode->next=NULL;
}

struct Node* insertAtBeginning(struct Node *head,int value){
	struct Node *newNode=malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	initNode(newNode,value);
	if(head!=NULL)
	newNode->next=head;
	return newNode;
}

int countNodes(struct Node *head){
	int counts=0;
	while(head!=NULL){
		counts++;
		head=head->next;
	}
	return counts;
}

void freeNodes(struct Node *head){
	if(head!=NULL){
		freeNodes(head->next);
		free(head);
	}
}
int main(){
	struct Node *head=NULL;
	printf("Enter data for nodes:\n");
	for(int i=0;i<10;i++){
		int value;
		printf("Enter value: ");
		scanf("%d",&value);
		head=insertAtBeginning(head,value);
	}
	
	int totalNodes=countNodes(head);
	printf("Total Nodes: %d\n",totalNodes);
	
	freeNodes(head);
	return 0;
}