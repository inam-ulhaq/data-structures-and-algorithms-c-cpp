/*
 Title: Circular Queue Using Array
 Author: Inam Ul Haq

 Description:
	In a circular queue implementation using an array, both front and rear
	initially start at index 0. The queue operations are similar to a linear
	queue, but the movement of pointers is handled differently to reuse space.

	For insertion, the rear pointer is first moved forward and then the new
	element is inserted at that position. Because of this approach, the very
	first position may appear vacant at the beginning. As insertions continue,
	the rear pointer eventually reaches the last position of the array. At
	this point, if the front pointer is still at index 0, the queue is said to
	be full.
	
	When elements are deleted, the front pointer moves forward. This creates
	vacant positions at the beginning of the array. Unlike a linear queue, these
	vacant positions can be reused in a circular queue. When the rear pointer
	reaches the end of the array and there is free space before the front
	pointer, the rear pointer moves back to the beginning of the array and
	continues inserting elements up to the position just before front.
	
	One important rule in a circular queue is that one position is always kept
	empty. This is done to clearly distinguish between the full and empty
	conditions. If rear becomes equal to front, the queue would appear empty,
	so insertion at the front position is avoided to prevent this ambiguity.

	Although the array itself is linear, it is treated as circular by allowing
	the front and rear pointers to move in a circular manner. This circular
	movement is achieved using the modulo operation. When a pointer reaches the
	last index and moves forward, it wraps around to index 0.

	For example, if the size of the queue is 5, the next position of a pointer is
	calculated as:
	(front + 1) % size

	front | (front+1)% size | index
	--------------------------------
		0 |  (0+1) % 5		| 1
	--------------------------------
		1 |  (1+1) % 5		| 2
	--------------------------------
		2 |  (2+1) % 5		| 3
	--------------------------------
		3 |  (3+1) % 5		| 4
	--------------------------------
		4 |  (4+1) % 5		| 0
	--------------------------------
		0 |  (0+1) % 5		| 1
	--------------------------------

	This causes the indices to repeat in a circular fashion (0 -> 1 -> 2 -> 3 -> 4 -> 0),
	thereby enabling circular movement of pointers. In this way, the circular
	queue efficiently reuses space and avoids the false overflow problem found in
	linear queue implementations.
*/

	

		
	