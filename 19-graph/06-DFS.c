/*
 Title: DFS (Depth-First Search) - Undirected Graph
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
	
	DFS is a graph traversal algorithm that explores vertices **as deep as possible** along each branch before backtracking.
	
	Key points:
	1. Start from a source vertex
	2. Visit a neighbor recursively until no unvisited neighbor remains
	3. Backtrack to previous vertex and continue
	4. Can be implemented using **recursion** or **stack**
	
	DFS is used to:
	- Detect cycles
	- Find connected components
	- Topological sorting (for DAGs)
	
	============================================================
	Step-by-Step DFS Example (Start from A)
	============================================================
	
	Step 0: Initialize
	
	- Visited: all false
	- Start vertex: A
	- DFS uses stack (implicitly in recursion)
	
	Visited: A=false, B=false, C=false, D=false
	
	------------------------------------------------------------
	Step 1: Visit A
	
	- Mark A as visited
	Visited: A=true, B=false, C=false, D=false
	- Explore neighbors: B, C
	- First neighbor: B
	
	Visited order so far: A
	
	------------------------------------------------------------
	Step 2: Visit B
	
	- Mark B as visited
	Visited: A=true, B=true, C=false, D=false
	- Explore neighbors: A, D
	- A already visited -> skip
	- Next neighbor: D
	
	Visited order so far: A, B
	
	------------------------------------------------------------
	Step 3: Visit D
	
	- Mark D as visited
	Visited: A=true, B=true, C=false, D=true
	- Explore neighbors: B, C
	- B already visited -> skip
	- Next neighbor: C
	
	Visited order so far: A, B, D
	
	------------------------------------------------------------
	Step 4: Visit C
	
	- Mark C as visited
	Visited: A=true, B=true, C=true, D=true
	- Explore neighbors: A, D
	- Both already visited -> stop
	
	Visited order so far: A, B, D, C
	
	------------------------------------------------------------
	Step 5: Backtrack
	
	- No unvisited neighbors left
	- DFS complete
	
	============================================================
	Final DFS Traversal Order (using neighbor order A->B->D->C):
	
	A -> B -> D -> C
	
	Notes:
	- Different neighbor visiting order may produce different DFS paths
	- DFS can be implemented using:
	  1. Adjacency Matrix
	  2. Adjacency List
	  3. Compact List
	- Time Complexity:
	  O(V + E) for adjacency list
	  O(V^2) for adjacency matrix
	- Space Complexity:
	  O(V) recursion stack for DFS

*/