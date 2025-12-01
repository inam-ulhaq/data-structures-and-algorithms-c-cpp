// Title: Finding Sum Pairs in Unsorted Sequence of Numbers
// Author: Inam Ul Haq
//
// Description:
// 	The function "sumPairs()" finds unique pairs of numbers within an unsorted list 
// 	that sum up to a specific 'key' value.
// 
// How It Works:
// 1. The function first scans the list to determine the maximum value ('maxVal').
// 2. A frequency array (used as a hash map) is created using `calloc`, sized 
//    `maxVal + 1`, and all elements are initialized to zero.
// 3. It iterates through the input list once. For each element, it calculates 
//    its complement ('target' = 'key' - current_element).
// 4. It checks if the 'target' value has already been encountered (by checking its 
//    count in the hash map) and if it is within valid bounds. If found, a pair is printed.
// 5. Finally, the function increments the count for the current element in the hash map.
// 
// Time Complexity Analysis:
// 1. Finding 'maxVal' takes O(n) time, where 'n' is the length of the list.
// 2. Allocating and initializing the hash map takes O(maxVal) time or constant time O(1) 
//    depending on specific memory implementation, but the initialization loop is O(maxVal).
// 3. The main loop iterates exactly 'n' times. Inside the loop, hash map lookups 
//    and insertions (array accesses) take constant time O(1).
// 4. The overall time complexity is dominated by the linear passes: O(n + maxVal). 
//    In many practical cases where maxVal is reasonably proportional to n, this is O(n).
//
// Space Complexity Analysis:
// The space complexity is O(maxVal) because memory is allocated proportional to the 
// largest value in the input list.




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

void sumPairs(struct Array *list ,int key){
	int maxVal=0;
	for(int i=0;i<list->length;i++){
		if(list->array[i]>maxVal){
			maxVal=list->array[i];
		}
	}
	int *hashMap=calloc((maxVal+1),sizeof(int));
	
	for(int i=0;i<list->length;i++){
		int currVal=list->array[i];
		int target=key-list->array[i];
		if(target>=0 && target<=maxVal && hashMap[target]>0)
			printf("(%d , %d)\n",target,list->array[i]);
		
		hashMap[currVal]++;
	}
	free(hashMap);
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
	sumPairs(&list,key);
	
	
	
	
	freeList(&list);
	return 0;
}