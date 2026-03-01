/*
 Title: Problem of False Overflow in Linear Queue Implementation
 Author: Inam Ul Haq
 Description

	This queue is implemented using a linear array where the front and rear
	indices move only in the forward direction.

	When elements are dequeued, the front index increases, freeing space at the
	beginning of the array. However, this freed space is never reused because the
	rear index does not move backward.

	When rear reaches size-1, the queue reports an overflow condition even
	though empty positions may exist at the start of the array. This situation is
	known as FALSE OVERFLOW.

 Pointer Reset Approch:
	A common idea to solve false overflow is to reset front and rear back to
	their initial values (e.g., -1) when the queue becomes empty.

 Why Pointer Reset is Not a Proper Solution:
	- Pointer resetting works only when the queue is completely empty.
	- It does not solve false overflow when there are still elements in the queue.
	- Resetting pointers while elements exist would break FIFO order and may
	  overwrite valid data.
	- Therefore, pointer resetting is not a general or safe solution to the false
	  overflow problem.

 Conceptual Solution:
	The correct way to eliminate false overflow is to reuse freed space while
	elements still exist in the queue. This is achieved by treating the array as
	circular, known as a Circular Queue.
*/
