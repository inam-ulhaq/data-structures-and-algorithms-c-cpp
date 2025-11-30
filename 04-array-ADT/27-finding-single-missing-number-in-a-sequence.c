// Title: Finding Single Missing Number In Sequence Of Number
// Author: Inam Ul Haq
//
// Description:
// 	The "findMissNumber" function is implemented to find and return the single
// 	missing integer in a consecutive sequence of numbers starting from 1.
// 
// How it works
// 1- It calculates the expected total sum of the complete sequence up to the last element.
// 2- It calculates the actual sum of all elements currently present in the array.
// 3- The difference between the expected sum and the actual sum is the missing number.
// 
// Time complexity
// 	Let's analyse the code
// 1- int n=list->array[list->length-1]; -> take 1 unite
// 2- int totalSum=n*n+n/2; -> take 1 unite
// 3- int currentSum=0; -> take 1 unite
// 4- in "for(int i=0;i<list->length;i++)"
//  int i=0 -> take 1 unite, i<list->length -> take n unites, i++ -> take n unites
// 5- currentSum+=list->array[i] take n unites
// 6- return totalSum-currentSum; -> take 1 unite
// 
// Lets F(n) is the total time taken 
// then 
// 	F(n)= 1+1+1+1+n+n+n+1
// 	F(n)= 3n + 5
//  hence the constant terms are not increasing with increase in input so 
// 	we will dorpe it 
//  F(n) = n 
//	So the time complexity is O(n).



#include <stdio.h>
#include <stdlib.h>

struct Array{
	int *array;
	int size;
	int length;
};

void initList(struct Array *list,int size){
	list->size=size;
	list->array=malloc(size * sizeof(int));
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

int findMissNumber(struct Array *list){
	int n=list->array[list->length-1];
	int totalSum=(n*n+n)/2;
	int currentSum=0;
	for(int i=0;i<list->length;i++){
		currentSum+=list->array[i];
	}
	return totalSum-currentSum;
}

int main(){
	int size;
	printf("List size: ");
	scanf("%d",&size);
	
	struct Array *list;
	initList(list,size);
	printf("List elements: \n");
	for(int i=0;i<size;i++){
		scanf("%d",&list->array[i]);
	}
	list->length=size;
	
	
	int key=findMissNumber(list);
	printf("%d is the missing number in sequence: \n",key);
	for(int i=0;i<list->length;i++)
		printf("%d ",list->array[i]);
	
	
	freeList(list);
	return 0;
}