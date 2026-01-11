// Title: Implementation of isEmpty() and isFull() Operations on Stack Using Array
// Author: Inam Ul Haq
//
// Description:
//	The isEmpty() operation is used to check whether the stack contains
//	any element or not. In an array-based stack, this condition depends
//	entirely on the value of the top variable.
//
//	When the stack is empty, the value of top is set to -1. This value
//	indicates that no valid index in the array is currently holding
//	any stack element.
//
//	So, if top is equal to -1, the stack is considered empty and
//	isEmpty() returns true (1). Otherwise, it returns false (0).
//
//	The isFull() operation is used to check whether the stack has reached
//	its maximum capacity. Since the stack is implemented using a fixed
//	size array, the last valid index is (size - 1).
//
//	If the value of top becomes equal to (size - 1), it means all
//	positions in the array are occupied and no more elements can be
//	inserted into the stack.
//
//	So, if top is equal to (size - 1), isFull() returns true (1).
//	Otherwise, it returns false (0).
//
//	Both isEmpty() and isFull() operations work in O(1) time complexity
//	because they perform only a single comparison.



	
#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int size;  // to store the size of stack.
	int *s;	   // pointer to dynamically declare array in heap.
	int  top;  // variable for storing the index of top element.
};

// passing value and stack by passing by address make changes in the orignal stack.
void push(struct Stack *stk,int value){ 

	if(stk->top==stk->size-1){ // check weather stack is full or not.
		printf("Stack overflow!\n"); // if full then stack overflow occurs.
		return; // terminate the function.
	}
	
	stk->top++; // increment to point on new empty index.
	stk->s[stk->top]=value; // inserting vlaue
}

int isEmpty(const struct Stack *stk){
	if(stk->top==-1){
		return 1;
	}else{
		return 0;
	}
}

int isFull(const struct Stack *stk){
	if(stk->top==stk->size-1){
		return 1;
	}else{
		return 0;
	}
}

int main(){

	struct Stack stk; // declaring struct stack type variable.
	
	printf("Enter size of stack: ");
	scanf("%d",&stk.size); // taking size form user.
	
	printf("Stack is created....\n\n");
	stk.s=malloc(stk.size*sizeof(int)); // allocating memory dynamically in heap.
	stk.top= -1; // setting top to -1, invalid mean just before the 0 index due empty stack.
	
	printf("Check the stack is empty or not?\n ");
	printf("Checking...\n");
	if(isEmpty(&stk)){
		printf("Stack is empty!\n\n");
	}else{
		printf("Stack is not empty!\n\n");
	}
	

	printf("Inserting elements to stack...\n");
	for(int i=0;i<stk.size;i++){
		int value;
		printf("Enter value to insert in stack: "); // ask for value to insert.
		scanf("%d",&value); // taking value.
		
		push(&stk,value); // calling push function to insert value print vlaue form stack to confrom weather inserted or not.

	}
	
	printf("\n");
	printf("Check the stack is full or not?\n");
	if(isFull(&stk)){
		printf("Stack is full!\n");
	}else{
		printf("Stack is not full!\n");
	}
	
	
	free(stk.s);
	stk.s=NULL;
	return 0;
}