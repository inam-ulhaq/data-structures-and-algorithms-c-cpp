/*
Title: Representation of Directed Graph (Concept + Steps)
Author: Inam Ul Haq

Description:

A directed graph (digraph) is a graph in which edges have direction.
If A -> B, it means there is a connection from A to B, but not
necessarily from B to A.

Example graph used:

    A -> B
    |    |
    v    v
    C -> D

Vertices: A, B, C, D
Edges: (A,B), (A,C), (B,D), (C,D)

============================================================
1. Adjacency Matrix
============================================================

Concept:
- Use a 2D array
- Rows represent source vertices
- Columns represent destination vertices
- Value = 1 if edge exists from row to column

------------------------------------------------------------

Step 1:
Write vertices as row and column labels

      A B C D

Step 2:
Initialize all values with 0

      A B C D
    ---------
A |  0 0 0 0
B |  0 0 0 0
C |  0 0 0 0
D |  0 0 0 0

Step 3:
Fill 1 where edge exists

(A,B) = 1
(A,C) = 1
(B,D) = 1
(C,D) = 1

Final Matrix:

      A B C D
    ---------
A |  0 1 1 0
B |  0 0 0 1
C |  0 0 0 1
D |  0 0 0 0

Explanation:
- Row = source, Column = destination
- Matrix is not symmetric (direction matters)
- Diagonal = 0 (no self-loop)

============================================================
2. Adjacency List
============================================================

Concept:
- Each vertex stores a list of vertices it points to
- Only outgoing edges are stored

------------------------------------------------------------

Step 1:
Create empty list for each vertex

A -> 
B -> 
C -> 
D -> 

Step 2:
Insert outgoing vertices

A -> B, C
B -> D
C -> D
D -> 

Explanation:
- Only outgoing edges stored
- Efficient for sparse graphs

============================================================
3. Compact List (Array Representation)
============================================================

Concept:
- Optimized array-based adjacency list
- Arrays used: vertex[], edge[], next[]
- vertex[] stores start index of each vertex in edge[]
- edge[] stores destination vertices
- next[] links next neighbor

------------------------------------------------------------

Step 1: Assign index to vertices

A=0, B=1, C=2, D=3

------------------------------------------------------------

Step 2: Store adjacency in edge[]

edge[] = B C D D

(Index:   0 1 2 3)

------------------------------------------------------------

Step 3: Link using next[]

next[] = 1 -1 3 -1

Explanation:
- next[i] points to next neighbor in edge[]
- -1 means end of list

------------------------------------------------------------

Step 4: vertex[] starting points

vertex[]:
A -> 0
B -> 2
C -> 3
D -> 4 (no neighbors)

------------------------------------------------------------

Traversal Example:

For A:
Start at vertex[A] = 0
edge[0] = B
next[0] = 1
edge[1] = C
next[1] = -1 (stop)

So A -> B, C

============================================================

Final Understanding:

Adjacency Matrix:
- Fast lookup, uses more space
- Row = source, Column = destination

Adjacency List:
- Stores only outgoing edges, space efficient

Compact List:
- Optimized array-based representation
- Good for large graphs

*/