/*
 Title: Summing All Elements in an Array ADT Using Recursion
 Author: Inam Ul Haq

 Description:
    This program demonstrates how to calculate the average of elements
    stored in an Array Abstract Data Type (ADT). The process involves:

        1. Initializing a dynamic array (ADT) with a specified size.
        2. Populating the array with integer values.
        3. Calculating the sum of all elements in the array.
           - Currently, the sum is calculated using an iterative loop.
           - Optionally, a recursive function can be used to compute the sum.
        4. Computing the average by dividing the total sum by the number of elements.
        5. Properly freeing allocated memory to avoid memory leaks.

    This program illustrates:
        - Dynamic memory allocation and deallocation in C.
        - Traversing an array and performing arithmetic operations.
        - Use of functions for modular and reusable code.

*/

 
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

double average(struct Array *list){
	int totalSum=0;
	for(int i=0;i<list->length;i++){
		totalSum+=list->array[i];
	}
	return (double)totalSum/list->length;
}

int main(){
	int size; // varable for size of list
	printf("Enter size of list: "); // message to enter size
	scanf("%d",&size); // taking size from user
	struct Array list;
	initList(&list,size);
	
	for(int i=0;i<size;i++){
		list.array[i]=i+1;
	}
	list.length=size;
	
	double averageOfList=average(&list);
	printf("Average of the list is: %f",averageOfList);
	
	freeList(&list);
	
	return 0;
}

