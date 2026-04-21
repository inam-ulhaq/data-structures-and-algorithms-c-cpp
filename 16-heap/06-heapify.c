 Title: Heapify
 Author: Inam Ul  Haq
 Description:
	Heapify is a procedure related to creation of heap not just insertion of one
	element, but inserting all the elements one by one and creating a heap. So it 
	is releted to creation of heap.
	
	Now let understand frist insertion and deletion in max heap.
		Assume that we have already a heap i.e
		
		
							 40
						  /     \ 
						30       35
					  /   \     /   \
					15    10   20   12
	let's insert  a new key i.e 45:
		it will be inserted at first vecant place i.e left child of 15 i.e:
		
							 40
						  /     \ 
						30       35
					  /   \     /   \
					15    10   20   12
				   /
				 45
		
	Now it will be re-arrange and place to it perfect position i.e 
	first compear with parent which is 15 and yes 45 si greater then 15 so it 
	will be swaped with 15.
		
							 40
						  /     \ 
						30       35
					  /   \     /   \
					45    10   20   12
				   /
				 15
	Again check it with it perent and grand parent place it on it's correct poistion.
	So 45 is greater then 30, So it will be swap with 30 now again compare it with 40,
	So 45 is again greater then 40, again swap 40 and 45. The final tree will look like:

							 45
						  /     \ 
						40       35
					  /   \     /   \
					30    10   20   12
				   /
				 15
				 
	So we adjusted the new element. But how adjustment is done? By sending the
	element from leaf to word root. So the only importent thing here is in insertion
	the element is adjusted form leaf toward root. So it down to upword. 
	
	Now let delete element form the give heap. So we know very will that always the root
	element will be deleted form the heap because it is the greatest element in the max 
	heap. Then who will take it's place the last element in the heap. 
	then is that will be a heap? no, but it will be a complete binary tree. then what to 
	do to make it a max heap? re-arranged the elements i.e compare it with it's greatest 
	child and if the child is greater then swap both of them, and do this again and again 
	till it comes to leaf or it's both childs is less than that element. 
	
	In this example 45 will be deleted, and as we know the last elment is 15 so 15 will be
	come to it's place and again 15 will be compare with it's greater child which is 40 so 
	40 is greater then and 15 and 40 will be swap with each other and again 15 will compare 
	with it's greater child which is 30 so 30 is greater then 15 therefor both will be swap 
	again and now 15 is the leaf node therefor it is now on it's perfect position.
	And the tree will look like: 
	
	
							 40
						  /     \ 
						30       35
					  /   \     /   \
					15    10   20   12
					
	Observation:
		As we delete the root node then we are arranging the element form root to 
	leaf node. i.e bringing the elemenet form root to leaf node. So here the important
	thing is it upword to down.
	
	
	Now in both insertion and deletion we are adjust elements to form a max heap but the
	direction of the is different i.e one is down to upword and second one is upword to 
	down approach.
	
	Now this is enough for me, let's  a binary array and which not a max heap try both 
	the approches i.e up to down and down to up for creating heap.
	
	
	i.e the array is:
		
		-----------------------------------
		| 5 | 10 | 30 | 20 | 35 | 40 | 15 | 
		-----------------------------------
		  1   2     3    4    5    6   7 
		  
	frist let's  try the up to down approch which we already following till now for insertion.
	i.e.
	
	
							 5
						   /   \
						 10     30 
						/  \   /  \
					  20   35 40  15
	Now this is complete binary tree but not a heap for making this heap we have to arrange
	all the elements one by one i.e. consider 5 is heap now arrange this, check it with it's
	childs so 30 is greater, swap it with 30.
							 30
						   /   \
						 10     5 
						/  \   /  \
					  20   35 40  15
	agian chek 5 with 40 so 40 is greater, ok swap that i.e.

							 30
						   /   \
						 10     40 
						/  \   /  \
					  20   35  5  15
					  
	Now is this a heap? no, because we just adjust only one element, how many element have 
	to adjust to make a max heap? n elements. And how many time is needed to adujust only 
	one element? log (n). So for n elements n-log(n) time will be needed.
	
	
	Now let's try the second approch i.e. down to up approch, here we will consider the leaf
	elements first for adjust and we will not compare them with it's parents but we will compare
	it with it's childrens. but leaf element have not any childrens? Yes and that is the main 
	benifet of dwon to up approch, Half of the element don't need to adujust.
	
							 30
						   /   \
						 10     5 
						/  \   /  \
					  20   35 40  15
					  
	This is a binary tree and will try to convert it into max heap. Consider the last
	element i.e 15 is heap, check it with it's childs, but it have no child, ok move to 
	40, 40 have also no child. All the leaf node will not adjust because it have no childs.
	Now go to 5 and check it with childs so it's greater child is 40, swap 40 with 5.
	The structure will look like: 
	
							 30
						   /   \
						 10     40 
						/  \   /  \
					  20   35 5   15
	Now move to 10, here the greater child is 35, so swap 35 with 10.
							 30
						   /   \
						 35     40 
						/  \   /  \
					  20   10 5   15
					  
	Now go to 30, it's greater child is 40 ok swap it and check the 30 again with
	it's new childs 5 and 15 but 30 is greater so keep it on it's position. and the 
	new structure will be look like:
		
							 40
						   /   \
						 35     30 
						/  \   /  \
					  20   10 5   15
					  
					
    Now let's check both on conditions of max heap on this.
	Is this a complete binary tree? yes.
	Is every parent element is greater than it's childs? yes. 
	So ok all the conditions are satisfied on this and finally a max heap is created 
	with less number of adjust meants.
	
	Analysis:
		As we not adjusting half of the elements here i.e leaf elements, therefore 
		analytically it's time complexity is Order of n i.e O(n), which much better 
		than n-log(n). And this is known as heapify.
				
		