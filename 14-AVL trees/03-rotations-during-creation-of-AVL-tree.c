/*
 Title: Rotation During Creation of AVL Tree
 Author: Inam Ul Haq
 Description:
	When we are inserting new nodes in AVL tree then it may become imbalance and so 
	to balance it we perform rotations.
	i.e 
						30
					   /
					  20
	And now we inserting and new node 10. Then it will become imbalance. i.e.
						30
					   /
					  20
					 /
					10
	here the balance factor 30 becom 2 which is not valid so the tree become imbalance 
	now how to balance it? we should rotate the tree on right side or we can say strach
	it below form 30 node toward right side. Then it will become
		
		
						20
					   /  \
					  10  30
	Now the tree is balanced bianry search tree or AVL tree.
	Types of Rotations:
	1-LL Rotation
	2-RR Rotation
	3-LR Rotation
	4-RL Rotation

	LL Rotation:
		let's take the initail tree 
		i.e 
						30
					   /
					  20
	The balance factor of 30 is 1 and the of 20 is 0. 
	Now let's insert on more node 15. 
						30
					   /
					  20
					 /
					15
	The balance factor of 30 is 2, of 20 is 1 and of 15 is 0. So node 30 become imbalance
	therefore we will perform rotation but before give a name to the that. Why the node become
	imbalance? because of rotation, In which direction that new node is inserted? in left of left
	or LL so let's name it LL Imbalance. Now for LL Imbalance how to perform rotation?
	The imbalance node is 30, So strich it toward right side but below so that the left child 
	of 30 which 20 come to the place of 30 and 30 become the right child of that node i.e of 20.

	(Befor Insertion)       (After insertion 15)     ( After Roation )
	
		  30						30						20
		 /						   /					   /  \
		20						  20					  15  30
								 /
								15
	
	1- Now what should be the name of the rotation? Hence we are balancing LL imbalance so to 
	this we can give any name let's say this is LL Rotation or Clock Rotation etc, there is no
	standard name for this, this is just a rotation so we can give any name.
	2- Now if you say this is just a small tree of three nodes, what if the tree is very large?
	dont worry rotation is always performing on just 3 nodes even if the tree has thousand of nodes
	also.




	RR Rotation:
		let's take the initail tree 
		i.e 
						10
					   	  \
					  	   20
					  	   
	The balance factor of 10 is 1 and the of 20 is 0. 
	Now let's insert on more node 30. 
						10
					   	  \
					  	   20
					  	   	\
					  	   	 30
	The balance factor of 10 is 2, of 20 is 1 and of 30 is 0. So node 10 become imbalance
	therefore we will perform rotation but before give a name to the that. Why the node become
	imbalance? because of insertion, In which direction that new node is inserted? in right of right
	or RR so let's name it RR Imbalance. Now for RR Imbalance how to perform rotation?
	The imbalance node is 10, So strich it toward left side but below so that the right child 
	of 10 which 20 come to the place of 10 and 10 become the left child of that node i.e of 20.

	(Befor Insertion)       (After insertion 30)     ( After Roation )
	
		  10						10						20
		   \						  \					   /  \
			20						  20				  10  30
								        \
										30
	
	Note: Now what should be the name of the rotation? Hence we are balancing RR Imbalance so to 
	this we can give any name let's say this is RR Rotation or Anti Clock Rotation etc.


	LR Rotation:
		let's take the initail tree 
		i.e 
						10
					   	  \
					  	   20
					  	   
	The balance factor of 10 is 1 and the of 20 is 0. 
	Now let's insert on more node 15. 
						10
					   	  \
					  	   20
					  	  /
					  	15
	The balance factor of 10 is 2, of 20 is 1 and of 15 is 0. So node 10 become imbalance
	therefore we will perform rotation but before give a name to the that. Why the node become
	imbalance? because of insertion, In which direction that new node is inserted? in right of left
	or RL so let's name it RL Imbalance. Now for RL Imbalance how to perform rotation?
	The imbalance node is 10, So now just strich one node will not enough the tree may still not balance
	so we will do this in tow steps. First strach 20 toward right side but below so that the left child 
	of 20 which 15 come to the place of 20 and 20 become the left child of that node i.e of 15. Now the 
	tree will become right skewed binary search tree, like the root node will be 10 and right child of 10 
	will be 15 and right child of 15 will be 20. So to balance this one one is required one more rotation 
	which is RR Rotation
	 

	(Befor Insertion)       (After insertion 30)     ( After first Roation )    (After second rotation)
	
		  10						10						10							 15
		   \						  \					      \							/  \
			20						  20				      15					  10   20
								     /							\
								    15							20  

	We are balancing RL Imbalance so let's say this is RL Rotation. This is one rotation only but can be done
	in two steps therefore we will call this double rotation.






	RL Rotation:
		let's take the initail tree 
		i.e 
						30
					   /
					10
					  	   
	The balance factor of 30 is 1 and the of 10 is 0. 
	Now let's insert one more node 20. 
						30
					   /
					10
					 \
					  20
					  
	The balance factor of 30 is 2, of 10 is 1 and of 20 is 0. So node 30 become imbalance
	therefore we will perform rotation but before give a name to the that. Why the node become
	imbalance? because of insertion, In which direction that new node is inserted? in left of right
	or LR so let's name it LR Imbalance. Now for LR Imbalance how to perform rotation?
	Again we will do this in two steps. First strach 10 toward left side but downward so that the right child 
	of 10 which 20 come to the place of 10 and 10 become the left child of that node i.e of 20. Now the 
	tree will become left skewed binary search tree, like the root node will be 30 and right child of 30 
	will be 20 and right child of 20 will be 10. So to balance this one is required one more rotation which is
	LL Rotation.
	 

	(Befor Insertion)       (After insertion 20)     ( After first Roation )    (After second rotation)
	
		  30					30						30							 20
		  /						/					    /							/  \
		10					  10				      20					  	   10  30
								\					  /
								20					10  

	We are balancing LR Imbalance so let's say this is LR Rotation.


	Message by Author Inam Ul Haq
	    Writing this manully then was so diffcult then memorzing but still i worte and complete this,
		Then don't think to skip, understand this and implement also.
	    
	
				 
	