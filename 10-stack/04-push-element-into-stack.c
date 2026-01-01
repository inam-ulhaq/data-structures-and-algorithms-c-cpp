// Title: Implementation of push() Operation on Stack Using Array
// Author: Inam Ul Haq
//
// Description:
//	The push() operation is used to insert a new element into the stack.
//	In stack, insertion is allowed only at one end, which is called the
//	top of the stack.
//
//	While implementing push() using an array, insertion is always done
//	at the ending index of the array. This is because insertion at the
//	end does not require shifting of elements and therefore takes
//	constant time.
//
//	Before inserting a new element, it is necessary to check whether
//	the stack is already full. This condition is checked by comparing
//	the value of top with (size - 1).
//
//	If top is equal to (size - 1), it means there is no vacant space
//	left in the array and stack overflow occurs.
//
//	If the stack is not full, the value of top is incremented by one
//	and the new element is stored at the index pointed by top.
//
//	The push() operation works in O(1) time complexity because it
//	performs insertion at a fixed position without any shifting.

	
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
int main(){

	struct Stack stk; // declaring struct stack type variable.
	
	printf("Enter size of stack: ");
	scanf("%d",&stk.size); // taking size form user.
	
	stk.s=malloc(stk.size*sizeof(int)); // allocating memory dynamically in heap.
	stk.top= -1; // setting top to -1, invalid mean just before the 0 index due empty stack.
	
	int value;
	printf("Enter value to insert in stack: "); // ask for value to insert.
	scanf("%d",&value); // taking value.
	
	push(&stk,value); // calling push function to insert value print vlaue form stack to confrom weather inserted or not.
	
	printf("New inserted value to stack is: %d\n",stk.s[stk.top]);
	
	
	free(stk.s);
	stk.s=NULL;
	return 0;
}