 Title: Bubble Sort
 Author: Inam Ul Haq
 Description:
	To understand bubble sort we will take some elements i.e. 8,5,7,3,2 and we
	will write this vertically i.e
	
	8
	5
	7
	3
	2
	
	We have to sort these elements, so let's start working on this. It will 
	compare consecitive paire of element every time, and if the first element
	is greater than sencond element then it will interchange the elements. So
	this will compare 8 with 5, and as 8 is greater so it will swap 8 and 5.
	Then it will compare 8 with 7, and again 8 is greater so it will swap them.
	So it will compare all posible paires of elements and if swaping is required
	it swap it. And once it compare all the posible pairs one time that as know 
	as pass.
	
	i.e first pass:
		
		8<- +   5     5    5       5
			|   8<-+  7    7       7
		5<- +      |  8<-+ 3       3
		7       7<-+     | 8<-+    2
		3       3     3<-+    |    8 
		2       2     2    2<-+     
		
	The number of element is 5 therefore all possible pairs are 4, So I compare 
	all possible pairs, And when all elements are compare once that is called as
	pass, mean we are going through the list, and this was first time so first 
	pass is done, then what is the result? one element is sorted. Which element
	is sorted? the first greatest element in the list i.e 8. Now little bit 
	analysis: There are 5 elements and we done 4 comparisions because for n 
	elements there n-1 maximume pairs. So for n elements n-1 comparision will be
	done. Now what about swaps? For every comparision one swap can be done max and 
	manimume zero, so as we are considring worst case so for 4 comparisions 4 swaps
	are done and we already saw that above. So as all elements are not sorted just 
	one element is sorted therefor will continue this process till all the elmenets 
	are sorted. So let's perform the second pass:
	
		
		5<- +   5     5       5
			|   7<-+  3       3
		7<- +      |  7<-+    2
		3       3<-+     |    7
		2       2     2<-+    8 
		8       8     8  
	
	If you analyse  here we not compare 7 with 8 which can be the last comparision
	because 8 is already sorted and comparision of sorted elements have no use. So
	we will avoid the comparisions of sorted elements. In the first pass we was done
	4 comparision but here as the last one is avoided so we done 3 comparisions only
	and therefore the maximume swaps is also 3, remember we performe only two swaps 
	but at most how many maximume swaps are possible? 3 there for we will consider 
	mixmume one not the actuall one. And till now two elements are sorted i.e 7 and 
	8. So let's move to 3rd pass:
		
		5<- +   3     3 
			|   5<-+  2  
		3<- +      |  5 
		2       2<-+  7 
		7       7     8 
		8       8    
		
	In the 3rd pass as the number of all unsorted elements are 3 so we done 2 comparisions
	and 2 swaps and get 3 sorted elements. Till we get 3 sorted elements out 5 with help of
	3 passes, so 3 elements are unsorted still, so let performe one more pass and see what 
	is the result.
	4th pass:
		
		3<- +       2
			|       3  
		2<- +       5 
		5           7 
		7           8 
		8       
	
	So in 4th sort we done only one comparision and performe one swap and finlly we get
	a get the list of sorted numbers.
	
 Analysis:
 	
	Number of passes:
		The total number of elements are 5 and till now we perform 4 passes, so
		for 5 elements their are 4 passes, then how many passes will be done for
		n element? As for 5 we performe 4 therefore for n elements n-1 passes will
		be performe. 
		
	Number of comparisions:
		See for first pass we performe 4, for 2nd 3, for 3rd two and for 4 we performe
		1 comparision, so it's like 1+2+3+4 so as the number of elements are 5 so these
		are for 5 elements. Now what if the elements are n? As for 5 element it's like
		1+2+3+4 so 5 till 4 therefore for n it will be 1+2+3+4+5...+n-1, so for n it will
		be till n-1. And we can also wrote it like 1+2+3+4+5...+n-1= (n(n-1))/2.
		and this is equal to (n^2 - n )/2. As the heighest degree polynomial is n^2 
		therefore we will assume that the number of comparisions is quadratic i.e O(n^2).
	
	Time compexity:
		As we saw before the time complexity of any sorting algorithm is based on the 
		number of comparisions and here the number of comparisions is n^2 therefore the
		time complexity is also O(n^2).
		
		
	Number of sawps:
		Actually these are the maximume number of swaps can be done. So as we see
		above for 5 elements swaps are 1+2+3+4 so n elements maximume number of 
		swaps will be 1+2+3+4+5...+n-1 and this is again O(n^2).
	
	So till now we just analyse the number of comparisions and number of swaps and 
	i will check the other after wirtting the code.
	
	So let's write the code. First of all we have to do? we have to performe n-1 
	passes, So something to repeat that is passes for n-1 time. So for this we will
	use for loop. Now what we are doing in passes? we are comparing n-1 pairs of 
	elements, So agian we need something to repeat that is going through the list 
	in each pass. So therefore we will use one more for loop. i.e
	
	void bubbleSort(int A[],int n){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){ // subbtracting i form n because we don't 
				if(A[j]>A[j+1]){      // want to resort the already sorted elements.
					int temp=A[j];    
					A[j]=A[j+1];
					A[j+1]=temp;
				}
			}
		}
	}
	
	The above algorithem will perform bubble sorting on list of elements. We
	take in both the condition n-1 not n because in first condition n-1 is due
	to n-1 passes while in second condition n-1 is due to for n number of elements
	there will be only n-1 number of pairs, and there we are also subbtracting
	i ecach time is because of in first pass one element will be sorted, in
	second two element and in 3rd three elements will be sorted and so on so 
	therefore just n-1 will be not enough but also subtractting the i i.e. n-1-i.

	Adoptive:
		What that above algorithm will dose if the list is already sorted? The 
		algorithm dosn't detecte that the numbers are already sorted but just 
		performe iteration over the list, So it's mean that bubble sort is not 
		adoptive by nature or self adoptive. Can we make it adoptive? yes we can
		dectect this as if there is no swaping performed for the whole single pass
		then it's mean that the list is already sorted. We can do this by just making 
		a flag i.e
		
		
	void bubbleSort(int A[],int n){
		int flag=0;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){ 
				if(A[j]>A[j+1]){
			
					int temp=A[j];    
					A[j]=A[j+1];
					A[j+1]=temp;
					flag=1;
				}
			}
			if(flag==0){
				break;
			}
		}
	}
	
	Now we make the algorithm adoptive. But what will be the time complexity now if the 
	list is already sorted? As that will be dectected after first pass and first pass 
	talk n units of time to be perfome therefor the time complexity will be n i.e O(n).
	
	Stable:
		As we are swaping whenever the first element is greater then second so if the 
		pair of element is equal then swap will not performed therefore bubble sort is 
		stable.
		
	Bubble Sort for K Largest Elements:
		See we get one element in first pass, get 2 sorted element in 2nd pass and get 3
		3 sorted elements in 3rd pass. So for Kth pass we will get kth sorted elements 
		therefore i.e if we need first three largest elements we will perform 3 passes.
		 
		 
	Why this is called is bubble sort?
		See if we are thrown something heavier i.e stone to water then it goes down in
		the waters and the bubbles are coming to the surface as they are lighter. here
		if look to these elements i.e.
		
		8
		5
		7
		3
		2
			Then 8 is the heaviest element so goes down and the lighter elements i.e 2 
		are like comming to the surface, As here also the larger elements going down
		and the smaller elmenet are comming up so it behaive like bubbles in water 
		therefore we called this bubble sort. 
		
	Wrote by:
			 Inam Ul Haq
						 The Ends.
	
		