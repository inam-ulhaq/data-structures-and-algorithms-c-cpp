/*
 Title: Merging 
 Author: Inam Ul Haq

 Description:
	Merging is the process of combining two or more sorted lists into a single
	sorted list. How do we merge?

	Assume that we have two lists:

	A: 2, 10, 18, 20, 23
	B: 4, 9, 19, 25
	
	Remember, when we combine two lists it is not necessary that both lists
	have the same number of elements. They may or may not be the same.
	In the above example, list A has 5 elements while list B has 4 elements.
	However, each list must contain at least one element.
	
	We can merge them by comparing their elements and copying the smallest
	one into a third array.
	
	For this purpose we take i and j and place them at the starting index of
	lists A and B respectively. We also take another list C and place k at
	its starting index.
	
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   i							 j
	   
	  -------------------------------------
	C |   |   |   |   |   |   |   |   |   |
	  -------------------------------------
	  	k
	  	
	Remember, if the sizes of A and B are m and n respectively, then the size
	of C will be m + n.
	
	Now in the first step compare A[i] and B[j] and copy the smaller one to C[k].
	Then increment the index from where the element is copied and also increment
	k to the next index. Since 2 is smaller than 4, 2 will be copied to C and
	i and k will be incremented.
	
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   		i						  j
	   
	  -------------------------------------
	C | 2 |   |   |   |   |   |   |   |   |
	  -------------------------------------
	  		k
	  		
	Now again compare A[i] with B[j] and repeat the above process.
	Since 4 < 10, 4 will be copied.
	
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   		i							  j
	   
	  -------------------------------------
	C | 2 | 4 |   |   |   |   |   |   |   |
	  -------------------------------------
	  			k
	
	Now third step:
		9 < 10 so copy 9 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   		i								  j
	   
	  -------------------------------------
	C | 2 | 4 | 9 |   |   |   |   |   |   |
	  -------------------------------------
	  				k
	  				
	Now fourth step:
		10 < 19 so copy 10 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   			 i							  j
	   
	  --------------------------------------
	C | 2 | 4 | 9 | 10 |   |   |   |   |   |
	  --------------------------------------
	  					 k
	  					 
	Now 5th step:
		18 < 19 so copy 18 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   			      i						   j
	   
	  ---------------------------------------
	C | 2 | 4 | 9 | 10 | 18 |   |   |   |   |
	  ---------------------------------------
	  						  k
	  						  
	Now 6th step:
		19 < 20 so copy 19 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   			      i						       j
	   
	  ----------------------------------------
	C | 2 | 4 | 9 | 10 | 18 | 19 |   |   |   |
	  ----------------------------------------
	  						       k

	Now 7th step:
		20 < 25 so copy 20 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   			           i						j
	   
	  -----------------------------------------
	C | 2 | 4 | 9 | 10 | 18 | 19 | 20 |   |   |
	  -----------------------------------------
	  						       		k
	  						       		
	Now 8th step:
		23 < 25 so copy 23 to C[k].
		
	  ------------------------		-------------------
	A | 2 | 10 | 18 | 20 | 23 |    B | 4 | 9 | 19 | 25 |
	  ------------------------ 		-------------------
	   			           		i				    j
	   
	  ------------------------------------------
	C | 2 | 4 | 9 | 10 | 18 | 19 | 20 | 23 |   |
	  ------------------------------------------
	  						       			 k
	  						       			 
	Now 9th step:
		List A has finished. There are no more elements in A to compare
		with B. Since list B is already sorted, the remaining elements
		can be copied directly.
		
		So copy 25 to C[k].
		
	  -------------------------------------------
	C | 2 | 4 | 9 | 10 | 18 | 19 | 20 | 23 | 25 |
	  -------------------------------------------
	  						       			 k
	
	So this is how we can merge two sorted lists into a single sorted list.
	
	Now let me write code for the above approach.
*/

#include <stdio.h>

void marge(int A[],int B[],int m, int n){
	int i,j,k;
	i=j=k=0;
	int C[m+n];
	while(i<m && j<n){
		if(A[i]<B[j]){
			C[k++]=A[i++];
		}else{
			C[k++]=B[j++];
		}
	}
	while(i<m){
		C[k++]=A[i++];
	}
	while(j<n){
		C[k++]=B[j++];
	}
	for(i=0;i<m+n;i++){
		printf("%d ",C[i]);
	}
	
}
	
	
int main(){
	
	int A[]={2,10,18,20,23};
	int B[]={4,9,19,25};
	marge(A,B,5,4); // 5 and 4 are the sizes of the lists.
	return 0;
}
						       			 
/* 
 Analysis:
	To analysis that tell me what is the main work that we are doing here? 
	We are just copying the elements, but how many elements? m elements form 
	one list and n elements form another list. So the time complexity is m+n.
*/	       			 