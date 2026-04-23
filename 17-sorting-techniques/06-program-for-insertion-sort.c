 Titile: Program for Insertion Sort
 Author: Inam Ul haq
 Description:
 	Assume that we have some number in array i.e
 	---------------------
	| 8 | 5 | 7 | 3 | 2 | 
	---------------------
	 0    1   2   3   4 
	 
	Here the indices are form 0 to 4 but the elements are 5, So to sort this 
	we will perform passes, how many passes? n-1 i.e 4. In this example form 
	which element we will start insertion? form 5 which at index 1, So we will 
	use loop, start from index 1 because element at index 0 is already sorted, 
	and we will iterate to i<n while n==5, this is becasue we are performing n-1
	passes, and here if you look total 4 passes will be done for 5 element so 
	
	
	void insertionSort(int A[],int n){
		for(int i=1, i<n;i++){
			// this loop is for passes.
		}
	}


	Now assume that we have an array of number 6, 8, 12, 14, 20, and 10 here the 
	numbers form 6 to 20 are sorted and at the last 10 is unsorted i.e
	
	-----------------------------
	| 6 | 8 | 12 | 14 | 20 | 10 |
	-----------------------------
	  0   1   2    3    4    5
	So assume that i is pointing to index of 10 i.e i==5, then we should to check
	this with all the number in sorted list till they are greater and shift them,
	i will assume the j is pointing on last element in the sorted list i.e index of
	20, which is 4, so j= i-1, as i==5. Now we have to take out the elmenet form 
	index i and check it with element at  index j and if the element at index j is
	greater then shift to j+1 index and then to the element at index j-1 as we done 
	with element at index j. So j will decriment every time till the element at index
	j is greater then form the element that is take out form the unsorted list or j is 
	equal to -1. Because assume that element at index 0 is also greater then the taked
	out element then the element form index 0 will shift to index 1 and j will be 
	decriment form 0 to -1 so -1 is invalid index therefore we have to stop as j==-1.
	And procdure will be done inside every pass. So we will take one another loop inside
	the for loop and continoue it untill j is greater then -1 and A[j] is greater then 
	the taked out element form the unsroted list. i.e
	
	void insertionSort(int A[],int n){
		for(int i=1, i<n;i++){
			int x=A[i]; // take out element form unsorted list.
			int j=i-1;
			while(j>-1 && A[j]>x){
				A[j+1]=A[j];
				j--;
			}
			
			A[j+1]=x;
		}
	}
	
	Remember the value of the inner loop will be stop either the value of A[j]
	is become smaller or j is equal to -1 so in both the case we can't use A[j]
	for the insertion on new element becasue if we use it, then it might be inserted
	on negitive index or replace the smallest value, so therefore we will use 
	A[j+1];
	
	
 Analysis:
 	
	Adoptive:
		Assume that we have a sorted list of some numbers i.e 2, 5, 8, 10. So
		as we know insertio sort starting form 1 onward, so it take out 5 and 
		compare with 2, so 5 is greater therefore no shifting will be done and
		first pass will be completed. Now in second pass 8 will be take out and 
		compare with 5, so again 8 is greater, no shifting will be done and second
		pass will end with just one comparision. Now thrid pass, so take out 10 
		and compare with 8, 10 is greater so again no shifting and and thrid pass
		will also end with just one comparision and with no shifting. So for 4 
		elements 3 passes are done, and everyone only with just one comparision.
		So there for total n-1 comparision is done, so the time complexity is O(n).
		Now as we know that the time complexity of insertion sort is O(n^2) but 
		when the elements are already in sorted form, then the time compleixty is 
		O(n), so we can say that yes the insertion sort is adoptive. But the question
		here is this is adoptive by nature or we make it adoptive like we did in 
		bubble sort by using flag? This is adoptive by nature, we did not make this
		adoptive but this is adoptive by nature because we not used any flag like 
		we used in bubble sort.
		
	Number of swaps: 
		As we seen in the above example if the elements are already sorted then in 
		every pass just one comparision was performed and no shifting is done,
		so no shifting mean no swaping. Therefore for alredy sorted list the number
		of swaps or shifting will be constant i.e O(1).
	
	Stable:
		As we use the condition if the element of sorted list is greater then the 
		element take out from the list of unsorted elements so then only we will 
		shift otherwise no shifting and no comparisions will be done further. So 
		they are equal mean duplicate then also no shifting and further comparisions
		will be done, but the element will be inserted after the that duplicated value
		that is already there in the sorted list so therefore the insertion sort is 
		also stabled. 