/*
 Title: Sum of Nodes Using Iteration
 Author: Inam Ul Haq

 Description:
	This program calculates the sum of all nodes in a singly linked list
	using an iterative approach. The list is traversed node by node until
	the pointer becomes NULL. Each node’s data is added to a sum variable.

 Time Complexity:
	The list is traversed once. If there are n nodes, the loop runs n times.
	Therefore, the time complexity is O(n).

 Space Complexity:
	The sum function uses a constant amount of extra memory.
	Hence, the space complexity is O(1).
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
		printf("Memory allocation failed!\n");
		exit(1);
	}
	initNode(newNode,value);
	if(head){
		newNode->next=head;
	}
	return newNode;
}

int nodesSum(struct Node *head){
	int sum=0;
	while(head){
		sum+=head->data;
		head=head->next;
	}
	return sum;
}
void freeNodes(struct Node *head){
	if(head){
		freeNodes(head->next);
		free(head);
	}
}
int main(){
	struct Node *head=NULL;
	for(int i=0;i<10;i++){
		int value;
		printf("Enter value: ");
		scanf("%d",&value);
		head=insertAtBeginning(head,value);
	}
	
	int sum=nodesSum(head);
	printf("Sum of Nodes: %d\n",sum);
	
	freeNodes(head);
	return 0;
}