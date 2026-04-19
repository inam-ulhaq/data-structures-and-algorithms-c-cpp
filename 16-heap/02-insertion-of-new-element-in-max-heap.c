/*
 Title: Inserting in Max Heap
 Author: Inam Ul Haq
 Description:
	Assume that we have a heap, digramitically shown as:
	

							(30)
						   /   \
						(20)   (15)
					   /   \   /  \
					(5)  (10)(12) (6)

    And this implemented in array like

	-------------------------------------------
	| 30 | 20 | 15 | 5 | 10 | 12 | 6 |   |    | 
	-------------------------------------------
	 1    2    3    4   5    6     7   8   9  -> indeices.
	
	Now what if we want to insert  a new element i.e. 40. So as this is max 
	heap the correct position for new node is insert at root, But 30 is already
	there where it will go? Ok no matter shift it. Now agin there is a confusion 
	shift on which side, left or right?, And if we do it may will not remain a 
	complete binary tree. So this is not the correct way.
	Now let's try to insert it in array so where the next insertion will be done in
	array? as this is a complete binary tree so the next insertion will be done after
	last element. i.e at index 8.

	-------------------------------------------
	| 30 | 20 | 15 | 5 | 10 | 12 | 6 | 40 |    | 
	-------------------------------------------
	 1    2    3    4   5    6     7   8   9  -> indeices.
	 
    Now let's find it's parent, As we know that in complete binary tree we are
    using formulas for left and right child is 2*i and 2*i+1 and for finding 
    parent of an element is i/2. So 40 is store at index 8, divid it by 2 it will 
    be 4. At index 4 in array element 5 is stored so it's mean that 40 is the left
    child of 5.
    But now is this a max heap? no because we says in max heap for an element all 
    it's decendent must samller or equal to an element, but here for 5 the decendent
    40 is greater than it. 
    Ok no mettar swap 40 with it's parent 5, and do this till again and again as the 
    40 reach it's correct position and satisfied the all the conditions of max heap.

	-------------------------------------------
	| 30 | 20 | 15 | 40 | 10 | 12 | 6 | 5 |    | 
	-------------------------------------------
	 1    2    3    4   5    6     7   8   9  -> indeices.
	 
	Now the parent of 40 is the index is 4 so index 4/2 the element is 20, So the 
	parent of 40 will be 20, but 20 is samller than 40.
	Ok again swap both the elements. 
	-------------------------------------------
	| 30 | 40 | 15 | 20 | 10 | 12 | 6 | 5 |    | 
	-------------------------------------------
	 1    2    3    4   5    6     7   8   9  -> indeices.
	 
	Now 40 is child of 30 i.e parent of element present at index 2 is 2/2 which
	is 1 and on index 1 the element is 30, but 30 is smaller then 40, so again swap
	it. 

	-------------------------------------------
	| 40 | 30 | 15 | 20 | 10 | 12 | 6 | 5 |    | 
	-------------------------------------------
	 1    2    3    4   5    6     7   8   9  -> indeices.
	 
	Now the tree is complete binary tree and also for the every element all it's 
	decendents are smaller thant that element or equal then that one.
	
	Now I will show it digarmatically.
	At first step as we know complete binary tree filled form left to right so 
	the first vecant position as left child of 5, 

							(30)
						   /   \
						(20)   (15)
					   /   \   /  \
					(5)  (10)(12) (6)
				   /
				(40)
	But as we know now this is not satisfying the codition of max heap, So we will
	swap it with it's parent.
	

							(30)
						   /   \
						(20)   (15)
					   /   \   /  \
					(40)  (10)(12) (6)
				   /
				(5)
				
	Again 20 is smaller then 40, So swap again
	

							(30)
						   /   \
						(40)   (15)
					   /   \   /  \
					(20)  (10)(12) (6)
				   /
				(5)
				
	Again 30 is smaller so let's swap agian
	

							(40)
						   /   \
						(30)   (15)
					   /   \   /  \
					(20)  (10)(12) (6)
				   /
				(5)

	Now finally if we lock to the strcuture, It satisfied all the condition of
	max heap. So this is how we can insert a new element in max heap.
	
	We can do insertion in min heap in the samiller way but the we have take car
	about the condition of min heap.
	
	

	
	
	
	
	

					   
				