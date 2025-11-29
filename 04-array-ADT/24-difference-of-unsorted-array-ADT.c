// Title: Difference Operation on Unsorted Arrays ADT
// Author: Inam Ul Haq
//
// Description:
// This program implements the Difference Operation (Set A difference Set B)
// for two unordered sets (Set A and Set B) stored in a custom Array Abstract
// Data Type (ADT) structure.
//
//
// Key Functionality (differenceOfUnSorted):
// 1. The function iterates through every element of the first set (set1) using an
//    outer loop (index i).
// 2. For each element in set1, it performs a linear search through the entire
//    second set (set2) using an inner loop (index j).
// 3. If a match is not found (set1->array[i] == set2->array[j]), that non common element
//    is appended to the result set (set3).
// 4. Time Complexity Analysis: Due to the nested loops, this brute-force
//    approach has a time complexity of O(n * m), where n and m are the
//    lengths of set1 and set2, respectively.

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
void differenceOfUnSorted(struct Array *set1,struct Array *set2,struct Array *set3){
	int i,j,k;
	i=j=k=0;
	for(;i<set1->length;i++){
		int found=0;
		for(j=0;j<set2->length;j++){
			if(set1->array[i]==set2->array[j]){
				found=1;
				break;
			}
		}
		if(found==0){
			set3->array[k++]=set1->array[i];
		}
	}
	set3->length=k;
}


int main(){
	int set1Size,set2Size,set3Size;
	
	printf("Enter set1 size: ");
	scanf("%d",&set1Size);
	struct Array set1;
	initList(&set1,set1Size);
	printf("Enter set1 elements: ");
	for(int i=0;i<set1.size;i++){
		scanf("%d",&set1.array[i]);
	}
	set1.length=set1Size;
	
	printf("Enter set2 size: ");
	scanf("%d",&set2Size);
	struct Array set2;
	initList(&set2,set2Size);
	printf("\nEnter set2 elements: ");
	for(int i=0;i<set2.size;i++){
		scanf("%d",&set2.array[i]);
	}
	set2.length=set2Size;
	
	struct Array set3;
	set3Size=set1Size+set2Size;
	initList(&set3,set3Size);
	differenceOfUnSorted(&set1,&set2,&set3);
	
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

