// Title: Finding Duplicates in an Unsorted List of Numbers
// Author: Inam Ul Haq
//
// Description:
// 	"unsortedDuplicates()" finds duplicates in an unsorted list of non-negative numbers
//  using a frequency counting method (hash table implemented via an auxiliary array).
// 
// How It Works
// 1. Find the maximum value (M) in the input list.
// 2. Allocate an auxiliary integer array (a simple hash table) of size M+1 and initialize to zero.
// 3. Iterate through the input list, using each element's value as an index to increment the counter in the auxiliary array.
// 4. Iterate through the auxiliary array to print elements with a count greater than one.
// 
// Time complexity
// The time complexity is dominated by the linear passes through the input list (N elements)
// and the auxiliary array (M elements, where M is the maximum value).
// 
// Let N be the number of elements in the list and M be the maximum value in the list.
// 
// Finding the maximum value: O(N)
// Initializing and traversing the auxiliary array: O(M)
// Counting frequencies: O(N)
// Printing results: O(M)
// 
// The total time complexity F(N, M) is O(N) + O(M) + O(N) + O(M), which simplifies to O(N + M).
// 
// F(N, M) = O(N + M)




#include <stdio.h>
#include <stdlib.h>

struct Array{
	int *array;
	int size;
	int length;
};

void initList(struct Array *list,int size){
	list->size=size;
	list->array=(int *)malloc(size * sizeof(int));
	if (list->array == NULL) {
    	printf("Memory allocation failed!\n");
    	exit(1);
	}
	list->length=0;	
}
void freeList(struct Array *list){
	free(list->array);
	list->array=NULL;
}

void unsortedDuplicates(struct Array *list){
	int size=0;
	for(int i=0;i<list->length;i++){
		if(size<list->array[i]){
			size=list->array[i];
		}
	}
	int *bitArray=malloc((size+1)*sizeof(int));
	for(int i=0;i<=size;i++)
		bitArray[i]=0;
	
	for(int i=0;i<list->length;i++){
		int index=list->array[i];
		bitArray[index]++;
	}
	
	for(int i=0;i<=size;i++){
		if(bitArray[i]>1){
			printf("%d is %d times occured\n",i,bitArray[i]);
		}
	}
	
}



int main(){
	int size;
	printf("List size: ");
	scanf("%d",&size);
	
	struct Array list;
	initList(&list,size);
	printf("List elements: \n");
	for(int i=0;i<size;i++){
		scanf("%d",&list.array[i]);
	}
	list.length=size;
	
	printf("Duplicates are:\n");
	unsortedDuplicates(&list);
	
	
	
	freeList(&list);
	return 0;
}