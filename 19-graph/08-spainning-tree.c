/*
Title: Spanning Tree (Concept + Example)
Author: Inam Ul Haq

============================================================
Concept:
============================================================

A Spanning Tree is a subgraph of a graph that:

1. Includes all vertices
2. Is connected
3. Has no cycles

In simple words:
- It connects all vertices with minimum edges
- It removes extra edges (cycles)

------------------------------------------------------------

Important Formula:

For a graph with n vertices:
Number of edges in spanning tree = n - 1

============================================================
Example Graph:
============================================================

    A -- B
    |    |
    C -- D

Vertices: A, B, C, D
Edges: (A,B), (A,C), (B,D), (C,D)

Total edges = 4

------------------------------------------------------------

Step 1:
We need to include all vertices: A, B, C, D

------------------------------------------------------------

Step 2:
Select edges such that:
- No cycle is formed
- All vertices are connected

------------------------------------------------------------

Possible Spanning Tree 1:

    A -- B
    |
    C -- D

Edges used:
(A,B), (A,C), (C,D)

Number of edges = 3 (n-1 = 4-1 = 3)

------------------------------------------------------------

Possible Spanning Tree 2:

    A -- B
         |
    C -- D

Edges used:
(A,B), (B,D), (C,D)

------------------------------------------------------------

Possible Spanning Tree 3:

    A
    |
    C -- D
         |
         B

Edges used:
(A,C), (C,D), (D,B)

------------------------------------------------------------

Step 3: Verify Properties

- All vertices included: YES
- Connected: YES
- No cycle: YES
- Edges = n-1: YES

============================================================
Key Points:
============================================================

1. A graph can have multiple spanning trees
2. A spanning tree has no cycles
3. Removing any edge disconnects it
4. Adding any extra edge creates a cycle

============================================================
Relation with BFS and DFS:
============================================================

- BFS Tree: Spanning tree formed using BFS
- DFS Tree: Spanning tree formed using DFS

Example:

BFS starting from A:
Tree edges -> (A,B), (A,C), (B,D)

DFS starting from A:
Tree edges -> (A,B), (B,D), (D,C)

============================================================
Final Understanding:
============================================================

Spanning Tree = Minimum edges + All vertices + No cycle

*/