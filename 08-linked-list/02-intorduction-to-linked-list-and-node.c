// Titile: Linked List
// Author: Inam Ul Haq
// Description:
//	1) What is link list:
//		Link list in the collection of nodes where each node contain
//		on data and pointer to the next node. And there is a speical 
//		pointer pointing to first node called first or Head.
//		Nodes are store in memory unlike array, it's not side by side
//		mean not contiguasly in memory.Then how it maintain the 
//		conteity? thorugh links that is addresses. So this is how the
//		link list is working.
//	2) How to define a node:
//		for defining node we have to define two things:
//			a) Data
//				data can be of any type, it may be int, float, char or
//				may be of user data type like structure or class.
//			b) Pointer
//				pointer is pointing to the next node so that's why we the node
//				and pointer type is same. usually we create the pointer of 
//				the node to which the pointer pointing. Therefor we say that
//				the class or structure is self-referential structure or
//				self-referential class.
//			c) size of node:
//				The size of node is equal to the total size of members
//				in the node. i.e if data is of integer type which take 
//				4 bytes and pointer also take 4 bytes then the size of
//				node will be 8.
				
				
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
int main(){
	struct Node *n1=malloc(sizeof(struct Node));
	n1->data=10;
	struct Node *n2=malloc(sizeof(struct Node));
	n1->next=n2;
	printf("Data: %d \nNext: %p",n1->data,n1->next);
}
			