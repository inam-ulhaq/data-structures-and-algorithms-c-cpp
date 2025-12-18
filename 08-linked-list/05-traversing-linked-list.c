// Title: Traversing LinkedList
// Author: Inam Ul Haq
// Description:
//   Traversing means visiting all the nodes of a linked list 
//   one by one.
//
//   Assume that we have a pointer 'head' pointing to the first
//	 node in the linked list.This pointer gives us access to the
//	 first node, but we should never modify (or disturb) the 
//	'head' pointer directly, because if we lose it, we lose access
//	 to the entire list.Since a singly linked list cannot move 
//	backward, we must preserve 'head'.
//
//   To traverse, we take another pointer and place it at the 
//	start of the list.
//   Example:
//       struct Node* ptr = head;
//
//   Traversal means visiting each node in sequence. So we move 
//	'ptr' to the next node like:
//       ptr = ptr->next;
//
//   This statement makes 'ptr' jump to the next connected node.
//	 We keep repeating this until 'ptr' becomes NULL, which means
//	 we’ve reached the end of the list.
//
//   Example condition:
//       while (ptr != NULL)
//
//   During traversal, we can perform various operations such as:
//       1. Displaying all node data
//       2. Counting the number of nodes
//       3. Searching for a particular node
//       4. Sorting the list, and many more.
//
//   In summary, almost all operations on a linked list involve
//	 traversal.
//   Example below: displaying all elements of the list using
//	 traversal.

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void initNode(struct Node *node,int data){
	node->data=data;
	node->next=NULL;
}

void display(struct Node *Head){
	while(Head!=0){ // loop will continue till the Head == Null->last node next.
		printf("%d -> ",Head->data); // printing the actual value.
		Head=Head->next;	// moving to the next node
	}
	printf("NULL");
}
struct Node* insertAtBeginning(struct Node* Head,int value){
	struct Node *newNode=malloc(sizeof(struct Node)); // new Node is created
	initNode(newNode,value);	// intializing the new Node
	newNode->next=Head;	// inserting the newNode at the baginning of the linked list.
	return newNode;	// returning the updated linked list.
}
void reverse(struct Node* first){
	if(first!=NULL){
		reverse(first->next);
		printf("%d -> ",first->data);
	}

}

void freeNodes(struct Node *Head){
	if(Head==NULL){
		return;
	}else{
		freeNodes(Head->next);
		free(Head);
	}
}
int main(){
	struct Node* head=NULL;
	for(int i=0;i<10;i++)
		head=insertAtBeginning(head,i);
		
	printf("Display linked list: \n");
	display(head);
	
	printf("\nReversing linked list: \n");
	reverse(head);
	
	
	freeNodes(head);
	if(head){
		printf("\nHead not pointing to any Node.\n");
	}
	return 0;
}
	