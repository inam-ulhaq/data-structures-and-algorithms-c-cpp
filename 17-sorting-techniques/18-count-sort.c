/*
 Title: Count Sort
 Author: Inam Ul Haq
 Description:

	Count Sort is an index-based sorting algorithm. The main idea behind
	this algorithm is not to compare elements like other sorting algorithms
	(for example Bubble Sort or Quick Sort). Instead, it counts how many
	times each element appears in the list.
	
	Because of this reason, Count Sort works very fast, but it requires
	extra memory.
	
	Concept:
	
	Assume that we have a list of elements:
	
	A = {5, 2, 8, 9, 14, 5, 7, 11, 2, 5}
	
	The first step in Count Sort is to find the maximum element in the list.
	The reason is that we need to create another array called the count array,
	and its size depends on the maximum element.
	
	If the maximum element is k, then the size of the count array will be
	(k + 1). Each index of this array represents a possible element value.
	
	In our example, the maximum element is 14, therefore we create a count
	array of size 15.
	
	Initially all values in the count array are set to zero.
	
	Idea of Counting:
	
	Now we scan the original list from beginning to end.
	
	Whenever we encounter an element x in the list, we go to index x in the
	count array and increase the value stored there by 1.
	
	This means the index of the count array represents the element value,
	and the value stored at that index represents how many times that
	element occurs in the list.
	
	For example:
	If C[5] = 3, it means the element 5 appears three times in the list.
	If C[2] = 2, it means the element 2 appears two times.
	
	Reconstructing the Sorted List:
	
	After counting all elements, the count array contains the frequency
	of each element.
	
	Now we rebuild the original array.
	
	We scan the count array from the smallest index to the largest index.
	If the value at an index is greater than zero, we copy that index
	into the original array. We repeat this process as many times as the
	value stored at that index.
	
	In this way, elements are placed in increasing order automatically.
	
	Final Sorted List:
	
	2, 2, 5, 5, 5, 7, 8, 9, 11, 14
	
	Important Observation:
	
	Count Sort is very fast because it does not use comparisons between
	elements. However, it requires extra memory for the count array.
	If the maximum element in the list is very large, the count array
	will also become very large, which increases memory usage.
	
	Therefore, Count Sort is most efficient when the range of elements
	is not very large.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void countSort(int A[],int n){
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		if(max<A[i]){
			max=A[i];
		}
	}
	int *c=calloc((max+1),sizeof(int));
	
	for(int i=0;i<n;i++){
		int index=A[i];
		c[index]++;
	}
	
	for(int i=0,j=0;i<=max;){
		if(c[i]>0){
			A[j++]=i;
			c[i]--;
		}else{
			i++;
		}
	}
	
	
}

int main(){
	int A[]={5,2,8,9,14,5,7,11,2,5};
	int n=10;
	countSort(A,n);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	
}