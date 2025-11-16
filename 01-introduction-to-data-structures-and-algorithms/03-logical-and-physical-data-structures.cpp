/*
 Title: Logical and Physical Data Structures
 Author: Inam Ul Haq
 Description:
    Logical Data Structure
        Definition:
            Conceptual way of organizing data and the relationships among data items.
            Focuses on how we think about or use the data (abstract view), not memory details.

        Types:
            1. Linear Data Structures:
                - Array: Elements in sequence [10, 20, 30]
                - Linked List: Elements connected via pointers
                - Stack: Last-In-First-Out (LIFO)
                - Queue: First-In-First-Out (FIFO)

            2. Non-Linear Data Structures:
                - Tree: Hierarchical structure, e.g., family tree
                - Graph: Networked relationships, e.g., social networks

        Key Idea:
            Answers "How is data related and organized?" without worrying about memory.


    Physical Data Structure
        Definition:
            Actual way data is stored in memory or on disk.
            Focuses on memory layout, pointers, contiguous/non-contiguous storage.

        Examples:
            - Array: Contiguous memory locations
            - Linked List: Nodes with data + pointer to next node
            - Stack: Implemented using Array or Linked List
            - Queue: Implemented using Array (circular) or Linked List
            - Tree: Nodes stored in memory with pointers
            - Graph: Stored as adjacency matrix or adjacency list

        Key Idea:
            Answers "How is this data actually stored and accessed in memory?"


    Relationship Between Logical & Physical:
        - One logical structure can have multiple physical implementations.
        - Example:
            Logical: Stack        -> Physical: Array or Linked List
            Logical: Queue        -> Physical: Array (circular) or Linked List
            Logical: Linked List  -> Physical: Nodes with pointers
            Logical: Tree         -> Physical: Nodes with pointers
            Logical: Graph        -> Physical: Adjacency matrix or adjacency list
*/
