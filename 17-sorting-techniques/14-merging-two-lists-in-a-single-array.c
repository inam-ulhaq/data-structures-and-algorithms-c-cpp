/*
 Title: Merging Two Lists in a Single Array
 Author: Inam Ul Haq

 Description:

	Merging can also be done when two sorted lists are present inside a
	single array. In this case the first part of the array represents the
	first sorted list and the second part represents the second sorted list.

	Assume that we have the following array:

	A: 2, 10, 18, 20, 23, 4, 9, 19, 25

	Here the first part is a sorted list:
		2, 10, 18, 20, 23

	and the second part is another sorted list:
		4, 9, 19, 25

	So we can consider them as two lists inside one array.

	If the first list starts from index low and ends at mid,
	and the second list starts from mid+1 and ends at high,
	then we can merge them into a single sorted list.

	So we take three indices:

		i -> starting index of first list
		j -> starting index of second list
		k -> starting index of temporary array B

	  ---------------------------------------------------------
	A | 2 | 10 | 18 | 20 | 23 | 4 | 9 | 19 | 25 |
	  ---------------------------------------------------------
	    i                mid   j

	  -------------------------------------------
	B |   |   |   |   |   |   |   |   |   |
	  -------------------------------------------
	    k

------------------------------------------------------------

	Step 1:
		Compare A[i] and A[j]

		2 < 4 so copy 2 to B[k]

	  -------------------------------------------
	B | 2 |   |   |   |   |   |   |   |   |
	  -------------------------------------------
	      k

------------------------------------------------------------

	Step 2:
		Compare 10 and 4

		4 < 10 so copy 4

	B: 2, 4

------------------------------------------------------------

	Step 3:
		Compare 10 and 9

		9 < 10 so copy 9

	B: 2, 4, 9

------------------------------------------------------------

	Step 4:
		Compare 10 and 19

		10 < 19 so copy 10

	B: 2, 4, 9, 10

------------------------------------------------------------

	Step 5:
		Compare 18 and 19

		18 < 19 so copy 18

	B: 2, 4, 9, 10, 18

------------------------------------------------------------

	Step 6:
		Compare 20 and 19

		19 < 20 so copy 19

	B: 2, 4, 9, 10, 18, 19

------------------------------------------------------------

	Step 7:
		Compare 20 and 25

		20 < 25 so copy 20

	B: 2, 4, 9, 10, 18, 19, 20

------------------------------------------------------------

	Step 8:
		Compare 23 and 25

		23 < 25 so copy 23

	B: 2, 4, 9, 10, 18, 19, 20, 23

------------------------------------------------------------

	Step 9:
		The first list has finished. The remaining elements
		of the second list will be copied directly.

		Copy 25.

	  -------------------------------------------
	B | 2 | 4 | 9 | 10 | 18 | 19 | 20 | 23 | 25 |
	  -------------------------------------------

	Now copy all elements of B back into array A.

	Final sorted array:

	A: 2, 4, 9, 10, 18, 19, 20, 23, 25

	This is how we merge two sorted lists present inside
	a single array.
*/

#include <stdio.h>
void marge(int A[],int mid,int high){
	int i=0,j=mid+1,k=0;
	int B[high];
	while(i<=mid && j<high){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}else{
			B[k++]=A[j++];
		}
	}
	while(i<=mid){
		B[k++]=A[i++];
	}
	while(j<high){
		B[k++]=A[j++];
	}
	
	for(i=0;i<high;i++){
		A[i]=B[i];
	}
	
}

int main(){
	int A[]={2,4,9,10,18,20,23,4,9,19,25};
	
	marge(A,6,11);
	
	for(int i=0;i<11;i++){
		printf("%d ",A[i]);
	}
}