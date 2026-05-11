/*
Title: Complete Graph Representation (Undirected & Directed)
Author: Inam Ul Haq

Description:

This shows how to represent graphs in three ways:
1. Adjacency Matrix
2. Adjacency List
3. Compact List

We compare **undirected** and **directed graphs** side by side.

============================================================
Example Graphs
============================================================

1. Undirected Graph:

    A -- B
    |    |
    C -- D

Vertices: A, B, C, D
Edges: (A,B), (A,C), (B,D), (C,D)

2. Directed Graph:

    A -> B
    |    |
    v    v
    C -> D

Vertices: A, B, C, D
Edges: (A,B), (A,C), (B,D), (C,D)

============================================================
1. Adjacency Matrix
============================================================

Undirected Graph:

      A B C D
    ---------
A |  0 1 1 0
B |  1 0 0 1
C |  1 0 0 1
D |  0 1 1 0

Explanation:
- Symmetric matrix (undirected)
- 1 indicates connection
- Diagonal = 0 (no self-loop)

Directed Graph:

      A B C D
    ---------
A |  0 1 1 0
B |  0 0 0 1
C |  0 0 0 1
D |  0 0 0 0

Explanation:
- Row = source, Column = destination
- Not symmetric
- Diagonal = 0

============================================================
2. Adjacency List
============================================================

Undirected Graph:

A -> B, C
B -> A, D
C -> A, D
D -> B, C

Directed Graph:

A -> B, C
B -> D
C -> D
D -> 

Explanation:
- Undirected: neighbors stored both ways
- Directed: only outgoing edges stored

============================================================
3. Compact List (Array Representation)
============================================================

Undirected Graph:

vertex[] = [0, 2, 4, 6]
edge[]   = [B, C, A, D, A, D, B, C]
next[]   = [1, -1, 3, -1, 5, -1, 7, -1]

Traversal Example:
For A: vertex[A]=0 -> edge[0]=B -> next[0]=1 -> edge[1]=C -> next[1]=-1
A -> B, C

Directed Graph:

vertex[] = [0, 2, 3, 4]
edge[]   = [B, C, D, D]
next[]   = [1, -1, 3, -1]

Traversal Example:
For A: vertex[A]=0 -> edge[0]=B -> next[0]=1 -> edge[1]=C -> next[1]=-1
A -> B, C

Explanation:
- vertex[]: starting index in edge[]
- edge[]: stores adjacent vertices
- next[]: links to next neighbor
- -1 indicates end

============================================================
Final Comparison:
============================================================

1. Adjacency Matrix:
- Fast lookup
- Undirected symmetric, Directed asymmetric
- Space = n*n

2. Adjacency List:
- Stores only neighbors
- Space efficient
- Traversal slower than matrix for lookup

3. Compact List:
- Array-based adjacency list
- Optimized memory
- Good for large graphs

*/