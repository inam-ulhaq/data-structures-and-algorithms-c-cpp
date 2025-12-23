/*
 Title: Sum of Nodes Using Recursion
 Author: Inam Ul Haq

 Description:
	This program calculates the sum of all nodes in a singly linked list
	using a recursive approach. The linked list is traversed node by node
	by making recursive function calls until the pointer reaches NULL.
	Each recursive call adds the data of the current node to the sum
	returned by the next call.

 Working:
	- If the current node is not NULL, the function calls itself with the
	  next node and adds the current node's data.
	- If the pointer becomes NULL, the function returns 0 (base case).

 Time Complexity:
	The function visits each node exactly once.
	For n nodes, there will be n recursive calls.
	Therefore, the time complexity is O(n).

 Space Complexity:
	Due to recursion, each function call occupies stack space.
	For n nodes, n stack frames are created.
	Therefore, the space complexity is O(n).
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
	if(head){
		return nodesSum(head->next)+head->data;
	}else{
		return 0;
	}
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