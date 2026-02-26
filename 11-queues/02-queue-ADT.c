/*
 Title: Queue ADT
 Author: Inam Ul Haq
 Description:
	Queue ADT defines a queue and its operations based on FIFO order, 
	without implementation details.
	a) Data Representation:
		1) Space for storing elements.
		2) front pointer for deletion of elements at front.
		3) rear pointer for insertion of elements at last.
		
	b) Operations
		1) enqueue:
			enqueue mean inserting an element in queue. This insert elemnet in rear
			end(last), i.e. a person want to stand in line, he must to stand in the last.
		
		2) dequeue:
			dequeue mean deleting element from the queue. Deleting is done from the 
			fornt end of the queue, i.e if a person's work completed and he want to 
			left the line, he must be the first one in the line.
		
		3) isEmpty:
			checking weather the queue is empty or not.
		
		4) isFull
			checking weather the queue is full or not.
		
		5) first:
			knowing element at the front in queue.
		
		6) last:
			knowing element at the last in queue.
	
	Queue can be emplimented using two physical data structures:
		1) Array.
		2) Linked list.
*/