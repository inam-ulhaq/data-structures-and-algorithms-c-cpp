/*
 Title: Introduction to Stack Data Structure
 Author: Inam Ul Haq

 Description:
	A stack is a collection of elements in which insertion and deletion are
	performed according to a specific discipline called **Last-In, First-Out (LIFO)**.
	This means that the element inserted last is the first one to be removed.

	In a stack, deletion can only be performed from the top. For example, if several
	elements are inserted into a stack, only the most recently inserted element can
	be deleted first.

	We use stack-like behavior in many real-life situations. Since we want to
	automate such tasks, we write programs that implement stacks so computers
	can perform these operations efficiently. Whenever an application requires
	LIFO behavior, a stack data structure is used.

 Example:
	Consider a can containing balls inserted in the following order:
	first green, then red, and finally yellow. The can allows insertion and
	removal from only one direction. If we remove a ball, which one will come out?
	The yellow ball, because it was inserted last. This behavior can be implemented
	using a stack data structure.
	
	Relationship Between Stack and Recursion:
	Recursion refers to functions that call themselves. Although recursion behaves
	like a loop, internally it uses a stack (called the system stack).
	
	Can recursion be converted into iteration? Yes.
	Can iteration be converted into recursion? Yes.

	It is known that every recursion can be converted into iteration. However,
	during this conversion, a stack is often required to store intermediate states.
	When recursion is used, the system stack is managed automatically by the compiler
	or runtime system, so the programmer does not need to handle it.

	When recursion is converted into iteration, the programmer must explicitly
	create and manage a stack (known as a programmer-defined stack). In such cases,
 stack data structures become essential.

 Note:
	Not all recursive functions require a stack when converted into iteration.
	Some recursive algorithms can be directly converted without using a stack.
*/
