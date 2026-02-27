/*
 Title: Terminologies of Tree
 Author: Inam Ul Haq
 Description:
	1 Tree:
		Tree is the collection of nodes and edges. If there are n
		nodes, then there will be n-1 edges, because for every node
		there is an edge coming from its parent except the root node.
		The node that has no parent, from where the tree is starting, is
		the root node, and the rest of the tree is called subtree. So tree is the
		collection of nodes, where one of the node is taken as the root node,
		and the rest of the nodes are divided into disjoint subsets, and
		each set is a tree or subtree.
		
	2 Root:
		The root is the topmost node of a tree and it is the starting point of the tree. 
		The root node has no parent, and all other nodes in the tree originate from it. 
		Every tree has exactly one root node, from which the entire tree structure is formed.
		
	3 Parent:
		The node is parent to it's very next decendents or those children which are connected 
		with just one edge.
		
	4 Child
		A child is a node in a tree that has a parent node directly above it. Any node that is 
		connected below another node by an edge is called the child of that node. A parent node 
		may have one or more child nodes, and each child node can further have its own children, 
		forming subtrees.
	
	5 Sibling: 
		Siblings the childern nodes of the same parent node.
		
	6 Descendents: 
		For any node the set of nodes which its childerns and their childerns and their childerns
		and so on are descendents. Or in other words descendents are those set of nodes which can 
		be reached from a particular node or under that node.
	
	7 Ancestors:
		For any node along the path from that node to root node all the nodes are ancestor.
		
	8 Degree of a Node:
		Degree of a node is number of direct childerns to that node, i.e if a node have two direct
		childern then it's degree is two.
	
	9 External Nodes:
		It is also called leaf nodes or terminal nodes. Nodes with degree zero are called is
		external nodes mean which no further childerns.
	
	10 Interanl Nodes:
		This is also called non leaf or non terminal nodes. Nodes whose dergee greater then zero 
		are internal nodes. 
	
	11 Levels:
		Levels of tree is start form 1 onwords that is root is at level one and it's childerns are
		at level 2 and their childerns are at level 3 and so on. To find a level for a node we counts 
		it's ancestors to till root node.
	
	12 Height:
		Height of the node is the number of adjuces till that node. So till root node there is no adjuce 
		therefore the height of root node is zero, then till the direct childrens of root node is one 
		adjuce so it's height is 1.
		
	13 Forests:	
		Collection of trees is called forests.
*/	 