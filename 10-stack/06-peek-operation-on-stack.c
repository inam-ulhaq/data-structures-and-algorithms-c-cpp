// Title: Implementation of peek() Operation on Stack Using Array
// Author: Inam Ul Haq
//
// Description:
//	The peek() operation is used to access an element of the stack
//	without removing it. Unlike pop(), peek() only returns the value
//	present at a specific position in the stack.
//
//	In peek operation, the position is given from the top of the stack,
//	not from the starting index of the array. Therefore, we need a
//	formula to convert the given stack position into an array index.
//
//	Let the top of the stack be represented by the variable 'top'.
//	If we want to peek the element at position 'pos' from the top:
//
//	Position 1 ? top element
//	Position 2 ? element just below the top
//	Position 3 ? element below that, and so on
//
//	So, the array index corresponding to position 'pos' can be guessed
//	by subtracting (pos + 1) from the value of top.
//
//	Index = top - pos + 1
//
//	Before accessing the element, it is necessary to check whether
//	the calculated index is valid or not. If the index becomes negative,
//	it means the given position does not exist in the stack.
//
//	If the index is valid, the value stored at that index is returned
//	without modifying the stack.
//
//	The peek() operation works in O(1) time complexity because it
//	accesses a fixed index directly without any insertion or deletion.


	
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

int peek(const struct Stack *stk,int pos){
	int x=-1;
	int index=stk->top-pos+1;
	
	if(index<0 || index >stk->top){
		printf("Invalid index!\n");
		return x;
	}
	return stk->s[index];
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
	
	int pos;
	printf("Enter position to find the value: ");
	scanf("%d",&pos);
	
	int result=peek(&stk,pos);
	
	if(result!=-1){
		printf("Value found is : %d\n",result);
	}
	
	
	free(stk.s);
	stk.s=NULL;
	return 0;
}