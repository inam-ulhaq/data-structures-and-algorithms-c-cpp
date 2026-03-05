#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

void frontEnqueue(struct Node **front, struct Node **rear,int value){
	struct Node *temp=malloc(sizeof(struct Node));
	if(!temp){
		printf("Memory failed!\n");
		return;
	}
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;

	
	if(*front==NULL){
		*front=*rear=temp;
		return;
	}
	
	temp->next=*front;
	(*front)->prev=temp;
	*front=temp;
}

void rearEnqueue(struct Node **front,struct Node **rear,int value){
	struct Node *temp=malloc(sizeof(struct Node));
	if(!temp){
		printf("Memory allocation failed!\n");
		return;
	}
	temp->data=value;
	temp->prev=NULL;
	temp->next=NULL;
	
	if(*front==NULL){
		*front=*rear=temp;
		return;
	}
	
	temp->prev=*rear;
	(*rear)->next=temp;
	*rear=(*rear)->next;
}

void display(struct Node *front){
	if(front==NULL){
		printf("Queue is empty!\n");
		return;
	}
	
	while(front!=NULL){
		printf("%d ",front->data);
		front=front->next;
	}
	
}

int frontDequeue(struct Node **front,struct Node **rear){
	if(*front==NULL){
		printf("Queue underflow!\n");
		return -1;
	}
	
	int x=(*front)->data;
	struct Node *temp=*front;
	*front=(*front)->next;
	
	if(*front==NULL)
		*rear=NULL;
	else
		(*front)->prev=NULL;
	
	
	free(temp);
	return x;
}

int rearDequeue(struct Node **front,struct Node **rear){
	if(*rear==NULL){
		printf("Queue is empty!\n");
		return -1;
	}
	
	struct Node *temp=*rear;
	int x=temp->data;
	if(*rear!=*front){
		*rear=(*rear)->prev;
		(*rear)->next=NULL;
	}else{
		*front=*rear=NULL;
	}
	
	free(temp);
	return x;
}

int isEmpty(struct Node *front){
	if(front==NULL){
		return 1;
	}
	return 0;
}

int isFull(){
	struct Node *temp=malloc(sizeof(struct Node));
	if(!temp){
		return 1;
	}
	free(temp);
	return 0;
}

void freeQueue(struct Node **front,struct Node **rear){
	while(*front!=NULL){
		struct Node *temp=*front;
		*front=(*front)->next;	
		free(temp);
	}
	*front=*rear=NULL;
}

int main(){
	struct Node *front, *rear;
	front=rear=NULL;
	
	int size,value;
	printf("Enter how many value to be inserted: ");
	scanf("%d",&size);
	
	for(int i=0;i<size;i++){
		printf("Enter value: ");
		scanf("%d",&value);
	
		rearEnqueue(&front,&rear,value);
	}
	 
	display(front);
	printf("\n");
	
	int deleted=rearDequeue(&front,&rear);
	if(deleted!=-1)
		printf("%d is deleted!\n",deleted);
	
	display(front);
	printf("\n");
	
	freeQueue(&front,&rear);
	
	return 0;	
}