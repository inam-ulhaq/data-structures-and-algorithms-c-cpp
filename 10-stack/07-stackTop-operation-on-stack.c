// Title: Implementation of StackTop() Operation on Stack Using Array
// Author: Inam Ul Haq
//
// Description:
//	The StackTop() operation is used to access the topmost element
//	of the stack without removing it.
//
//	Since the stack is implemented using an array, the index of the
//	topmost element is always stored in the variable 'top'.
//
//	If the stack is empty, the value of top is equal to -1. In this
//	case, there is no valid element present at the top of the stack
//	and StackTop() cannot return any value.
//
//	If the stack is not empty, the top element can be directly
//	accessed by using the index stored in top.
//
//	Value = s[top]
//
//	The StackTop() operation does not modify the stack and works in
//	O(1) time complexity because it performs a direct array access
//	at a fixed index.

	
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

int stackTop(const struct Stack *stk){
	if(stk->top==-1){
		printf("Stack is empty!\n");
		return -1;
	}
	
	return stk->s[stk->top];
}

int main(){

	struct Stack stk; // declaring struct stack type variable.
	
	printf("Enter size of stack: ");
	scanf("%d",&stk.size); // taking size form user.
	
	stk.s=malloc(stk.size*sizeof(int)); // allocating memory dynamically in heap.
	stk.top= -1; // setting top to -1, invalid mean just before the 0 index due empty stack.
	
	for(int i=0;i<stk.size;i++){
		int value;
		printf("Enter value to insert in stack: "); // ask for value to insert.
		scanf("%d",&value); // taking value.
		
		push(&stk,value); // calling push function to insert value print vlaue form stack to confrom weather inserted or not.

	}
	
	int result=stackTop(&stk);
	
	if(result!=-1){
		printf("Stack top element is : %d\n",result);
	}
	
	
	free(stk.s);
	stk.s=NULL;
	return 0;
}