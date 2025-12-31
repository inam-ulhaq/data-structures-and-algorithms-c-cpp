// Title: Implimentation of Stack Using Array
// Author: Inam Ul Haq
// 
// Description:
//	For definition of stack we required data representation and the operations
//	on that data. So here we will implement the data representation of stack 
//	using array.
//	So for implementing a stack what are the things required when you are using 
//	an array.
//	
//	1) For storing data we need a fixed size array. What should be the data type 
//	   of this array dpend upon the data you store. i.e int, fload, char etc.
//	2) variable for storing the size of array, and size is integer type data so 
//	   it also must be integer i.e int.
//	3) Top pointer variable, that will poiting to the top element in the stack.
//	   The data type of this variable will be int because it will store the index of
//	   top element not the address.
//
//	In stack we can insert or delete element only form on side, but in array
//	we can do it form both i.e starting and ending sides. So we have to chose
//	one side only for insertion and deletion, but which? the one that take less
//	time among them. Let's analyise both of them.
//	
//	1) Starting side:
//		If we insert form starting side in the array then first we have to shift
//		all the elements before inserted to create a room for the new element 
//		which will take n unit and then we have to be insert the new element. So
//		due to the shifting of elements the time complexity will O(n).
//		Simllarly in deletion shfiting of elements is required to fill the blank 
//		room of deleted element so it's time complexity will be also O(n).
//		
//	2) Ending sid:
//		If we are insert form end side the array, first will access the index which
//		can be randomly done and that take constant time. After finding the index the 
//		room will be already vecant so we will directly insert the element which will 
//		take one unite of time. So the over all time complexity of the function will 
//		cosntant.
//		And same as the case for deletion we don't need any shifting just deleting the
//		element form spacific index. So the time complexity will of deletion will be also
//		constant.
//		
//	After proper Analysis we find a conclusion that inserting and deletion will be efficent
//	if we do it form end side because it's time complexity is constant. So we will delete 
//	and insert element only from end side of the array.
	
#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int size;  // to store the size of stack.
	int *s;	   // pointer to dynamically declare array in heap.
	int  top;  // variable for storing the index of top element.
};


int main(){
	struct Stack stk; // declaring struct stack type variable.
	
	printf("Enter size of stack: ");
	scanf("%d",&stk.size); // taking size form user.
	
	stk.s=malloc(stk.size*sizeof(int)); // allocating memory dynamically in heap.
	stk.top= -1; // setting top to -1, invalid mean just before the 0 index due empty stack.
	
	return 0;
}