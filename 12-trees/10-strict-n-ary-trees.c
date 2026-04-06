/*
 Title: Strict n-ary Trees 
 Author: Inam Ul Haq
 Description:
	A strict n-ary tree is a tree data structure where each
	node has either exactly n children or no children at all.
	Here, n is a fixed positive number (n >= 1).
	A node may have:
	 - exactly n children (this is an internal node), or
	 - no children (this is a leaf)
	Nodes with fewer than n children are not allowed.
	Examples
	Strict binary tree (n = 2)
	Each node has either 2 children or 0 children.
	Strict ternary tree (n = 3)
	Each node has either 3 children or 0 children.
	Strict quaternary tree (n = 4)
	Each node has either 4 children or 0 children.
	Structure Notes
	The tree starts from a root node.
	All internal nodes have the same number of children.
	The tree may or may not be balanced.
	Basic Properties
	Let:
	 i = number of internal nodes
	 l = number of leaf nodes
	 N = total number of nodes
	Then:
	 l = (n - 1)i + 1
	 N = ni + 1
*/
