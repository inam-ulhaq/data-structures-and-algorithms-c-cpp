#include <stdio.h>
#include <stdlib.h>

struct Queue{
	
	int size;
	int front;
	int rear;
	int *Q;
	
};

void enqueue(struct Queue *q,int value){
	if(q->rear==q->size-1){
		printf("Queue overflow!\n");
		return;
	}
	q->rear++;
	q->Q[q->rear]=value;
}

int dequeue(struct Queue *q){

	if(q->front==q->rear){
		printf("Queue underflow!\n");
		return -1;
	}
	q->front++;
	return q->Q[q->front];
}

int isEmpty(struct Queue q){
	if(q.front==q.rear){
		return 1;
	}
	return 0;
}
int isFull(struct Queue q){
	if(q.rear==q.size-1){
		return 1;
	}
	return 0;
}

int first(struct Queue q){
	if(q.front==q.rear){
		printf("Queue is empty!\n");
		return -1;
	}
	return q.Q[q.front+1];
}

int last(struct Queue q){
	if(q.front==q.rear){
		printf("Queue is empty!\n");
		return -1;
	}
	return q.Q[q.rear];
}

void display(struct Queue q){
	if(q.front==q.rear){
		printf("Queue is empty!\n");
		return;
	}

	for(int i=q.front+1; i<=q.rear ;i++){

		printf("%d ",q.Q[i]);
	}
	printf("\n");
}

int main(){
	struct Queue q;
	printf("Enter Size of Queue: ");
	scanf("%d",&q.size);
	q.Q=malloc(q.size*sizeof(int));
	
	if(q.Q==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	q.front=q.rear=-1;
	
	printf("Inserting element to queue: \n");
	for(int i=0;i<q.size;i++){
		int value;
		printf("Enter value: ");
		scanf("%d",&value);
		enqueue(&q,value);
	}
	printf("Displaying element into queue: \n");
	display(q);
	
	printf("after deleting one element form queue.\n");
	dequeue(&q);
	display(q);
	
	free(q.Q);
	q.Q=NULL;
	return 0;
}