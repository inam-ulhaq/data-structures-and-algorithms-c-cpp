// Title: Traversing the LinkedList Using Recursion
// Author: Inam Ul Haq
// Description: 
//	By traversing the linked list using recursion we mean
//	visiting all the elements of the linked list with the help of 
//	recursion instead of using loops.
//
//	In recursion, the function keeps calling itself again and again,
//	each time moving the pointer to the next node.
//	i.e. display(ptr->next);
//
//	Each recursive call will handle one node — it will display the
//	current node’s data, then call itself for the next node.
//	This process will continue until the pointer becomes NULL,
//	which means we have reached the end of the linked list.
//
//	So basically, recursion does the same work as a loop,
//	but it uses function calls instead of iteration.
//	Example below: displaying all the elements of the linked list 
//	using recursion.
// 
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

void reverseRec(struct Node* first){
	
	if(first!=NULL){
		reverseRec(first->next);
		printf(" <-%d",first->data);
	}else{
		printf("NULL");
	}
}

void  displayRec(struct Node* first){
	
	if(first!=NULL){
		printf("%d -> ",first->data);
		displayRec(first->next);
	}else
		printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* first,int value){
	struct Node* newNode= malloc(sizeof(struct Node));
	initNode(newNode,value);
	newNode->next=first;
	return newNode;
}

void freeNodes(struct Node* head){
	if(head==NULL){
		return;
	}else{
		freeNodes(head->next);
		free(head);
	}
}

int main(){
	struct Node* head=NULL;
	for(int i=0;i<10;i++)
		head=insertAtBeginning(head,i);
		
	displayRec(head);
	reverseRec(head);
	
	freeNodes(head);
	
	return 0;
}

//--------------------------------------
// Time Complexity Explanation
//--------------------------------------
//
// Let T(n) = total time taken by displayRec() 
//            to display n nodes.
//
// Case (a): When pointer is not NULL (i.e. node exists)
// ------------------------------------------------------
//	if(first != nullptr)        -> takes 1 unit of time
//	printf("%d -> ",first->data)-> takes 1 unit of time
//	displayRec(first->next)     -> takes T(n-1) time
//
// So total work done for this case = 1 + 1 + T(n-1)
// Hence,  T(n) = T(n-1) + 2
//
// Case (b): When pointer becomes NULL (Base Case)
// ------------------------------------------------
//	else 
//	printf("NULL")      -> takes 1 unit of time
//  return; 			-> takes 1 unite of time
//
// So total = 1 + 1 = 2 units
//
//--------------------------------------
// Combine both cases together:
//
//	For n nodes, the function will call itself n times
//	and in each call it performs 2 constant-time operations.
//
// So we can write:
//
//	T(n) = T(n-1) + 2
// 
//
// Expanding this:
//	T(n) = T(n-1) + 2      where T(n-1) = T(n-2) + 3

//	T(n) = (T(n-2) + 2) + 2
//	     = (T(n-3) + 2) + 2 + 2
//	     = ...
//	     = T(0) + 2n
//
// Since constants don’t matter in Big-O notation:
//
//	T(n) = O(n)
//
//--------------------------------------
// Therefore:
//	Time Complexity = O(n)
//	Because each node is visited exactly once.
//
//--------------------------------------
// Space Complexity
//--------------------------------------
//	In recursion, each function call is stored in the stack.
//	For n nodes → n recursive calls → stack depth = n.
//
//	So Space Complexity = O(n)
//
