 Title: Deleting Element from Max Heap
 Author: Inam Ul Haq
 Description:
	Assume that we have a heap i.e.
	
					     40
					   /    \
					 35      30
				    /  \    /  \
				  15   10  25   5
				  
	And stored in an array i.e.
	
	-----------------------------------
	| 40 | 35 | 30 | 15 | 10 | 25 | 5 |
	-----------------------------------
	
	Note: Form max heap we can only delete the largest element present in the heap.
	Let me delete the element form the given heap, Obivesly the largest element wil 
	be deleted, it's 40 here.
	More important than that is Which element will take it place? We have re-arrange
	the element back in a way that the condition of heap must be satisfied back.
	
	Assume that the first element of heap is deleted i.e:
		
					     
					   /    \
					 35      30
				    /  \    /  \
				  15   10  25   5		
	which element will take the place of 40? let replace it with next largest element
	in its child i.e. 35. then what about the place of 35? replace it with it's largest
	child i.e 15:
		
					     35
					   /    \
					 15      30
				       \    /  \
				       10  25   5		
				       
	Oh! look it this, this not even now a complete binary tree. So this is worg! let me
	do this with a different way.
	
	First of all i will replace the deleting element of the heap with the last element
	in the heap i.e:
		
					      5
					   /    \
					 35      30
				    /  \    /  
				  15   10  25   
				  
	Now this is complete binary tree but not a max heap, Ok no problem one condition is
	staisfied that's  all, let re-arrange the last element i.e 5. 
	But how to re-arrange it?
	First compare it's both child and chose the greatest one i.e in 35 and 30 it is 
	35 and now compare it with root node i.e 5 if the child is greater then swap them.
	And yes here 35 is greater then 5 so swap them, And do this untill you get the max
	heap. So after first swap it will look like:
		
		
					     35
					   /    \
					  5      30
				    /  \    /  
				  15   10  25   
				  
	now again the child of 5 is greater then 5 and greater child is 15 so agian swap 5 
	with 15. i.e
	
		
					     35
					   /    \
					 15      30
				    /  \    /  
				   5   10  25 
				   
	Now the element is deleted and the remaining structure also obye all the conditions.
	
	
	let me implmenet this procedure.
	
	first look thorugh array i.e
	
	-----------------------------------
	| 40 | 35 | 30 | 15 | 10 | 25 | 5 |
	-----------------------------------
	 1     2    3     4    5   6    7 
	 
	Let me delete 40.
	So first step is to replace 40 with last elemenet  5 i.e.
	
	-----------------------------|-----
	| 5 | 35 | 30 | 15 | 10 | 25 |    |
	-----------------------------|-----
	  1   2     3    4   5    6     7
	Now compare 5 with it's greater child. First compare it's childs i.e if the
	index of perent element is 'i' then it's  first child is 2*i and it's second child 
	is 2*i+1. As i==1 so at 2 -> 35 and at 3-> 30 are the elements and in both of 
	the 35 is greater, Now compare 35 with 5, So again 35 is greater So let swap 
	both of them i.e
	
	-----------------------------|----
	| 35 | 5 | 30 | 15 | 10 | 25 |    |
	-----------------------------|----
	   1   2    3    4    5   6    7
	Now agian it's childs are greater and the greater one is 15 in 15 and 10, So 
	agian swap 5 with 15 i.e 
	
	-----------------------------|----
	| 35 | 15 | 30 | 5 | 10 | 25 |    |
	-----------------------------|----
	   1   2    3    4    5   6    7
	   
	Now as we can see the size of heap is 6, then if we calculate 2*i then it will 
	be 8 which is not there, So now 5 on it's perfect position.
	
	Now let me implement this procdure:


void delete(int A[],int n){
	
	int i=1,j;
	A[i]=A[n];
	j=2*i;
	
	while(j<n-1 && (A[i]< A[j] || A[i]<A[j+1])){
		int temp=A[i];
		if(A[j]>A[j+1]){
			
			A[i]=A[j];
			i=j;
			j=2*i;
			
		}else{
			
			A[i]=A[j+1];
			i=j+1;
			j=2*i;
		}
   }
}
	Analysis:
		The main work we are doing is swaping level by level which take log(n) time
		in worst case, So the time complexity is O(log(n)).

    Now One More Important Thing:
	Whenever when i deleting the element form the array one last poistion of
	heap will become vecant. Is that the part of heap? no. Shall i keep the deleted
	element there i.e 40 ? yes ok no problem beacuse whatever will be there is not 
	part of heap.i.e
	-----------------------------|----
	| 35 | 5 | 30 | 15 | 10 | 25 | 40 |
	-----------------------------|----
	   1   2    3    4    5   6    7
	   
	Now let me delete one more element form the heap. i.e 35. So now the array
	will look like:
	------------------------|----------
	| 30 | 5 | 25 | 15 | 10 | 35 | 40 |
	------------------------|----------
	   1   2    3    4    5   6    7
	   
	Again delete one more element i.e 30. The array will look like:
	-------------------|---------------
	| 25 | 5 | 10 | 15 | 30 | 35 | 40 |
	-------------------|---------------
	   1   2    3    4    5   6    7		
	
	Again delete one more element i.e 25. The array will look like:
	--------------|--------------------
	| 15 | 5 | 10 | 25 | 30 | 35 | 40 |
	--------------|--------------------
	   1   2    3    4    5   6    7	

	Again delete one more element i.e 15. The array will look like:
	---------|-------------------------
	| 10 | 5 | 15 | 25 | 30 | 35 | 40 |
	---------|-------------------------
	   1   2    3    4    5   6    7
	   
	Again delete one more element i.e 10. The array will look like:
	-----|-----------------------------
	| 5  | 10 | 15 | 25 | 30 | 35 | 40 |
	-----|-----------------------------
	   1   2    3    4    5   6    7	
	   
	Now delete the last element also i.e 5, the array will look like:
	|-----------------------------------
	| 5  | 10 | 15 | 25 | 30 | 35 | 40 |
	|-----------------------------------
	   1   2    3    4    5   6    7	
	   
	Observation:
		If you observe we get the deleted element in sorted order and this is
		what? acctually this is heap sort.
		
	Analaysis:
		Here we are just deleting all the elements one by one and deleting one 
		element can takan the time is log(n), So we are deleting n elements therfor
		it will take n-log(n) time.
		
	Implementation:
		
void delete(int A[],int n){
	
	int i=1,j,deletedElement=0;
	deletedElement=A[i];
	A[i]=A[n];
	j=2*i;
	
	while(j<n-1 && (A[i]< A[j] || A[i]<A[j+1])){
		int temp=A[i];
		if(A[j]>A[j+1]){
			
			A[i]=A[j];
			i=j;
			j=2*i;
			
		}else{
			
			A[i]=A[j+1];
			i=j+1;
			j=2*i;
		}
   }
   A[n]=deletedElement;
}
		
		
	Heap Sort:
		1- Create a heap of 'n' elements.
		2- delete and the elements one by one so the element will in assending order.

	This is the end of this lesson if you read this then say me thank you bro! because 
	i wrote this in very busy time for you. Hahaha jsut a joke bro keep shining and 
	move on! i will be always with you.
	