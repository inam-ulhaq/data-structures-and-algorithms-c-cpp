/*
    Title   : Search in a Singly Linked List using Move-To-Front Heuristic
    Author  : Inam Ul Haq

    Description:
        This program implements a singly linked list and performs a search
        operation using the Move-To-Front (MTF) heuristic. Nodes are inserted
        at the end of the list, and when a key is found during the search,
        the corresponding node is moved to the front of the list to optimize
        future searches.

    Working:
        - Nodes are dynamically created and inserted at the end of the list.
        - The search operation traverses the linked list node by node.
        - Two pointers are used: one for the current node and one for the
          previous node.
        - When the key is found:
            * If the node is not already the head, it is detached from its
              current position.
            * The node is then moved to the front of the list.
        - If the key is not found, the search returns NULL.

    Time Complexity:
        In the worst case, the entire linked list is traversed.
        For n nodes, the time complexity is O(n).

    Space Complexity:
        No extra memory is used apart from a few pointer variables.
        Therefore, the space complexity is O(1).
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	int data;
	struct Node *next;
};

void initNode(struct Node *newNode,int value){
	newNode->data=value;
	newNode->next=NULL;
}

void insertAtLast(struct Node **head,int value){
	struct Node *newNode=malloc(sizeof(struct Node));
	if(!newNode){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	initNode(newNode,value);
	
	struct Node *current=*head;
	if(*head==NULL){
		*head=newNode;
		return;
	}
	
	while(current->next){
		current=current->next;
	}
	
	current->next=newNode;
}

struct Node* search(struct Node **head,int key){
	
	struct Node *p=*head;
	struct Node *q=NULL;
	
	while(p){
		printf("step...done!\n");
		if(key==p->data){
			if(q!=NULL){
				q->next=p->next;
				p->next=*head;
				*head=p;
			}
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

void freeNodes(struct Node *head){
	if(head!=NULL){
		freeNodes(head->next);
		free(head);
	}
}
int main(){
	struct Node *head=NULL;
	int size;
	printf("Enter size of linked list: ");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		int value;
		printf("Enter value for Node(%d): ",i+1);
		scanf("%d",&value);
		insertAtLast(&head,value);
	}
	int key;
	for(int i=0;i<2;i++){
		printf("Enter key: ");
	scanf("%d",&key);
	if(search(&head,key))
		printf("Key found!\n");
	else
		printf("Key not found!\n");
	}
	
	freeNodes(head);
	return 0;
}