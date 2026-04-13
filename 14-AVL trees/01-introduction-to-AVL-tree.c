/*
 Title:AVL Trees
 Author: Inam Ul Haq
 Description:
	These are height balance binary trees. How the height of tree can balanced? The 
	height can be balanced using balance factor.

	Balance Factor:
	balance factor of node is the height of it's left sub tree subtracted by height of
	it's right sub tree i.e.

	balance of factor= height of left sub tree - height of right sub tree
	
	This balance factor we calculated on every node of binary search avl tree.
	We can get any value form the above expression than what values will be consider
	the valid balance factor values for a node?
	valid balance factor values={ -1, 0, 1} or when we take modulus of that value it must
	be less than or equal to 1. i.e. b.f= |h.l-h.r| <= 1.
	
	For every node the balance should be calculated in the tree and every node  must be 
	balance otherwise we say the tree is imbalanced. 
	
	When the tree is imbalanced then how we can make balanced or AVL tree? using rotation
	we make the tree balanced.