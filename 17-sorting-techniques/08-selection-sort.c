 Title: Selection Sort
 Author: Inam Ul Haq
 Description:
	The first question here arises is why we call this is selection sort? So the
	answer is in this sorting technique we are selecting a position and find out 
	an element for that position and insert it there. So i will understand this
	by taking list of unsorted element i.e 8, 6, 3, 2, 5, 4. We will sort these 
	elements and understand how selection sort working.
	
	let' worte these element vertically i.e 
	-----
	| 8 | 0 ->index
	-----
	| 6 | 1
	-----
	| 3 | 2
	-----
	| 2 | 3 
	-----
	| 5 | 4
	-----
	| 4 | 5
	-----
	
	This will also performe passes, So in first pass we will select first position 
	and let it be index 0. So select first position as index 0 and finde sutible 
	element for it, as we are sorting the element in accending order so we will 
	try to find the first smallest element in the list and insert at on that first
	position. 
	
	Now as we are selecting a position, so first we will take a position pointr i.e p
	and the second thing as we are searching for minimume element in the list so we will 
	need two more pointers i.e one will pointing to the current minimume element and 
	one for searching further in the list as may be in the further list more smaller 
	element is present then that one. So let k is the pointer for the current smallest
	element and j is the pointer the will move in the list. Then the list will look like
	
	    K   -----
	j---> \ | 8 | 0 -->p (position pointer)
			-----
			| 6 | 1
			-----
			| 3 | 2
			-----
			| 2 | 3 
			-----
			| 5 | 4
			-----
			| 4 | 5
			-----
	We will assume that the current smallest element in the list is 8 as that 
	is the starting point, so k will point on that element, but remeber one 
	thing all the above pointer will store the indexes of the elements. Now 
	let's move j to next element i.e 6 and compare it with current smallest 
	element i.e 8 so 6 is smaller than 8 therefore we will update k our current
	smallest element by moving i.e we will assigne the index of new smallest 
	element to k.
	
	        -----
            | 8 | 0 -->p (position pointer)
		 K	-----
	j---> \	| 6 | 1
			-----
			| 3 | 2
			-----
			| 2 | 3 
			-----
			| 5 | 4
			-----
			| 4 | 5
			-----	
	Now move j to next element 3 and compare with current smallest element i.e 6 
	so again the 3 is smaller so we will update our current smallest element i.e
	        -----
            | 8 | 0 -->p (position pointer)
		 	-----
	    	| 6 | 1
		 K	-----
	j---> \ | 3 | 2
			-----
			| 2 | 3 
			-----
			| 5 | 4
			-----
			| 4 | 5
			-----
	Now again move j and compare so again 2 is smaller then 3 therefore we will update
	
	        -----
            | 8 | 0 -->p (position pointer)
		 	-----
	    	| 6 | 1
		 	-----
			| 3 | 2
		 K	-----
	j---> \	| 2 | 3 
			-----
			| 5 | 4
			-----
			| 4 | 5
			-----	
	Now let's j further to the next element i.e 5 and compare it with current smallest
	element i.e 2. So 5 is not smaller than 2 there for we will not update the current
	smallest element.
	        -----
            | 8 | 0 -->p (position pointer)
		 	-----
	    	| 6 | 1
		 	-----
			| 3 | 2
		 K	-----
	      \	| 2 | 3 
			-----
		j-->| 5 | 4
			-----
			| 4 | 5
			-----
			
	Now move j to next element 4 and compare it with current smallest element 2
	so still 2 is smaller, so we will not update i.e:
	        -----
            | 8 | 0 -->p (position pointer)
		 	-----
	    	| 6 | 1
		 	-----
			| 3 | 2
		 K	-----
	      \	| 2 | 3 
			-----
			| 5 | 4
			-----
		j-->| 4 | 5
		    -----
		    
	Now if we move j to next location so now j will pointing to invalid position 
	so we will stop moving j. 
	So we have fenished the entire list and found out the smallest element. Just 
	observe one thing, just we found out which is manimume element and we got the
	index of that element and not swap any element till now. 
	Now what to do? Interchange the samllest element with the element that is present
	the selected position i.e to pointer p is pointing. So 8 and 2 will interchange 
	and the new list will look like:
		
		
        	-----
            | 2 | 0 
		 	-----
	    	| 6 | 1
		 	-----
			| 3 | 2
			-----
	        | 8 | 3 
			-----
			| 5 | 4
			-----
		    | 4 | 5
		    -----
	So this is the result of first pass and we got the smallest element in the list 
	as result. So in first pass one element is sorted. 
	Analysis, in first pass we compare how many element? n-1, and performe how many
	swaps? just one. 
	
	Now in second pass we will select the next position i.e second position at index 1.
	mean put position pointer and current pointer there and will found out a smallest 
	element in the reaming unsorted list. We will check the sorted element i.e 2 again
	with any element because it's already on their perfect position. 
	
	So the starting of second pass will look like:
		
	        -----
            | 2 | 0 
		 k	-----
	  j--> \| 6 | 1 -->p (position pointer)
		 	-----
			| 3 | 2
		 	-----
	      	| 8 | 3 
			-----
			| 5 | 4
			-----
		    | 4 | 5
		    -----
		
	Now again move j to the next element and compare with current smallest 
	element:
		
			-----
            | 2 | 0 
		 k	-----
	       \| 6 | 1 -->p (position pointer)
		 	-----
		j-->| 3 | 2
		 	-----
	      	| 8 | 3 
			-----
			| 5 | 4
			-----
		    | 4 | 5
		    -----
		    
	So compare 6 with 3 as 3 is smaller than 6 so we will update our current smllest
	element i.e and move j to the next element.
	
			-----
            | 2 | 0 
		  	-----
	        | 6 | 1 -->p (position pointer)
		 k	-----
		   \| 3 | 2
		 	-----
	    j-->| 8 | 3 
			-----
			| 5 | 4
			-----
		    | 4 | 5
		    -----
	So now we will compare 3 with 8, so 3 is samller, so don't need to update
	the current smallest element but just move j to the next element i.e 5. 
	Now again do this so again 3 is smaller so no need to update but just move 
	j to 4 and compare, so again 3 is the smallest element so don't need to update
	the smallest element and as the we check again the whole unsorted list and 
	find out the smallest element so we will interchange it with element present 
	on the selected position i.e 6.
	
			-----
            | 2 | 0 
		  	-----
	        | 3 | 1 
		 	-----
		    | 6 | 2
		 	-----
	    	| 8 | 3 
			-----
			| 5 | 4
			-----
		    | 4 | 5
		    -----
	In the result of second pass we get the second smallest element in the list. 
	Analysis, in second pass how many comparision we did? n-2, because we did not
	check the first element that was alredy sorted. And how many swaps we done? 
	Again only one swap we did.
	
 1
    Third Pass

    Now let's perform the third pass. We will select the third position
    (index 2) and find the smallest element in the remaining unsorted list.

    Current list after second pass:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 6 | 2 --> p (position pointer)
        -----
        | 8 | 3
        -----
        | 5 | 4
        -----
        | 4 | 5
        -----

    Assume 6 is the current smallest element, so pointer k will point to it.
    Pointer j will move forward to search for a smaller element.

    Compare 6 with 8 -> 8 is larger, so no update.

    Move j forward and compare 6 with 5 -> 5 is smaller,
    therefore update k so that it points to index 4.

    Move j again and compare 5 with 4 -> 4 is smaller,
    therefore update k so that it points to index 5.

    Now j moves to an invalid position and the search stops.

    We found the smallest element = 4.

    Now swap the smallest element (4) with the element at
    the selected position (6).

    New list after third pass:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 4 | 2
        -----
        | 8 | 3
        -----
        | 5 | 4
        -----
        | 6 | 5
        -----

    Analysis:
    Comparisons = n - 3
    Swaps = 1


    Fourth Pass

    Now select the fourth position (index 3).

    Current list:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 4 | 2
        -----
        | 8 | 3 --> p
        -----
        | 5 | 4
        -----
        | 6 | 5
        -----

    Assume 8 is the current smallest element.

    Compare 8 with 5 -> 5 is smaller,
    so update k to index 4.

    Compare 5 with 6 -> 5 is still smaller,
    so no update.

    Smallest element = 5.

    Swap 5 with 8.

    New list:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 4 | 2
        -----
        | 5 | 3
        -----
        | 8 | 4
        -----
        | 6 | 5
        -----


    Fifth Pass

    Select the fifth position (index 4).

    Current list:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 4 | 2
        -----
        | 5 | 3
        -----
        | 8 | 4 --> p
        -----
        | 6 | 5
        -----

    Compare 8 with 6 -> 6 is smaller.

    Update k to index 5.

    Swap 6 with 8.

    Final sorted list:

        -----
        | 2 | 0
        -----
        | 3 | 1
        -----
        | 4 | 2
        -----
        | 5 | 3
        -----
        | 6 | 4
        -----
        | 8 | 5
        -----


    Final Analysis of Selection Sort

    Number of passes = n - 1

    Total comparisons:
        (n-1) + (n-2) + (n-3) + ... + 1
        = n(n-1)/2

    Total swaps:
        Only 1 swap per pass
        = n - 1 swaps

    Time Complexity:
        Best Case    = O(n^2)
        Average Case = O(n^2)
        Worst Case   = O(n^2)

    Selection sort always checks the entire unsorted list
    to find the smallest element for each position.
