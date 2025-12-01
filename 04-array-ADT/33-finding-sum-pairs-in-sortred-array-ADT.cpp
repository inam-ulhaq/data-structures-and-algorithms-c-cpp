// Title: Finding Sum Pairs in a Sorted Sequence of Numbers
// Author: Inam Ul Haq
//
// Description:
// 	The function "sumPairsInSorted()" finds unique pairs of numbers within a *sorted* list 
// 	that sum up to a specific 'key' value using the two-pointer technique.
// 
// How It Works:
// 1. Two pointers, 'i' and 'j', are initialized to the start (0) and end (length-1) 
//    of the sorted list, respectively.
// 2. The function enters a while loop that continues as long as 'i' is less than 'j'.
// 3. In each iteration, it sums the elements at the 'i' and 'j' indices.
// 4. If the sum equals the 'key', the pair is a match and both pointers are moved 
//    inward (i++, j--).
// 5. If the sum is greater than the 'key', the right pointer 'j' is moved leftward 
//    (j--) to find a smaller sum.
// 6. If the sum is less than the 'key', the left pointer 'i' is moved rightward 
//    (i++) to find a larger sum.
// 
// Time Complexity Analysis:
// 1. The approach uses a single linear pass through the data.
// 2. The loop runs at most 'n' times (where 'n' is the list length) as the pointers 
//    converge from opposite ends.
// 3. Inside the loop, all operations (comparisons, additions, increments/decrements) 
//    are constant time O(1).
// 4. The overall time complexity is dominated by the single pass, resulting in O(n).
//
// Space Complexity Analysis:
// The space complexity is O(1).
// 1. The algorithm operates in-place on the existing array.
// 2. It requires only a constant, fixed amount of extra memory for the variables 
//    'i', 'j', and 'key', regardless of the input size 'n'.




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

void sumPairsInSorted(struct Array *list ,int key){
	int i=0,j=list->length-1;
	while(i<j){
		if(list->array[i]+list->array[j]==key){
			printf("(%d,%d)\n",list->array[i],list->array[j]);
			i++;
			j--;
		}else if(list->array[i]+list->array[j]>key){
			j--;
		}else{
			i++;
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
	int key;
	printf("Enter key: ");
	scanf("%d",&key);
	
	printf("Pairs are:\n");
	sumPairsInSorted(&list,key);
	
	
	
	
	freeList(&list);
	return 0;
}