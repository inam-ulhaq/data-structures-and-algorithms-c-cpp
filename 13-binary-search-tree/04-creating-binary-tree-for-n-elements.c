/*
 Title: Creating Binary Search Tree
 Author: Inam Ul Haq
 Description:
	Let's we have set of some values i.e 9, 15, 5, 20, 16, 18, 12. And now we are creating
	binary search tree for the same order. 
	Rules for insertion:
	1- if the value is already there in the binary search tree don't insert it.
	2- if the value is smaller then the existing node move left child of that node.
	3- if the value is greater then the existing node move to right child of that node.
	 
	insertions:
	1- 9 will be insert is a root node.
	2- 15 is greater so it will be asigin to the right child of 9.

							9
							 \
							  15

	3- 5 < 9 so move to left child of 9.

							9
						   / \
						  5	  15 
						  
	4- 20 > 9 so move to right child of 9,then 20 >15 again move to right child of 15.

							9
						   / \
						  5	  15 
						  		\
						  		20
						  
	5- 16 > 9 so move to right child of 9,then 16 >15 again move to right child of 15.
	then 16 <20 so now move to left child of 20 and insert 16.

							9
						   / \
						  5	  15 
						  		\
						  		20
						  	   /
						  	  16
						  	  
						  	  
	6- 18 > 9 so move to right child of 9,then 18 >15 again move to right child of 15.
	then 18 <20 so now move to left child, then 18> 16 so move right child of 16 and 
	insert the new node there.

							9
						   / \
						  5	  15 
						  		\
						  		20
						  	   /
						  	  16
						  	  	\
						  	  	 18
						  	  	 
						  	  	 
	7- 12 > 9 so move to right child of 9,then 12 <15 so move left child of 15. And
	then insert 12 there

							9
						   / \
						  5	  15 
						  	 /	\
						  	12	20
						  	   /
						  	  16
						  	  	\
						  	  	 18
						  
							  
	Now analysis insertion take O(log n) time but when we are creating tree of number
	then we insert n times so the total time for the creating of tree will be O(n log n).
	