/*
 Title: Limitation of Array based Queue and Why to use Linked List 
		insted of Array.
 Author: Inam Ul Haq
 Description: 
	Imagine a queue like people waiting in line at an ice cream shop.
	1. Array based queue (your current code)
	   - Think of a row of chairs where people can sit.
	   - front is the spot just before the first person in line.
	   - rear is the spot where the last person is sitting.
	   - When someone comes (enqueue), they sit at the rear.
	   - When someone leaves (dequeue), the front moves forward.
	
	   Some problems with this:
	   - The number of chairs is fixed. If more people come than chairs, they cannot sit.
	   - In circular queues, we have to leave one chair empty to know if the queue is full or empty.
	   - Chairs are in a single row, so very long lines might not fit in memory.
	   - If we want a bigger queue, we have to create a new row of chairs and move everyone, which is not easy.
	
	2. Linked list queue
	   - Imagine people holding hands in a chain. Each person knows who comes next.
	   - front is the first person, rear is the last person.
	   - Adding a person (enqueue) is like letting someone hold the last person's hand.
	   - Removing a person (dequeue) is like the first person leaving the line. No one has to move or shift.
	
	   Why this is better:
	   - The line can grow or shrink naturally. We do not have a fixed limit.
	   - No space is wasted. Every person is in the line.
	   - People do not have to stand in a single row. They can be anywhere in memory.
	   - Easy to manage and flexible if we do not know how many people will come.
	
	3. Summary
	   - Array queue is like a row of chairs. It is fast but limited in size.
	   - Linked list queue is like a chain of people holding hands. It can grow or shrink as needed.
*/
