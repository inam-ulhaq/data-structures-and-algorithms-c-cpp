 Title: Program to Insert into Heap
 Author: Inam Ul haq
 Description:
 	Assum that we have a heap:
 	
 						40
 					   /  \
 					 35    15
 					/ \    / \
 				   30  10 12  06
 				  / \
 				 5  20
 	
	And it stored in an array.i.e.
 	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 10 | 12 | 06 | 05 | 20 |   |
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9  
	
	And now we are inserting a new element 50. So first of all we will store 
	element in array then we will call the function insert() to rearrange the 
	the elements.i.e the new element is 50.
	then
	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 10 | 12 | 06 | 05 | 20 | 50|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    5
	
	Now the element is stored in the array but this is  not heap because it make
	a structure like.

	 					40
 					   /  \
 					 35    15
 					/ \    / \
 				  30  10 12  06
 				 / \  /
 			    5  20 50 
				 
	Which is not the shap of max heap, so what we have to do now we will re-arrange the
	elements and convert it back it into max heap.
	
	Rearranging the Elements: 
	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 10 | 12 | 06 | 05 | 20 | 50|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10
	
	consider that 'n' is the index to new inserted element in the arry.
	so we will pass both the array and 'n' to insert() function:
		
	void insert(int A[],int n){
		// let's take two variables 
		// 'i' for triversing the array
		int i; 
		// 'temp' for storing the newly inserted element int array
		int temp; 
		i=n; // assigaining n to i
		temp=A[i]; //assiging newly inserted element to temp.
		
		// Now waht we have to do further? just compare element at index i in
		// array with the parenet of index i. If the value in temp is smaller or
		// equal with it's parent then do nothing maean it position is already perfect,
		// or if the value in temp is greatr the swap it with it's parent, and 
		// do this aagin and again untill either the value in temp is greater or you 
		// reached to the the root element, mean as long as i is greater than 1.
		// So we can do this through loop.
		while(i>1 && temp>A[i/2]){ // condition 
			
			A[i]=A[i/2]; // this will move the value to forward if condition 
						 // satisfied
			i=i/2;		 // this will update the index as the new value move farward.
		}
		// As the loop ends, mean that the new perfect position if finded out and then
		// have to assgain the new value.
		A[i]=temp;
		
	}
	
	So this is how the element will be re-arranged with function.
	
	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 10 | 12 | 06 | 05 | 20 | 50|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10
	
	i.e at first iteration:
		the new value is 50 and its index is 10 so 10/2=5 will be it's parent
		index which is 10. now compare 50 with 10 so the 50 is greater than 10 
		therfore the condition is true, So the iteration will be performed and 
		the loop will do their work.
	
	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 10 | 12 | 06 | 05 | 20 | 10|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10	
	
	as you can see the 10 is copied to to it's new position, and as the 'i' was 
	10, So it was also divided by 2 and become 5, So the new value of 'i' is 5 
	then it's  parent value will be 5/2=2, mean it's parent element is 35, now 
	again check the conditions:
	
	i=5, A[5/2]=35 and temp is 50, so 'i' is also greater than 1 and 50 is also 
	greater than 35 so the loop will again exicute.
	And then new array will become:
	--------------------------------------------------
    | 40 | 35 | 15 | 30 | 35 | 12 | 06 | 05 | 20 | 10|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10
	 and 'i' will be equal to 2.
	 
	 
	Again check the conditions:
	
	i>1 yes that ture and A[2/2]=40 is also less than 50 so this condition also 
	true. So the loop will exicute again.
	The new array will be:
	
	--------------------------------------------------
    | 40 | 40 | 15 | 30 | 35 | 12 | 06 | 05 | 20 | 10|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10
	And i=1;
	
	now let's  agian check the conditions:
	
	as i which is 1 is greater than 1? now it's equal so the condition will
	become false and loop will be ends:
	
	i indecate the perfect position for new value 50 stored in temp variable.
	
	So after the loop "A[i]=temp" will assgain the the new value to it's position
	i.e the new array will be 
	--------------------------------------------------
    | 50 | 40 | 15 | 30 | 35 | 12 | 06 | 05 | 20 | 10|
 	--------------------------------------------------
	 1     2    3    4     5   6     7   8    9    10
	
	now the this is  perfect max heap.,
	
	
	
	
	
	
	
	 