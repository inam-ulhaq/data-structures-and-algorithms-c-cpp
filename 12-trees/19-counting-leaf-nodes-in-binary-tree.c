#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct treeNode{
	struct treeNode *lChild;
	int data;
	struct treeNode *rChild;
};

struct QueueNode{
	struct treeNode *data;
	struct QueueNode *next;
};

int isEmptyQueue(struct QueueNode *front){
	if(front==NULL){
		return 1;
	}
	return 0;
}

void enqueue(struct QueueNode **front,struct QueueNode **rear,struct treeNode *data){
	struct QueueNode *temp=malloc(sizeof(struct QueueNode));
	temp->data=data;
	temp->next=NULL;
	
	if(*front==NULL){
		*front=*rear=temp;
		return;
	}
	
	(*rear)->next=temp;
	*rear=temp;
}

struct treeNode* dequeue(struct QueueNode **front,struct QueueNode **rear){
	struct QueueNode *temp=*front;
	if(*front==NULL){
		return NULL;
	}
	*front=(*front)->next;
	if(*front==NULL){
		*rear=NULL;
	}
	struct treeNode *data=temp->data;
	free(temp);
	return data;
}

struct StackNode{
	struct treeNode *data;
	struct StackNode *next;
};

int isEmptyStack(struct StackNode *top){
	if(top==NULL){
		return 1;
	}
	return 0;
}

void push(struct StackNode **top,struct treeNode *data){
	struct StackNode *temp=malloc(sizeof(struct StackNode));
	temp->data=data;
	temp->next=NULL;
	if(*top==NULL){
		*top=temp;
		return;
	}
	temp->next=*top;
	*top=temp;
}

struct treeNode *pop(struct StackNode **top){
	struct StackNode *temp=*top;
	if(top==NULL){
		return NULL;
	}
	*top=temp->next;
	struct treeNode *data=temp->data;
	free(temp);
	return data;
}


void create(struct treeNode **root){
	int data;
	printf("Enter roote value: ");
	scanf("%d",&data);
	if(data==-1)
		return;
	struct treeNode *temp=malloc(sizeof(struct treeNode));
	temp->lChild=NULL;
	temp->rChild=NULL;
	temp->data=data;
	*root=temp;
	struct QueueNode *front=NULL,*rear=NULL;
	enqueue(&front,&rear,temp);
	
	while(!isEmptyQueue(front)){
		temp=dequeue(&front,&rear);
		printf("Enter value for lChild of %d :",temp->data);
		scanf("%d",&data);
		if(data!=-1){
			temp->lChild=malloc(sizeof(struct treeNode));
			temp->lChild->lChild=NULL;
			temp->lChild->data=data;
			temp->lChild->rChild=NULL;
			enqueue(&front,&rear,temp->lChild);
		}
		
		printf("Enter value for rChild of %d :",temp->data);
		scanf("%d",&data);
		if(data!=-1){
			temp->rChild=malloc(sizeof(struct treeNode));
			temp->rChild->lChild=NULL;
			temp->rChild->data=data;
			temp->rChild->rChild=NULL;
			enqueue(&front,&rear,temp->rChild);
		} 
	}
	
}

void preOrder(struct treeNode *root){
	if(root){
		printf("%d ",root->data);
		preOrder(root->lChild);
		preOrder(root->rChild);
	}
}
/*
int countLeafNodes(struct treeNode *root){
	if(root){
		if(root->lChild==NULL && root->rChild==NULL)
			return 1;
		return countLeafNodes(root->lChild)+countLeafNodes(root->rChild);
	}else
		return 0;
}
*/

int countLeafNodes(struct treeNode *root){
	int x,y;
	x=y=0;
	if(root){
		
		x=countLeafNodes(root->lChild);
		y=countLeafNodes(root->rChild);
		if(root->lChild==NULL && root->rChild==NULL)
			return x+y+1;
		else 
			return x+y;
		
	}else
	
		return 0;
}



int main(){
	struct treeNode *root=NULL;
	create(&root);
	printf("Leaf Nodes are: %d ",countLeafNodes(root));
	return 0;
}