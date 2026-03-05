/*
 Title: Concept of Priority Queue
 Author: Inam Ul Haq
 Description:
    A priority queue is a special type of queue in which every
    element is assigned a priority.
    Unlike a simple queue, elements in a priority queue are
    removed according to priority, not according to the order
    in which they were inserted.

    An element with higher priority is served before an element
    with lower priority.
    If two elements have the same priority, they are processed
    in the order they entered the queue.

    Conceptual Types of Priority Queue

        1) Limited Priority Queue
           In a limited priority queue, the number of priority
           levels is fixed.
           Each priority level has its own queue, and elements
           are placed into these queues based on their priority.
           Higher priority queues are always checked first.
           This method is simple and efficient when priorities
           are known in advance.

           Real-life example:
           Task scheduling in an operating system where system
           tasks are processed before user tasks.

        2) Element Priority Queue
           In an element priority queue, each element carries
           its own priority value.
           There is no fixed number of priority levels, and
           priorities can vary freely.
           Elements are compared directly with each other.
           This method is more flexible than limited priority
           queues.

           Real-life example:
           Emergency room patients are treated based on the
           severity of their condition.
*/
