/*
 Title: Implementation of pop() Operation on Stack Using Linked List
 Author: Inam Ul Haq
	
 Description:
	For definition of stack we required data representation and the operations
	on that data. So here we will implement the data representation of stack
	using linked list.
	So for implementing a stack what are the things required when you are using
	a linked list.
	
	1) Node structure:
		Each node contains two parts:
			a) Data part: to store the actual value (int, float, char, etc.)
			b) Link part: to store the address of the next node.
	
	2) Top pointer:
		A pointer variable that will point to the top node of the stack.
		The data type of this variable will be pointer to node.
	
		In stack we can insert or delete element only from one side, but in linked list
	we can perform insertion and deletion from both starting and ending sides.
	So we have to choose one side only for stack operations, but which one?
	The one that takes less time. Let's analyze both of them.
	
	1) Ending side (tail):
		If we insert an element at the end of the linked list, first we have to
		traverse the whole list to reach the last node, which takes O(n) time.
		After that we insert the new node.
		Similarly, for deletion from the end, traversal is required to reach the
		second last node, so the time complexity will also be O(n).
	
	2) Starting side (head):
		If we insert an element at the starting side of the linked list, we do not
		need any traversal. We simply create a new node and adjust the links.
		So insertion will take constant time O(1).
		Similarly, for deletion, we just move the top pointer to the next node,
		which also takes constant time O(1).

	After proper analysis we find a conclusion that insertion and deletion will be
	efficient if we do it from the starting side because its time complexity is
	constant.
	So in stack using linked list, we will perform push and pop operations
	only from the starting side of the linked list.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data; // to store data
	struct Node *next; // pointer pointing to next node
}; 

void display(const struct Node *top){
	if(top==NULL){
		printf("NULL\n");
		return;
	}
	
	while(top){
		printf("%d ",top->data);
		top=top->next;
	}
}

void push(struct Node **top,int x){
	
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("Stack overflow!\n");
		return;
	}
	
	temp->next=*top;
	temp->data=x;
	*top=temp;
}

int peek(struct Node *top,int pos){
	if(top==NULL){
		printf("Stack is empty!\n");
		return -1;
	}
	
	for(int i=0;top!=NULL && i<pos-1;i++){
		top=top->next;
	}
	if(top!=NULL)
		return top->data;
	printf("Invalid position!\n");
	return -1;
}

int main(){
	struct Node *top=NULL;
	
	int size;
	printf("Enter number of elements to insert: ");
	scanf("%d",&size);
	
	for(int i=0;i<size;i++){
		int value;
		printf("Enter value: ");
		scanf("%d",&value);
		push(&top,value);
	}
	
	printf("Display stack: ");
	display(top);
	printf("\n");
		
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	
	int peekElement=peek(top,pos);
	if(peekElement!=-1){
		printf("element at positon %d is: %d\n",pos,peekElement);
	}
	
	return 0;
}