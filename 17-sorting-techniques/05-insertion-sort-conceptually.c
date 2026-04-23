 Title: 
 Author: Inam Ul Haq
 Description:
	To explain insertion sort i take array i.e 
	---------------------
	| 8 | 5 | 7 | 3 | 2 | 
	---------------------
	So i have 5 elements in the array now let's performe insertion sort on this.
	So the very first thing i assume that the first element (8) in the array is
	already sorted. So the array will look like:
	----|----------------
	| 8 | 5 | 7 | 3 | 2 | 
	----|----------------
	
	If there is only one  element that obivesly that is sorted, so we assume that 
	the first element is already sorted. Then the remaining elements are not sorted.
	So remaining elements will take out from the array mean form unsorted list and 
	inserted on the left side mean in sorted list. So the procedure is take out an 
	element form the unsorted list and insert in the sorted list. So let' start the 
	process.
	
	first step: 
		assume that there are two list in the array sorted and unsorted. in sorted
		list there are only one element which is 8 while in unsorted list there are
		4 elements starting from 5 to 2 so the first element is 5 in unsorted list 
		therefore i will first take out 5 form unsorted list and insert it in sorted
		list. So as we take out the element form unsorted list the size of sorted 
		list will be increased one element i.e the array will look like:
	--------|------------
	| 8 |   | 7 | 3 | 2 |  and the the element take out is 5.
	--------|------------
	
	So what to do now? compare 5 with the right most element in sorted list i.e 8 
	and if the key element (5) is smaller then the element form the sorted list then
	shift the element of sorted list one position toward right side. Or if the key 
	element is greater the insert the key after the on the right side of first smallest
	element then key element i.e 5.
	So now compare 5 with 8, so 5 is smaller therefore shift 8 one position on the right
	side then the array will look like:
	--------|------------
	|   | 8 | 7 | 3 | 2 | 
	--------|------------
	Now there is nothing more therefore we will insert 5, and the final result will 
	be look like:
	--------|------------
	| 5 | 8 | 7 | 3 | 2 | 
	--------|------------
	let's assume that this is first pass. Now let's analyse the first pass, so how many 
	comparision i did only one and how many shift i did only one i.e shift 8.
	
	Now let's go do the second pass. So take out 7 form the array then array will look 
	like:
	------------|--------
	| 5 | 8 |   | 3 | 2 |    7 is take out.
	------------|--------
	
	Now let's compare 7 with 8 so the key element 7 is smaller therefore we will shift 
	the 8 toward right side one position i.e 
	------------|--------
	| 5 |   | 8 | 3 | 2 |    
	------------|--------
	Now compare 7 with next element in the sorted list i.e 5 so here the key element is 
	not smaller but it's greater then the element form the sorted list, therefore we will
	not shift the element 5 but we will insert the key element in vecant position form where
	the last element was shifted i.e 8 so the final result will look like:
	------------|--------
	| 5 | 7 | 8 | 3 | 2 |    
	------------|--------
	This was second pass now let's analyse the second pass, so how many comparision we did?
	two i.e with 7 with 8 and 7 with 5, so we did two comaprisions in second pass. Now how many
	elements we shift in second pass? only one in this case, but how many can be did if atmost?
	atmost two can be done in second pass, i.e 5 is not smaller then key element then 5 will 
	be also shifted but here it's smaller therefore it not shifted.
	
	Now let's performe the third pass. I will take out 3 from the unsorted list and insert it 
	in the sorted list. So the array will look like:
	----------------|----
	| 5 | 7 | 8 |   | 2 |    3 is taked out.
	----------------|----
	
	now compare 3 with 8 so the key element is smaller therefore 8 will be shifted, and again
	compare key (3) with next element i.e 7 so again key is smaller therefore 7 will be also 
	shifted one position on the right side. And after the shifting again key will be compare 
	with the next element i.e 5 so again key is smaller which 3 therefore 5 will also shifted
	and the last no more element is there in the sorted list therefore the key will inserted.
	And the final result will look like:
	----------------|----
	| 3 | 5 | 7 | 8 | 2 |   
	----------------|----
	Now let's analyse the third pass, so how many comparision we did? we did three comparisions
	and what shifting? total three elements are shifted and atmost three elements can be shifted.
	
	Now let's performe the fourth pass, i.e take out 2 form the unsorted list and insert at in  
	the sorted list list, so the array will look like:
	--------------------|
	| 3 | 5 | 7 | 8 |   |  2 is taked out.  
	--------------------|
	
	Now let's compare 2 with all the element one by one till in the sorted list till a the elements
	form the list is greater than two and shfit them one position toward right side if the element
	form the list is greater, and as a smaller value appeare so stope comparing and insert the key 
	at that position. If we look the list is sorted and the smallest value in the sorted list is 3 
	and 3 is greater form the key value so no smaller value is there in the sorted list therefore 
	all the elements will be shifted the sorted list one position toward right side  i.e 
	--------------------|
	|   | 3 | 5 | 7 | 8 |   
	--------------------|
	Now insert 2 just before 3 because there is nothing more before 3. So the final result 
	will look like:
		
	--------------------|
	| 2 | 3 | 5 | 7 | 8 |   
	--------------------|
	This was the 4th pass, now let's analyse this. So how many comparisions are done? total 4 and 
	how many element are shifted? The element shifted are also 4.
	
	
	Now let's do some analysis: 
	
	Number of passes:
		How many passes we performe? For 5 elements we performe 4 passes mean for 8 elements
		we will perform 7 passes, so how many passes will be needed for n elements? for n elements
		n-1 pass will be required.
		
	Number of comparisions:
		For first pass we perfrome 1 comparision, for 2nd pass 2, for 3rd pass 3 comparisions and 
		4th pass 4 comparisions are done. So i will add them i.e
		1+2+3+4 . As for 5 element 4 passes therefore therefore the comparision are also to 1+2+3+4, so
		for n element there will be n-1 passes so there for it will be added like:
		1+2+3+4....+n-1. So it like the addition of first n natural numbers i.e n(n-1)/2.
		so it's  again equal to O(n^2). It's mean the number of comparision here is qudratic 
		mean n^2.
		
	Time complexity:
		As the time complexity of algorithm is the number of comparision in of the algorithm and 
		the number of comparision of insertion sort is n^2 so therefore time complexity of 
		insertion sort is also n^2 so the maximume time taken by insertion sort is O(n^2).
	
	Number of swaps:
		Number of swaps is also same as number of comparisions i.e in firs pass maximume can
		be 1, in 2nd 2, in 3rd 3 and in 4th pass maximume swaps can 4, so again it's like 
		1+2+3+4 for 5 elements then for n elements it will be 1+2+3+4...+n-1 so this also 
		O(n^2).
	
		
	
		