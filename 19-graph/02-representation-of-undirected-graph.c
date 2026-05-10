/*
 Title: Representation of Undirected Graph (Concept + Steps)
 Author: Inam Ul Haq
 Description:

	We represent an undirected graph in different ways depending on
	memory usage and efficiency.

	Example graph used:

	    1 -- 2
	    |    |
	    3 -- 4

	Vertices: 1, 2, 3, 4
	Edges: (1,2), (1,3), (2,4), (3,4)


	1. Adjacency Matrix

		Adjacency matrix is a 2D array where:
		- Rows and columns both represent vertices
		- The elements inside the matrix or 2D array represent the 
		  connection or edge between the the vertices i.e
		  if value = 1 then edge exists, otherwise for zero no link
		  exist between vertices.
		
		It directly shows whether two vertices are connected.
		
	Lets represent it step by step
		
	Step 1:
		Write vertices as row and column labels.
		
		    	1, 2, 3, 4
		      1
		      2
		      3
		      4
		
	Step 2:
		Initialize all values with 0.
		
		      1 2 3 4
		    ---------
		1 |  0 0 0 0
		2 |  0 0 0 0
		3 |  0 0 0 0
		4 |  0 0 0 0
		
	Step 3:
		Fill 1 where edge exists.

		(1,2) and (2,1) = 1
		(1,3) and (3,1) = 1
		(2,4) and (2,4) = 1
		(3,4) and (4,3) = 1

	Final Matrix:
		      1 2 3 4
		    ---------
		1 |  0 1 1 0
		2 |  1 0 0 1
		3 |  1 0 0 1
		4 |  0 1 1 0

	Explanation:
		- Symmetric matrix (undirected graph)
		- Diagonal = 0 (no self-loop)

============================================================
2. Adjacency List
============================================================

Concept:
Each vertex stores a list of its neighbors.
Instead of storing all possible connections, we only store
existing edges.

This saves memory.

------------------------------------------------------------

Step 1:
Create empty list for each vertex.

A -> 
B -> 
C -> 
D -> 

Step 2:
Insert adjacent vertices.

A -> B, C
B -> A, D
C -> A, D
D -> B, C

Explanation:
- Only actual edges are stored
- Efficient for sparse graphs

============================================================
3. Compact List (Array Representation)
============================================================

Concept:
Compact list is an optimized version of adjacency list.
Instead of using separate linked lists, we store everything
in arrays.

It uses:
- vertex[] : starting index of each vertex
- edge[]   : stores adjacent vertices
- next[]   : links to next element

This reduces pointer overhead and improves memory usage.

------------------------------------------------------------

Step 1: Assign index to vertices

A=0, B=1, C=2, D=3

------------------------------------------------------------

Step 2: Store adjacency in edge[]

edge[] = B C A D A D B C

(Index:   0 1 2 3 4 5 6 7)

------------------------------------------------------------

Step 3: Link using next[]

next[] = 1 -1 3 -1 5 -1 7 -1

Explanation:
- next[i] gives next neighbor index
- -1 means end of list

------------------------------------------------------------

Step 4: Define vertex[] starting points

vertex[]:
A -> 0
B -> 2
C -> 4
D -> 6

------------------------------------------------------------

Final Structure:

vertex[] = [0, 2, 4, 6]

edge[]   = [B, C, A, D, A, D, B, C]

next[]   = [1, -1, 3, -1, 5, -1, 7, -1]

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
- Simple but uses more space

Adjacency List:
- Saves space, widely used

Compact List:
- More optimized version of list using arrays

*/