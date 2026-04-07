/*
 Title: Relation Between Internal and External Nodes in Strict n-ary Trees
 Author: Inam Ul Haq
 Description:
	In a strict n-ary tree, each node has either exactly n
	children or no children at all.
	
	Internal node:
	 A node that has exactly n children.
	
	External node (leaf):
	 A node that has no children.
	
	Node Relation Analysis
	
	Let:
	 number of internal nodes
	 number of external (leaf) nodes
	
	Each internal node contributes exactly n children.
	The total number of children in the tree equals the
	total number of nodes - 1.
	
	From this property, a fixed relation exists between
	internal and external nodes.
	
	Relation
	
	 number of external nodes =
	 (n - 1) * number of internal nodes + 1
	
	Total Nodes
	
	 total number of nodes =
	 number of internal nodes + number of external nodes

	 total number of nodes =
	 n * number of internal nodes + 1

	Conclusion

	In a strict n-ary tree, the number of leaf nodes is
	always directly related to the number of internal
	nodes. This relation does not depend on the shape
	or height of the tree.
*/
