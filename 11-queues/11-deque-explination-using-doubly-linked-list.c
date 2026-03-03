/*
 Title: Deque Implimentation using Doubly Linked List
 Author: Inam Ul Haq
 Description: 
    A deque (double-ended queue) is a linear data structure in which
    insertion and deletion operations can be performed at both
    the front and the rear ends.

    In this implementation, a doubly linked list is used.
    Each node contains three parts:
    1) data        -> stores the value
    2) prev pointer -> points to the previous node
    3) next pointer -> points to the next node

    Two pointers are maintained:
    front -> points to the first element of the deque
    rear  -> points to the last element of the deque

    When the deque is empty:
    front = NULL and rear = NULL

    Insertion at Front:
    - A new node is created.
    - If the deque is empty, the new node becomes both front and rear.
    - Otherwise, the new node is linked before the current front.
    - The front pointer is updated to the new node.

    Insertion at Rear:
    - A new node is created.
    - If the deque is empty, the new node becomes both front and rear.
    - Otherwise, the new node is linked after the current rear.
    - The rear pointer is updated to the new node.

    Deletion from Front:
    - First, check whether the deque is empty.
    - The front pointer is moved to the next node.
    - If the deque becomes empty after deletion, rear is set to NULL.
    - Otherwise, the previous pointer of the new front is set to NULL.

    Deletion from Rear:
    - First, check whether the deque is empty.
    - If more than one node exists, the rear pointer is moved
      to the previous node and its next pointer is set to NULL.
    - If only one node exists, both front and rear are set to NULL.

    Display Operation:
    - Traversal starts from the front pointer.
    - Each node is visited using the next pointer.
    - Elements are displayed from front to rear.

    Empty Condition:
    - The deque is empty if the front pointer is NULL.

    Full Condition:
    - Since a linked list uses dynamic memory allocation,
      the deque is considered full only when memory allocation fails.

	Freeing the DEQueue:
    - All nodes are deleted one by one from the front.
    - Memory is released properly to avoid memory leaks.
    - Both front and rear pointers are finally set to NULL.

    This implementation allows efficient insertion and deletion
    at both ends in constant time.
*/
