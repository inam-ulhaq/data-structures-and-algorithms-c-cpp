/*
 Title: Node
 Author: Inam Ul Haq
 Description: 
	Node:
		Node is a container that contain on data and pointer to next node.
		In data we store the actual value while in pointer pointing to next 
		node stores address of next node, it's acctually a link to the next node.
		the data type of data defend upon the data we store in the node, but the 
		data type of pointer to next node must be Node, becuase it pointing to 
		Node type varible. Is this possible to use Node type insde the Node structure? 
		Yes and that type of structure we called it as selfrencial structure.
	
	Where to Store Node:
		The property of node is it can be controlled durring run time i.e. we can 
		create and can delete a node manullay during run time of the program, So
		to gain such a quality we have to declare the node in heap through pointer.
		
	*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;			// variable to store data
	struct Node *next;	// pointer to store the address of next node
};


int main(){
	struct Node *ptr=malloc(sizeof(struct Node)); // node is dynamically create in heap

	ptr->data=10;	// accessing the varible of node
	ptr->next=NULL; // next not pointing anywhere
	
	printf("Data: %d\n",ptr->data);	//printing data from a node
	printf("Next: %p\n",(void *)ptr->next);	
	
	free(ptr);	// rleasing the memory
	return 0;
}