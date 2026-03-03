#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};


void enqueue(struct Node **front,struct Node **rear,int value){
	struct Node *temp=malloc(sizeof(struct Node));
	if(!temp){
		printf("Memory allocation failed!\n");
		return;
	}
	temp->data=value;
	temp->next=NULL;
	
	if(*front==NULL){
		*front=*rear=temp;
		return;
	}
	
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

int dequeue(struct Node **front,struct Node **rear){
	if(*front==NULL){
		printf("Queue underflow!\n");
		return -1;
	}
	
	int x=(*front)->data;
	struct Node *temp=*front;
	*front=(*front)->next;
	
	if(*front==NULL){
		*rear=NULL;
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
	
		enqueue(&front,&rear,value);
	}
	 
	display(front);
	printf("\n");
	
	int deleted=dequeue(&front,&rear);
	if(deleted!=-1)
		printf("%d is deleted!\n",deleted);
	
	display(front);
	printf("\n");
	
	freeQueue(&front,&rear);
	
	return 0;	
}