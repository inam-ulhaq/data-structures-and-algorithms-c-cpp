/*
 Title: Iterative Traversal of Binary Tree
 Author: Inam Ul Haq

 Description:
	In recursion, we can move forward and backward easily. 
	If we want to move forward, we simply call:
	   fun(ptr->left) or fun(ptr->right)

	And when we need to go backward, it happens automatically because 
	the address of the previous node is stored in the activation record 
	(function call stack). So recursion manages the return path for us.

	However, in the iterative approach, we can move forward easily using:
	    ptr = ptr->left  or  ptr = ptr->right

	But unlike recursion, we do not automatically have access to the 
	previous node’s address. Therefore, when we need to go backward, 
	we cannot do it directly.

	To solve this problem, we use a stack data structure to store 
	previous nodes manually, so we can return to them when needed.
*/



#include <stdio.h>
#include <stdlib.h>

struct treeNode{
	struct treeNode *lChild;
	struct treeNode *rChild;
	int data;
};

struct queueNode{
	struct treeNode **data;
	struct queueNode *next;
}*front=NULL,*rear=NULL;


void enqueue(struct treeNode *data){
	struct queueNode *newNode=malloc(sizeof(struct queueNode));
	if(!newNode){
		printf("memory allocation failed!\n");
		return;
	}
	
	newNode->data=data;
	
	if(front==NULL){
		front=rear=newNode;
		return;
	}
	rear->next=newNode;
	rear=rear->next;
}
struct treeNode* dequeue(){
	struct queueNode *temp=NULL;
	if(front!=NULL){
		temp=front;
		front=front->next;
	}
	return temp->data;
}
struct treeNode *root=NULL;
void create(){
	int userData;
	printf("Enter data for roote: ");
	scanf("%d",&userData);
	root=malloc(sizeof(struct treeNode));
	root->data=userData;
	root->lChild=NULL;
	root->rChild=NULL;
	enqueue(root);
	while(front!=NULL){
		struct treeNode *tempRoot=dequeue();
		printf("Enter data for lChild of %d",tempRoot->data);
		scanf("%d",&userData);
		if(userData!=-1){
			tempRoot->lChild=malloc(sizeof(struct treeNode));
			tempRoot->lChild->lChild=NULL;
			tempRoot->lChild->rChild=NULL;
			tempRoot->lChild->data=userData;
			enqueue(tempRoot->lChild);
		}
		printf("Enter data for rChild of %d",tempRoot->data);
		scanf("%d",&userData);
		if(userData!=-1){
			tempRoot->rChild=malloc(sizeof(struct treeNode));
			tempRoot->rChild->lChild=NULL;
			tempRoot->rChild->rChild=NULL;
			tempRoot->rChild->data=userData;
			enqueue(tempRoot->rChild);
		}
	}
	
}

void preOrder(struct treeNode *tempRoot){
	if(root){
		printf("%d ",tempRoot->data);
		preOrder(tempRoot->lChild);
		preOrder(tempRoot->rChild);
	}
}

int main(){
	create();
	preOrder(root);
}