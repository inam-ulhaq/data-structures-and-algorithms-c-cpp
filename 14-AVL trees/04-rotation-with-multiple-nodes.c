/*
 Title: Formulas for Rotations
 Author: Inam Ul Haq
 Description:
	We seen multiple rotation but those were only for three nodes, now what if there are
	multiple more than three nodes or there are also childs of the child of imbalance node?
    We will see this in formulas.
    
    LL Rotation With Multiple Nodes:
    	Assume that we have tree of multiple nodes i.e. thousands of node, And One node
		become imbalance in it i.e. node A, So as we know that in rotation only 3 nodes 
		can be modified durring rotations.
    										A
    									  /  (A left child)
    									 B  
    								   /  \
    								  C   D
							  (C childs) (D childs)
    Assume that the balance factors are: A -> 2, B -> 0, C -> 0, D -> 0.
    
    Now we are clearly seeing this node "A" is imbalance, So to balance just strach it downward,
    Node B will goto the position of A and will become the right child of B.
    Now what about the Node C? It will there same as first i mean left child of B still.
    But about right child of B which Node D? Yah it's problematic so if we keep it same as first 
    one the it will be not a binary tree mean node B will be three child i.e. left child C, right 
    child A and one at the maddle which is D. So to solve this problem will shipt the midle node D
    and make it the left child of A. But wait what if there is already left child of A? No don't 
    worry it will not happen because before this A was parent of B and B was the left child of A,
    So as B become the parent of A, Then the left child position of A will be vecant for now, So just
	attach the right child of B with the left child  of A. i.e.

    									 B  
    								   /  \
    								  C   A
							  (C childs) / \
									    D (A right child)
									 (D childs) 
	Now the tree become balanced. 
	Balance Factors: B -> -1, C-> 0, A->1,D->1.
	
	Example:



										30
									  /    \
									20      40
								   /  \		 \
								  10  25     50
								 /  \   \
								5   15  28
							   /
							  4	
    Balance Factors: 30 -> 2, 20 -> 1, 40 -> -1, 10 -> 1, 25-> -1, 50 -> 0, 5 ->1,
    				 15-> 1, 28 -> 0, 4 -> 0
    				 
    Only one node balance factor is invalid which 2 ,So we have to balance it. Striching
    30 to 40 position, what about 30 position? 20 will comes, Now 20 will three childs i.e.
    10, 25 and 30, S0 we have to connect the 25 with 30 as a left child of 30. It will be 
    look like: 
    
    
    
										20
									  /   \
									10     30
								   /  \	   / \
								  5   15  25  40
								 /         \
								4          28
								
    Balance Factors: 20 -> 0, 10 ->1, 30 ->1, 40 -> -1, 5-> 1, 15 -> 0, 25 -> -1,
    				 40-> 0, 4 -> 0, 28 -> 0.
					 
	Now no invalid value is there so the tree become imbalance.		
	
	
	
	/*
 Title: Formulas for Rotations
 Author: Inam Ul Haq
 Description:
	We seen LL rotation, now we will see RR, LR and RL rotations
	in the same format and same explanation style.


    RR Rotation With Multiple Nodes:

	Assume that we have tree of multiple nodes i.e. 
	And One node become imbalance in it i.e. node A.

    										A
    						(A left child)	  \  
    										   B  
    										  /  \
    										 C   D
								    (C childs) (D childs)

    Assume that the balance factors are:
    A -> -2, B -> 0, C -> 0, D -> 0.

    Now we are clearly seeing this node "A" is imbalance,
    So to balance just strach it downward in left side.

    Node B will goto the position of A and will become
    the left child of B.

    Now what about the Node D?
    It will remain same as first i mean right child of B still.

    But about left child of B which Node C?
    If we keep it same then B will have three childs,
    left child A, right child D and middle C.

    So to solve this problem we will shipt the middle node C
    and make it the right child of A.

	So just attach the left child of B with the right child of A.

    										B
    									  /   \
    									 A     D
    								    / \
    				        (A left child) C
    									 (C childs)

	Now the tree become balanced.

	Balance Factors:
	B -> 1, A -> -1, C -> 0, D -> 0.


	Example:

										30
									  /    \
									20      40
											  \
											   50
												 \
												  60

    Balance Factors:
    30 -> -2, 40 -> -1, 50 -> -1, others -> 0

    Only one node balance factor is invalid which -2,
    So we have to balance it.

    Striching 30 downward,
    40 will comes to position of 30.

    Now 40 will have three childs i.e.
    30, 50 and middle subtree (none in this simple case).

    Final tree:

										40
									  /    \
									30      50
								   /          \
								 20           60

	Now no invalid value is there so the tree become balanced.


	LR Rotation With Multiple Nodes:


	Assume that node A become imbalance and
	A -> 2 and its left child B -> -1.

    										A
    									  /
    									 B
    									  \
    									   C
    									  / \
    							 (C left)  (C right)

    This rotation done in two steps.

    Step 1: Left rotation at B
    Step 2: Right rotation at A


	Step 1:

    										A
    									  /
    									 C
    									/
    								   B


	Step 2:

    										C
    									  /   \
    									 B     A
    								    / \   / \
    						(B left)(B right)(A left)(A right)

    Node C will goto position of A.
    Node A become right child of C.
    Node B become left child of C.

	Now the tree become balanced.


	Example:

										30
									  /
									20
									  \
									   25

    Balance Factors:
    30 -> 2, 20 -> -1

    After LR rotation:

										25
									  /    \
									20      30

	Now no invalid value is there so the tree become balanced.


	RL Rotation With Multiple Nodes:


	Assume that node A become imbalance and
	A -> -2 and its right child B -> 1.

    										A
    										  \
    										   B
    										  /
    										 C
    										/ \
    								 (C left)  (C right)

    This rotation also done in two steps.

    Step 1: Right rotation at B
    Step 2: Left rotation at A


	Step 1:

    										A
    										  \
    										   C
    										    \
    											 B


	Step 2:

    										C
    									  /   \
    									 A     B
    								    / \   / \
    							   (A left)(C left)(C right)(B right)

    Node C will goto position of A.
    Node A become left child of C.
    Node B become right child of C.

	Now the tree become balanced.


	Example:

										30
										  \
										   40
										  /
										 35

    Balance Factors:
    30 -> -2, 40 -> 1

    After RL rotation:

										35
									  /    \
									30      40

	Now no invalid value is there so the tree become balanced.
*/