/*
 Title: Find Maximum Value in a Singly Linked List
 Author: Inam Ul Haq

 Description:
	This program finds the maximum value present in a singly linked list
	using an iterative approach. The list is traversed from the head node
	to the last node, and each node’s data is compared with the current
	maximum value.

 Working:
	- A variable maxValue is initialized with INT_MIN to handle negative values.
	- The linked list is traversed using a while loop.
	- For each node, the data value is compared with maxValue.
	- If the current node’s value is greater, maxValue is updated.
	- After traversing all nodes, the maximum value is returned.

 Time Complexity:
	The linked list is traversed once.
	For n nodes, the loop executes n times.
	Therefore, the time complexity is O(n).

 Space Complexity:
	Only a single variable is used to store the maximum value.
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

void initNodes(struct Node *head,int value){
	head->data=value;
	head->next=NULL;
}

struct Node* insertAtBeginning(struct Node *head,int value){
	struct Node *newNode=malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memroy allocation failed!\n");
		exit(1);
	}
	
	initNodes(newNode,value);
	
	if(head){
		newNode->next=head;
	}
	return newNode;
}

void freeNodes(struct Node *head){
	if(head){
		freeNodes(head->next);
		free(head);
	}
}

int findMax(struct Node *head){
	int maxValue=INT_MIN;
	while(head){
		if(head->data>maxValue)
			maxValue=head->data;
		head=head->next;
	}
	return maxValue;
}

int main(){
	struct Node *head=NULL;
	printf("Enter Nodes values: \n");
	for(int i=0;i<8;i++){
		int value;
		printf("Enter value for node(%d): ",i+1);
		scanf("%d",&value);
		head=insertAtBeginning(head,value);
	}
	int maxValue=findMax(head);
	printf("Maximume Value in linked list is: %d\n",maxValue);
	
	freeNodes(head);
	return 0;
}