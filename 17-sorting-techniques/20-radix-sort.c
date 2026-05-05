 Title: Radix Sort
 Author: Inam Ul Haq
 Description:
	A: 237, 146, 259, 348, 152, 163, 235, 48, 36, 62. Already I have taken 
	array of elements, and I am going to sort them using radix sort.
	This sort is similar to bin sort, but in bin sort we may take an array of 
	bins equal to the largest element present in the array, so what is the largest
	element present in our array i.e it is 348, so imagine I have an array of bins of 
	size 348, it will require lots of space in memory, assume that if the largest
	element in the array is 10000, then we will create an array of bins of size 10000.
	So to make that bin sort simple we introduce radix sort.
	
	So how is this different?
	See we will not take a 348 bins array for the above list, but we will take 
	only 10 bins. 
	
	Why only 10 bins? 
	See what the above numbers are? These are integers. Ok integers, but which
	number system? Decimal number system.
	
	In the decimal number system how many digits? 0 to 9, so take 0 to 9 bins,
	that means these are enough to sort those numbers using radix sort. So that's
	why the name is radix. Then what if the above numbers are in binary form, then
	how many bins are enough? Only two bins are enough. What if those are octal? then 8 
	bins are enough. So that's why the name comes radix sort. 
	
	So for sorting the above list I will take 10 bins from 0 to 9 and also initialize 
	with NULLs i.e 
	
		----------------------------------------------------------
	A	| 237 | 146 | 259 | 348 | 152 | 163 | 235 | 48 | 36 | 62 |
		----------------------------------------------------------
		  ---------------------------------------------------
	bins :|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|
		  ---------------------------------------------------
		    0    1     2    3   4    5    6    7    8    9
		    
	So the setup is ready. Next we have to learn how to sort them.
	
	So let's start the procedure. In the procedure I will scan through the list of
	elements. In scanning the first element is 237, and if we look in the bins,
	but there is no bin available for 237? No we don't have to drop 237 in bin 237, 
	but we have to drop it in bin 7. So it means I should just check the last digit
	of the number? Yes I should check only the last digit of the number and drop it 
	in that corresponding bin, so the 237 will drop in bin 7 i.e:

		----------------------------------------------------------
	A	| 237 | 146 | 259 | 348 | 152 | 163 | 235 | 48 | 36 | 62 |
		----------------------------------------------------------
		  ---------------------------------------------------
	bins :|NULL|NULL|NULL|NULL|NULL|NULL|NULL|   |NULL|NULL|
		  ---------------------------------------------------
		    0    1     2    3   4    5    6   7|    8    9
		    								  237
		
	Assume that 237 was stored in A[0], then how can I know the last digit of
	A[0] is 7? By simply taking modulus of A[0] with 10 i.e A[0]%10.
	
	Now the same thing I will do for the whole list and the final list will look
	like:
		
		----------------------------------------------------------
	A	| 237 | 146 | 259 | 348 | 152 | 163 | 235 | 48 | 36 | 62 |
		----------------------------------------------------------
			
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins :|NULL|NULL|    |    |NULL|    |    |    |    |    |
		  ---------------------------------------------------
		    0    1     |    |         |    |     |     |     |
		    		  152  163		 235  146   237   348   259
		    		   |				   |		   |
		    		  62				  36		   48
		
	So the final bin array will look like.
	Now assume that the list A becomes empty. We will scan the bins list and 
	if the bin is not empty copy that element to list A in the first empty location.
	but some bins are holding more elements, copy which one first? The one that is inserted
	first into the bins i.e bin 2 holding two elements the first one is 152 and the 
	second one is 62, then copy 152 first then 62. And also make the bins empty again.
	So the regenerated list will look like:
	   ----------------------------------------------------------	
	A: | 152 | 62 | 163 | 235 | 146 | 36 | 237 | 348 | 48 | 259 |
	   ----------------------------------------------------------
	   
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins: |NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|
		  ---------------------------------------------------
		  
	So finally we regenerated the list from bins. Now look at the list carefully,
	is the list sorted now? No, it is not sorted yet, that was just the first pass.
	
	Then what to do further? Repeat the above process for the second pass, but that 
	was on the basis of the last digit i.e we were dropping the elements based on the
	last digit of the number. But here we will drop the numbers based on the 
	second last digit of the number to corresponding bins. i.e the first element 
	is now 152, and as this is the second pass, so the second last digit of 152 is 5,
	so drop 152 into the 5th bin. Second element in the list is 62, the second last is
	6, therefore drop 62 into the 6th bin. 
	
	Scan the whole list and do this with all the elements, so finally the bins
	will look like: 
	
	
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins :|NULL|NULL|NULL|    |    |    |    |NULL|NULL|NULL|
		  ---------------------------------------------------
		    		       |   	|     |    |           
		    		      235  146	 152   62          
		    		       |    |	  |	   |		
		    		       36  348	 259  163		 
		    		  	   |	|
		    		  	  237  48
		    		  	   
	Now regenerate the list from the above bins and make them empty also.
	Scan the list from the left side copy the elements to the list i.e
	   ----------------------------------------------------------	
	A: | 235 | 36 | 237 | 146 | 348 | 48 | 152 | 259 | 62 | 163 |
	   ----------------------------------------------------------
	
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins: |NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|
		  ---------------------------------------------------
		  
	So this is the result of the second pass.
	
	Now again look at the list and tell is it sorted or not? No this is not
	sorted again. Ok no problem do one more pass.
	
	Total how many passes we will do to sort a list? Up to the number of digits of
	the maximum number in the list. What do you mean by this? I mean in the above list 
	the maximum number is 348, and there are three digits in 348 i.e 3,4,8 so the 
	list will be sorted in 3 passes. Then what if in a list the maximum element is 
	34532? Simple it will be sorted in 5 passes because it has five digits.
	But the important thing is every pass will not be done on the same digit. But 
	first pass will be done on the last digit, second pass will be done on the second last
	digit, third pass will be done on the third last digit and so on.
	But what if there are smaller elements also there i.e of one or two digits, then
	how will it deal in the third pass because they do not have a third digit? Yes we will assume 
	their third digit is zero.
	
	Now so far we have done only two passes let's complete the third pass also.
	Scan the new generated list A and drop the numbers to bins i.e
	
	
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins :|	   |    |    |    |NULL|NULL|NULL|NULL|NULL|NULL|
		  ---------------------------------------------------
		   | 	|	  |    |              
		   036	146	  235  348	         
		   | 	|	  |        
		   048	152	  237     	 
		   | 	|	  |	   	
		   062	163	  259	  
		   
	So finally all the numbers are dropped into their corresponding bins, now we
	have to regenerate the list from the bins i.e the result of the third pass will be
	   ----------------------------------------------------------	
	A: | 36 | 48 | 62 | 146 | 152 | 163 | 235 | 237 | 259 | 348 |
	   ----------------------------------------------------------
	
			0	  1   2    3     4   5    6     7   8    9  ---> indices
		  -----|----|----|----|----|----|----|----|----|----|
	bins: |NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|NULL|
		  ---------------------------------------------------
		  
	Now look carefully at the new list A and tell me. The list is sorted now.
	This is how radix sort works.
	 

 Time Complexity of Radix Sort

	Let:
		n = number of elements in the array
		d = number of digits in the largest number
		b = number of bins (base of number system)
		
    General Time Complexity:
		O(d * (n + b))
		
	Explanation:
		In radix sort we perform sorting digit by digit.
		If the largest number has d digits, then the algorithm
		will perform d passes.
		
	In each pass:
		1. We scan all n elements and place them into bins.
		2. We then collect the elements back from the bins.
		
		Since we are using the decimal number system,
		the number of bins b = 10, which is constant.
		
		Therefore the practical time complexity becomes:
		
	Time Complexity = O(d * n)
		
		
 Space Complexity of Radix Sort

	Radix sort requires extra space for storing elements
	temporarily inside bins.

	Space Complexity = O(n + b)

	Where:
		n = number of elements
		b = number of bins

	Since b = 10 (constant in decimal system),
	the space complexity becomes:
	Space Complexity = O(n)
