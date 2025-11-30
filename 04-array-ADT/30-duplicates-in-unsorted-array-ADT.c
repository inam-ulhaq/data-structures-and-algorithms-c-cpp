// Title: Finding Duplicates in an Unsorted List of Numbers
// Author: Inam Ul Haq
//
// Description:
// 	The function "unsortedDuplicates()" is implemented to find duplicates 
// 	within an unsorted list of numbers.
// 
// How It Works:
// 1. The function takes a list as an input parameter.
// 2. An outer 'for' loop is used to select each element of the list sequentially.
// 3. The inner 'for' loop searches for duplicates among all elements that follow 
//	the currently selected target element.
// 4. If a duplicate is found, the 'break' statement interrupts the inner loop.
// 
// Time Complexity Analysis:
// 1. The outer loop initializes (int i=0) in constant time, checks its condition 
//    (i < list->length - 1) approximately 'n' times, and increments 'i' approximately 'n' times.
// 2. The inner loop ("for(int j=i+1; j < list->length - 1; j++)") executes a 
// 	decreasing number of times: 
//    (n-1) + (n-2) + ... + 1 iterations. The total number of comparisons is 
//	roughly n(n-1)/2, 
//    which is approximately n squared (n^2).
// 3. Let F(n) be the time complexity function:
// 	F(n) = 1 (initialization) + n (condition checks) + n (increments) + n^2 (inner loop operations)
//  F(n) = n^2 + 2n + 1
// 4. In Big O notation, we keep the dominant term:
// 	F(n) = O(n^2)
//
// The overall time complexity is O(n^2) because the nested loops require comparing every item 
//	with every other item in the worst case.







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
	for(int i=0;i<list->length-1;i++){
		for(int j=i+1;j<list->length;j++){
			if(list->array[i]==list->array[j]){
				printf("%d ",list->array[i]);
				break;
			}
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