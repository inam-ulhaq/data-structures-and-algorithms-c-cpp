/*
 Title: Number of Binary Trees
 Author: Inam Ul Haq
 Description:
	The number of binary trees refers to how many different binary tree
	structures can be formed using a given number of nodes. For example,
	if the number of nodes is 3, then there are several distinct binary
	trees that can be constructed depending on the arrangement of nodes.

	There are two types of nodes considered while counting binary trees:
		- Unlabelled Nodes
		- Labelled Nodes
		
	1. Unlabelled Nodes:
	   When the nodes are not distinct, the number of different binary
	   trees that can be formed with n nodes is given by the nth Catalan
	   number.

	      cn = (1 / (n + 1)) * (2n choose n)
	   
	   Example:
		if there are 3 number of unlabelled nodes the number of possible 
		trees are:
		
		1)	O	2) 	   O    3)    O    4)   O    5)   O
		   /		  /          / \         \         \
		  O			 O          O   O         O         O
		 /			  \                      /           \
		O			   O                    O             O
        
        So there 3 nodes we can genrate 5 different shaped binary trees.
        next if there are 4 node the there can be 14 different shaped trees 
        are genarated i.e
        
        1)      O            2)      O            3)      O
		       /                    /                    /
		      O                    O                    O
		     /                    / \                    \
		    O                    O   O                    O
		   /                                              /
		  O                                              O


		4)  O            5)      O            6)      O
 	        \                    \                    \
 	         O                    O                    O
	          \                  / \                  /
          	   O                O   O                O
                \                                     \
                 O                                     O


		7)    O           8)        O           9)        O
	         / \                   / \                   / \
	        O   O                 O   O                 O   O
	       /                          \                /
	      O                           O               O


	10)   O          11)       O          12)       O
         / \                  / \                  / \
        O   O                O   O                O   O
         \                  /                      \
          O                O                        O


	13)   O          	 14)  O
         /                    \
        O                      O
         \                    /
          O                  O
           \                /
            O              O
            
         Now let's verify this through the Catalan number formula, i.e., for n = 3

			C(n) = (1 / (n + 1)) * (2n choose n)
		
			C(3) = (1 / (3 + 1)) * (6 choose 3)
			C(3) = (1 / 4) * (6 * 5 * 4) / (3 * 2 * 1)
			C(3) = (1 / 4) * 20
			C(3) = 5
			

 Hence, for 3 unlabelled nodes, the number of possible binary trees is 5.


	2. Labelled Nodes:
	   When the nodes are distinct (labelled), the number of different
	   binary trees that can be formed with n nodes depends on both the
	   structure of the tree and the arrangement of labels on the nodes.

	    The number of labelled binary trees is given by:

	    	Number of labelled binary trees = Cn × n!

	   where Cn is the nth Catalan number and n! is the factorial of n.


	   Example:
		if there are 3 labelled nodes, then first we find the number of
		unlabelled binary tree structures and then arrange labels on each
		structure.

		From Catalan number:
			C(3) = 5        // five different structures

		Factorial of 3:
			3! = 3 × 2 × 1 = 6   // six label arrangements per structure


	   The 5 different structures are shown below, and for each structure
	   all 6 label arrangements (A, B, C) are possible.


	   Structure 1 (Left Skewed):

		    O            A            A            B            B            C            C
		   /            /            /            /            /            /            /
		  O       ->   B      ->    C      ->    A      ->    C      ->    A      ->    B
		 /            /            /            /            /            /            /
		O            C            B            C            A            B            A


	   Structure 2 (Right Skewed):

		O              A            A            B            B            C            C
		 \              \            \            \            \            \            \
		  O        ->    B      ->    C      ->    A      ->    C      ->    A      ->    B
		   \              \            \            \            \            \            \
		    O              C            B            C            A            B            A


	   Structure 3 (Root with Two Children):

		    O              A            A            B            B            C      
		   / \            / \          / \          / \          / \          / \
		  O   O      ->  B   C   ->   C   B   ->   A   C   ->   C   A   ->   A   B
		                               
	   Structure 4 (Left child with right child):

		    O              A            A            B            B            C    
		   /              /            /            /            /            /
		  O         ->   B     ->    C        ->    A     ->    C      ->    A
		   \              \          \              \           \            \
		    O              C         B              C           A             B


	   Structure 5 (Right child with left child):

		O               A             A    	          B              B              C  
		 \              \              \              \              \              \
		  O        ->    B        ->    C        ->    A        ->    C        ->    A
		 /              /              /              /              /              /
		O              C              B              C              A              B


	   Thus:
		Number of structures = 5
		Label arrangements per structure = 3! = 6

		So, number of labelled binary trees:
			= C(3) × 3!
			= 5 × 6
			= 30

	   Hence, for 3 labelled nodes, the number of possible binary trees
	   is 30.


		Similarly, if there are 4 labelled nodes:
			C(4) = 14
			4! = 24

		Number of labelled binary trees:
			= 14 × 24
			= 336

*/