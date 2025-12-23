/*
 Title: Find Maximum Value in a Singly Linked List Using Recursion
 Author: Inam Ul Haq

 Description:
	This program finds the maximum value present in a singly linked list
	using a recursive approach. The function recursively traverses the list
	until the last node is reached and then compares values while returning
	back through the recursive calls.

 Working:
	- If the current node is not NULL, the function calls itself for the next node.
	- The recursive call returns the maximum value of the remaining list.
	- The current node’s data is compared with the returned value.
	- The larger value is returned.
	- If the pointer becomes NULL, a base value is returned.

 Time Complexity:
	Each node is visited exactly once.
	For n nodes, there are n recursive calls.
	Therefore, the time complexity is O(n).

 Space Complexity:
	Due to recursion, each function call uses stack memory.
	For n nodes, n stack frames are created.
	Therefore, the space complexity is O(n).
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
	if(head){
		int max=findMax(head->next);
		
		if(max>head->data){
			return max;
		}else{
			return head->data;
		}
	}else{
		return INT_MIN;
	}
}

int main(){
	int size;
	printf("Enter Number of nodes: ");
	scanf("%d",&size);
	struct Node *head=NULL;
	printf("Enter Nodes values: \n");
	for(int i=0;i<size;i++){
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