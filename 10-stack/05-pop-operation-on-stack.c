// Title: Implementation of pop() Operation on Stack Using Array
// Author: Inam Ul Haq
//
// Description:
//	The pop() operation is used to remove the top element from the stack.
//	In stack, deletion is allowed only from one end, which is called the
//	top of the stack.
//
//	While implementing pop() using an array, deletion is always performed
//	from the ending index of the array. This is because deletion from the
//	end does not require shifting of elements and therefore takes
//	constant time.
//
//	Before deleting an element, it is necessary to check whether the
//	stack is empty or not. This condition is checked by comparing the
//	value of top with -1.
//
//	If top is equal to -1, it means there is no element present in the
//	stack and stack underflow occurs.
//
//	If the stack is not empty, the element pointed by top is returned
//	and then the value of top is decremented to remove that element
//	from the stack.
//
//	The pop() operation works in O(1) time complexity because it
//	performs deletion at a fixed position without any shifting.

	
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


int pop(struct Stack *stk){
	if(stk->top==-1){
		printf("Stack underflow!\n");
		return-1;
	}
	return stk->s[stk->top--];
}

int main(){
	struct Stack stk; // declaring struct stack type variable.
	
	printf("Enter size of stack: ");
	scanf("%d",&stk.size); // taking size form user.
	
	stk.s=malloc(stk.size*sizeof(int)); // allocating memory dynamically in heap.
	stk.top= -1; // setting top to -1, invalid mean just before the 0 index due empty stack.
	
// pushing vlaues to stack.
	int value;
	printf("Enter value to insert in stack: "); // ask for value to insert.
	scanf("%d",&value); // taking value.
	
	push(&stk,value); // calling push function to insert value print vlaue form stack to confrom weather inserted or not.

	
// poping value from stak.	
	int deleted=pop(&stk);
	if(deleted!=-1){
		printf("%d is poped.\n",deleted);
	}
	 
	free(stk.s);
	stk.s=NULL;
	return 0;
}