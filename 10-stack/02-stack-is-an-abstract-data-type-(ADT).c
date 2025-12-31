/*
 Title: Stack Abstract Data Type(ADT)
 Author: Inam Ul Haq
 Description:
	Abstract data type to stack will contain the the data representation and
	operation on the stack. ADT just give the definition of stack in terms of 
	data representation and the operations.
 Representation:
	1-Data:
		a) We need a space for storing the elements.
		b) A top pointer pointing to the recently added element in the stack.
	
	2-Operation:
		Some operations are given bellow that can be performed on stack.
		1. push(value)
			Inserting element into stack.
		2. pop()
			deleting the to element form the stack.
		3. peak(index)
			Knowing element at a specific index. The values are arrange on the 
			bases of deletion not insertion. i.e the first value is the last inserted one.
		4. stackTop()
			Knowing what is the top most value in the stack.
		5. isEmpty()
			check if the stack is empty.
		6. isFull()
			check if the stack is full.
			
 Implementation:
	We know that a stack is the collection of elements that works on discpline called LIFO.
	So where do we store the collection of elements? In memory we are storing it, but there
	are two ways to store it.
	1) Storing using array.
	2) Storing using linked list
	
	These are the two physical data structure that we are using to store stack.
*/