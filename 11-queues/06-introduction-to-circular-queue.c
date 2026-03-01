/*
 Title: Circular Queue
 Author: Inam Ul Haq

 Description:
	The main problem with a linear queue arises after deleting elements. Instead of
	shifting the remaining elements backward (which would require O(n) time), the
	queue implementation moves the front and rear pointers forward so that
	enqueue and dequeue operations can be performed in constant time.

	However, this approach creates unused space at the beginning of the array.
	When elements are dequeued, the front pointer moves forward, leaving vacant
	positions behind it. These free positions cannot be reused because both
	pointers move only in one direction.

	For example, consider a linear queue of size 10. Initially, the queue is full,
	with front at index 0 and rear at index 9. If we dequeue 5 elements, the
	front pointer moves to index 5, creating 5 empty positions at the beginning
	of the queue. Even though space is available, new elements cannot be enqueued
	because the rear pointer is already at the last index and cannot move
	forward. This situation is known as false overflow.

	The correct solution is to reuse the free space created at the beginning of the
	array by treating the queue as circular. When the rear pointer reaches the
	last position and there is available space before the front pointer, it
	wraps around to the beginning of the array. This circular movement of pointers
	eliminates false overflow and allows efficient use of memory. This structure
	is known as a Circular Queue.
*/
