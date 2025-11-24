/*
 Title: Summing All Elements in an Array ADT Using Recursion
 Author: Inam Ul Haq

 Description:
    This program demonstrates how to compute the sum of all elements
    stored in an Array Abstract Data Type (ADT) using a recursive function.

    The process of summing elements involves:
        1. Traversing the array element by element.
        2. Adding the current element to the accumulated sum of
           all preceding elements.
        3. Recursively reducing the problem size until the base case
           (length = 0) is reached.

    The Array ADT implemented here consists of:
        - A dynamically allocated integer array.
        - A 'size' indicating total capacity.
        - A 'length' representing the number of valid elements stored.

    The program:
        - Initializes the Array ADT.
        - Populates it with sample values.
        - Computes the total sum using recursion.
        - Displays the result to the user.
        - Frees all dynamically allocated memory before exiting.
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
	list->length=0;	
}
void freeList(struct Array *list){
	free(list->array);
	list->array=NULL;
}

int sum(struct Array *list,int length){
	if(length==0){
		return 0;
	}
	else{
		return (list->array[length-1])+sum(list,length-1);
	}
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
	
	int totalSum=sum(&list,list.length);
	printf("Total sum of the list is: %d",totalSum);
	
	freeList(&list);
	
	return 0;
}

