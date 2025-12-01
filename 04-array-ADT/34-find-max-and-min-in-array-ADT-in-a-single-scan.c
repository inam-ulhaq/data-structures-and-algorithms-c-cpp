// Title: Finding Max and Min Number in a Single Scan
// Author: Inam Ul Haq
//
// Description:
// 	The function "maxAndMin()" efficiently determines both the maximum ('max') 
// 	and minimum ('min') values present within an unsorted input list in a single pass.
// 
// How It Works:
// 1. The 'min' and 'max' variables are initialized using the very first element 
//    of the array to provide a starting baseline.
// 2. A single 'for' loop iterates through the list starting from the second element.
// 3. For each element encountered:
//    - It checks if the current element is less than the current 'min'. If so, 'min' is updated.
//    - Otherwise (using 'else if'), it checks if the current element is greater 
//      than the current 'max'. If so, 'max' is updated.
// 4. By the end of the loop, both the absolute maximum and minimum values of the 
//    entire list have been identified.
// 
// Time Complexity Analysis:
// 1. A single loop traverses 'n-1' elements of the list exactly once.
// 2. Each iteration involves a maximum of two comparisons and a potential assignment 
//    (constant time operations O(1)).
// 3. The overall time complexity is linear, O(n), as it scales directly with the 
//    number of elements 'n'.
//
// Space Complexity Analysis:
// The space complexity is O(1).
// 1. The algorithm operates in-place and does not allocate additional memory 
//    proportional to the input size.
// 2. It only uses a fixed number of integer variables ('min', 'max', 'i') for 
//    tracking purposes.




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

void maxAndMin(struct Array *list){
	int min,max;
	min=max=list->array[0];
	for(int i=1;i<list->length;i++){
		if(list->array[i]<min){
			min=list->array[i];
		}else if(list->array[i]>max){
			max=list->array[i];
		}
	}
	printf("Max: %d and Min: %d",max,min);
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
	
	maxAndMin(&list);
	
	
	
	
	freeList(&list);
	return 0;
}