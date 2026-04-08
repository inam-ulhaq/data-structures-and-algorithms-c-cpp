/*
 Title: Tree Traversals
 Author: Inam Ul Haq
 Description:
	Tree traversal is the process of visiting all the nodes of a tree
	in a specific order. In binary trees, there are two main types of
	traversals: Depth-First Traversal (DFS) and Breadth-First Traversal (BFS).

	1) Depth-First Traversals (DFS):

		a) Inorder Traversal (Left -> Root -> Right):
		First, visit the left subtree
		Then, visit the root node
		Finally, visit the right subtree
		
		Example Tree:
		        1
		      /   \
		     2     3
		    / \   /
		   4   5 6
		
		Inorder Traversal Output:
		4 2 5 1 6 3
	
	b) Preorder Traversal (Root -> Left -> Right):
		First, visit the root node
		Then, visit the left subtree
		Finally, visit the right subtree

		Preorder Traversal Output:
		1 2 4 5 3 6

	c) Postorder Traversal (Left -> Right -> Root):
		First, visit the left subtree
		Then, visit the right subtree
		Finally, visit the root node

		Postorder Traversal Output:
		4 5 2 6 3 1

	2) Breadth-First Traversal (BFS):
	
	a) Level Order Traversal:
		Nodes are visited level by level
		From left to right at each level
		Usually implemented using a queue

		Level Order Traversal Output:
		1 2 3 4 5 6

	Summary:
		Inorder Traversal   : Left -> Root -> Right
		Preorder Traversal  : Root -> Left -> Right
		Postorder Traversal : Left -> Right -> Root
		Level Order         : Level by Level (Left to Right)
		
		Tree traversals are commonly used for searching, sorting,
		and processing hierarchical data structures.
*/
