#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int size;
	int front;
	int rear;
	int *Q;
};

void enqueue(struct Queue *q,int value){
	if((q->rear+1)%q->size==q->front){ // if queue is full.
		printf("Queue overflow!\n");
		return;
	}
	
	q->rear=(q->rear+1)%q->size; // move rare 
	q->Q[q->rear]=value;
}

int dequeue(struct Queue *q){
	if(q->rear==q->front){
		printf("Queue is underflow!\n");
		return -1;
	}
	
	q->front=(q->front+1)%q->size; // move fornt pointer 
	return q->Q[q->front]; // return deleted element
}

int isEmpty(struct Queue q){
	if(q.front==q.rear)
		return 1;
	return 0;
}

int isFull(struct Queue q){
	if((q.rear+1)%q.size==q.front)
		return 1;
	return 0;
}

int first(struct Queue q){
	if(isEmpty(q))
		return -1;
	return q.Q[q.front+1];
}

int last(struct Queue q){
	if(isEmpty(q))
		return -1;
	return q.Q[q.rear];
}

void display(struct Queue q){
	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return;
	}
	
	while(q.front!=q.rear){
		q.front=(q.front+1)%q.size;
		printf("%d ",q.Q[q.front]);
	}
}

int create(struct Queue *q,int size){
	q->size=size;
	q->Q=malloc(q->size*sizeof(int));
	if(q->Q==NULL){
		printf("Memory allocation failed!\n");
		return 0;
	}
	q->front=q->rear=0;
	return 1;
}
int main(){
	struct Queue q;
	
	int size;
	printf("Enter size for queue: ");
	scanf("%d",&size);
	
	if(create(&q,size)){
		printf("Queue is created.\n");
	}
	
	printf("insert elements in queue.\n");
	for(int i=0;i<size-1;i++){
		int value;
		printf("Enter elements: ");
		scanf("%d",&value);
		enqueue(&q,value);
	}
	
	display(q);
	printf("\n");
	
	for(int i=0;i<size-1;i++){
		dequeue(&q);
	}
	
	display(q);
	printf("\n");
	
	for(int i=0;i<size-1;i++){
		int value;
		printf("Enter elements: ");
		scanf("%d",&value);
		enqueue(&q,value);
	}
	
	display(q);
	printf("\n");
	
	free(q.Q);
	return 0;
}