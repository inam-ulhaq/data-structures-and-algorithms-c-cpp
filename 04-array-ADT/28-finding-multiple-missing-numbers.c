// Title: Finding Multiple Missing Numbers in Sorted Sequnce of Numbers
// Author: Inam Ul Haq
// Description:
// 	The "findMultipleMissingNumbers" function is implemented to find and print
// 	all missing integers in a sorted sequence of numbers.
// 
// How it works
// 1- It finds missing integers in a sorted sequence of numbers using the 
//	difference method.
// 2- It establishes the initial difference (diff) between the element 
//	value and its index.
// 3- It iterates through the array, and if the current difference (array[i] - i) 
//	is greater than the initial difference (diff), missing numbers are present.
// 4- It uses a nested loop to print all numbers between the current expected 
//	value and the actual value, incrementing 'diff' for each missing number found.
//
// Time complexity
// 	Let's analyse the code
// 1- int diff=list->array[0]-0; -> take 1 unite
// 2- in "for(int i=0;i<list->length;i++)"
//  int i=0 -> take 1 unite, i<list->length -> take n unites, i++ -> take n unites
// 3- if(list->array[i]-i!=diff) -> take n unites
// 4- in "while(diff<list->array[i]-i)"
//    This loop executes k times, where k is the total number of missing elements (k < n).
// 5- printf("%d ",i+diff) -> take k unites
// 6- diff++ -> take k unites
//
// Lets F(n) is the total time taken 
// then 
// 	F(n)= 1 + 1+n+n + n + k+k
// 	F(n)= 3n + 3 + 2k
//  Since k (the number of missing elements) is always less than n (the array size), 
// 	the worst-case complexity remains linear.
// 
// 	F(n) = n 
//	So the time complexity is O(n)



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
void findMultipleMissingNumbers(struct Array *list){
	int diff=list->array[0]-0;
	for(int i=0;i<list->length;i++){
		if(list->array[i]-i!=diff){
			while(diff<list->array[i]-i){
				printf("%d ",i+diff);
				diff++;
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
	
	printf("Miss numbers are: \n");
	findMultipleMissingNumbers(&list);

	
	
	freeList(&list);
	return 0;
}