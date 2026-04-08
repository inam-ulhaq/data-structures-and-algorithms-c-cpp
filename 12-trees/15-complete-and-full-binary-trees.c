/*
 Title: Full Binary Tree and Complete Binary Tree
 Author: Inam Ul Haq
 Description:
	
	1) Full Binary Tree:
	A Full Binary Tree is a binary tree in which all levels are completely filled.
	This means it contains the maximum possible number of nodes for a given height.
	
	If the height of the tree is h, then the total number of nodes n is:
	n = 2^(h + 1) - 1
	
	Example:
	        1
	      /   \
	     2     3
	    / \   / \
	   4   5 6   7
	
	Here, all levels are fully filled, so this is a Full Binary Tree.
	
	
	2) Complete Binary Tree:
	A Complete Binary Tree is a binary tree in which:
	- All levels except the last are completely filled.
	- The last level is filled from left to right without skipping any position.
	
	Example:
	        1
	      /   \
	     2     3
	    / \   /
	   4   5 6
	
	This tree is complete because nodes are added from left to right
	in the last level with no gaps.
	
	
	3) Array Representation of Binary Trees:
	Binary trees can be represented using an array.
	
	Rules:
	- The root node is stored at index 0.
	- For a node at index i:
	  Left child  = 2*i + 1
	  Right child = 2*i + 2
	
	Example (Complete Binary Tree):
	
	Tree:
	        1
	      /   \
	     2     3
	    / \   /
	   4   5 6
	
	Array Representation:
	Index:  0  1  2  3  4  5
	Array: [1, 2, 3, 4, 5, 6]
	
	There are no empty spaces in the array, so the tree is complete.
	
	
	
	Example of a Non-Complete Binary Tree:
	
	Tree:
	        1
	      /   \
	     2     3
	          /
	         4
	
	Array Representation:
	[1, 2, 3, -, -, 4]

	This tree is NOT complete because there are empty positions
	between elements in the array.
*/
