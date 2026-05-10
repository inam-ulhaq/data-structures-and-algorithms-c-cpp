/*
 Title: Graph Terminologies
 Author: Inam Ul Haq

 Description:
	
	1. Vertex (Node):
	A vertex is a point in a graph that represents an object.
	Example:
	A, B, C are vertices.

	2. Edge:
	An edge is a connection between two vertices.
	Example:
	(A, B) means A is connected to B.

	3. Adjacent Vertices:
	Two vertices are adjacent if they are directly connected by an edge.
	Example:
	(A, B) -> A and B are adjacent.

	4. Degree of a Vertex:
	Degree is the number of edges connected to a vertex.
	Example:
	A -- B -- C
	Degree of B = 2

	5. In-degree and Out-degree (Directed Graph):
	In-degree  = number of incoming edges
	Out-degree = number of outgoing edges
	Example:
	A -> B -> C
	For B: in-degree = 1, out-degree = 1

	6. Path:
	A path is a sequence of vertices connected by edges.
	Example:
	A -> B -> C -> D

	7. Cycle:
	A cycle is a path that starts and ends at the same vertex.
	Example:
	A -> B -> C -> A
	
	8. Connected Graph:
	A graph is connected if there is a path between every pair of vertices.
	Example:
	A -- B -- C

	9. Disconnected Graph:
	A graph is disconnected if some vertices are not reachable.
	Example:
	A -- B    C (C is disconnected)

	10. Weighted Graph:
	A graph in which edges have weights.
	Example:
	A --5-- B

	11. Unweighted Graph:
	A graph in which edges have no weights.
	Example:
	A -- B

	12. Simple Graph:
	A graph with no self-loops and no parallel edges.
	Example:
	A -- B

	13. Self Loop:
	An edge that connects a vertex to itself.
	Example:
	A -> A

	14. Parallel Edges:
	Multiple edges between the same pair of vertices.
	Example:
	A == B (two edges between A and B)

	15. Complete Graph:
	A graph in which every vertex is connected to every other vertex.
	Example:
	For vertices A, B, C:
	(A,B), (A,C), (B,C)
	Number of edges = n(n-1)/2
*/