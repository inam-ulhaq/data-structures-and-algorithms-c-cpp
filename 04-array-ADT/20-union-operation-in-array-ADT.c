/*
 Title: Union Operation in Array ADT
 Author: Inam Ul Haq

 Description:
 This program implements the Union Operation for two unordered sets 
 (Set A and Set B) stored in a custom Array Abstract Data Type (ADT) structure.

 The program defines a struct Array which acts as a dynamic array 
 representing a set. It includes:
 - int array: Pointer to the dynamically allocated integer array.
 - int size: The maximum capacity of the array.
 - int length: The current number of elements in the array (the size of the set).

 Key functionalities include:
 1. initList: Allocates memory for the array and initializes its properties.
 2. freeList: Deallocates the memory to prevent memory leaks.
 3. unionOfUnSorted: Performs the core union operation (A U B).

 The union algorithm works as follows:
 a. All elements of the first set (set1) are copied directly into the result set (set3).
 b. It then iterates through each element of the second set (set2).
 c. For each element in set2, it checks if that element is already present in set3 (which contains A).
 d. If the element is not found (i.e., it's a unique element), it is appended 
    to set3.
 e. This approach ensures that the final set set3 contains all elements from 
    both set1 and set2 without any duplicates, satisfying the mathematical 
    definition of set union.

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

void unionOfUnSorted(const struct Array *set1,const struct Array *set2,struct Array *set3){
	int i=0,j=0,k=0;
	for(;i<set1->length;i++){
		set3->array[k++]=set1->array[i];
	}
	set3->length=k;
	for(i=0;i<set2->length;i++){
		int found=0;
		for(j=0;j<set3->length;j++){
			if(set2->array[i]==set3->array[j]){
				found=1;
			}
		}
	
		if(!found){
			set3->array[k++]=set2->array[i];
			set3->length=k;
		}
	}
}

int main(){
	int set1Size,set2Size,set3Size;
	
	printf("Enter set1 size: ");
	scanf("%d",&set1Size);
	struct Array set1;
	initList(&set1,set1Size);
	for(int i=0;i<set1.size;i++){
		scanf("%d",&set1.array[i]);
	}
	set1.length=set1Size;
	
	printf("Enter set2 size: ");
	scanf("%d",&set2Size);
	struct Array set2;
	initList(&set2,set2Size);
	for(int i=0;i<set2.size;i++){
		scanf("%d",&set2.array[i]);
	}
	set2.length=set2Size;
	
	struct Array set3;
	set3Size=set1Size+set2Size;
	initList(&set3,set3Size);
	unionOfUnSorted(&set1,&set2,&set3);
	
	printf("Set1 elements: ");
	for(int i=0;i<set1.length;i++){
		printf("%d ",set1.array[i]);
	}
	
	printf("\nSet2 elements: ");
	
	for(int i=0;i<set2.length;i++){
		printf("%d ",set2.array[i]);
	}
	
	printf("\nSet3 elements: ");
	for(int i=0;i<set3.length;i++){
		printf("%d ",set3.array[i]);
	}
	
	
	return 0;
}

