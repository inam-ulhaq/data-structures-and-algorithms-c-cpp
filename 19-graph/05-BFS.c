/*
Title: BFS (Breadth-First Search) - Undirected Graph
Author: Inam Ul Haq

Graph Used:

    A -- B
    |    |
    C -- D

Vertices: A, B, C, D
Edges: (A,B), (A,C), (B,D), (C,D)

============================================================
Concept:
============================================================

BFS is a graph traversal algorithm that explores vertices in **levels**:
1. Start from a source vertex
2. Visit all neighbors first
3. Use a **queue** to keep track of next vertices to visit
4. Mark visited vertices to avoid repetition

It is commonly used to find:
- Shortest path in unweighted graph
- Connected components

============================================================
Step-by-Step BFS Example (Start from A)
============================================================

Step 0: Initialize

- Queue: empty
- Visited: all false
- Start vertex: A

Queue: [A]
Visited: A=true, B=false, C=false, D=false

------------------------------------------------------------
Step 1: Dequeue A

- Current vertex = A
- Visit neighbors of A: B, C
- Add unvisited neighbors to queue

Queue: [B, C]
Visited: A=true, B=true, C=true, D=false

Visited order so far: A

------------------------------------------------------------
Step 2: Dequeue B

- Current vertex = B
- Visit neighbors of B: A, D
- A already visited -> skip
- D not visited -> enqueue

Queue: [C, D]
Visited: A=true, B=true, C=true, D=true

Visited order so far: A, B

------------------------------------------------------------
Step 3: Dequeue C

- Current vertex = C
- Visit neighbors of C: A, D
- Both already visited -> skip

Queue: [D]

Visited order so far: A, B, C

------------------------------------------------------------
Step 4: Dequeue D

- Current vertex = D
- Visit neighbors of D: B, C
- Both already visited -> skip

Queue: []

Visited order so far: A, B, C, D

------------------------------------------------------------
Step 5: Queue empty -> BFS Complete

============================================================
Final BFS Traversal Order:

A -> B -> C -> D

Explanation:
- BFS visits vertices level by level
- Queue ensures FIFO order
- No vertex is visited twice

============================================================
Notes:

- If starting from a different vertex (e.g., C), order may differ:
C -> A -> D -> B

- BFS can be implemented using:
1. Adjacency Matrix
2. Adjacency List
3. Compact List (array-based)

- Space Complexity:
O(V + E) for adjacency list
O(V^2) for adjacency matrix

- Time Complexity:
O(V + E) for adjacency list
O(V^2) for adjacency matrix

*/b