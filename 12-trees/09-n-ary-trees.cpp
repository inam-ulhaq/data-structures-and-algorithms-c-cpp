/*
 Title: n-ary Trees 
 Author: Inam Ul Haq
 Description:
	An n-ary tree is a tree data structure where each node
	can have at most n children.
	Here, n is a fixed positive number (n >= 1).
	A node may have:
	 - no children (this is called a leaf), or
	 - one or more children, up to n
	There is no rule that a node must have exactly n children.
	Some nodes can have fewer children.
	Examples
	Binary tree (n = 2)
	Each node can have 0, 1, or 2 children.
	Ternary tree (n = 3)
	Each node can have 0, 1, 2, or 3 children.
	Quaternary tree (n = 4)
	Each node can have from 0 to 4 children.
	Structure Notes
	The tree starts from a root node.
	Children of a node are usually kept in order
	(first child, second child, and so on).
	Different branches of the tree may grow to
	different heights.
	Basic Property
	Let:
	 N = total number of nodes
	 E = number of edges
	In any n-ary tree:
	 E = N - 1
*/
