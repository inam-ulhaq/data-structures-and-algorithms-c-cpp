/*
 Title: Height and Nodes Analysis of n-ary Trees
 Author: Inam Ul Haq
 Description:
	In an n-ary tree, each node can have at most n children.
	There is no restriction that a node must have exactly
	n children.

	Height Analysis

	Height is the number of edges on the longest path from
	the root node to any leaf node.

	When the total number of nodes is given:
	 Minimum height occurs when the tree is balanced.
	 Minimum height is approximately:
	     log base n of (total number of nodes) minus 1

	 Maximum height occurs when the tree is skewed.
	 Maximum height equals:
	     total number of nodes minus 1

	Nodes Analysis

	When the height is given:
	 Minimum number of nodes occurs when the tree is
	 completely skewed.
	 Minimum number of nodes equals:
	     height plus 1

	 Maximum number of nodes occurs when the tree is
	 perfectly balanced.
	 Maximum number of nodes equals:
	     1 + n + n squared + ... + n to the power height

	 This forms a geometric series.

	Maximum number of nodes formula:
	 (n to the power (height plus 1) minus 1) divided by (n minus 1)

	Basic Property

	Let:
	 total number of nodes
	 number of edges

	For any n-ary tree:
 number of edges equals total number of nodes-1
*/
