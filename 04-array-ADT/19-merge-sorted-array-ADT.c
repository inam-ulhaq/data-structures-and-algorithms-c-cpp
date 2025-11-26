/*
 Title: Merge Operation in Array ADT
 Author: Inam Ul Haq

 Description:
    Merging can be performed only on sorted arrays. 
    A merge operation is a binary operation that combines two sorted arrays 
    into a single sorted array.

    During merging:
        - We take two sorted input arrays.
        - Compare elements from both arrays in increasing order.
        - Insert the smaller element into the output array.
        - Continue until all elements from both arrays have been processed.

    Note:
        - Merging requires a third array to store the result.
        - The merge operation cannot be performed in-place using the two 
          input arrays because overwriting elements would destroy ordering.
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

void mergeArrays(struct Array *list1,struct Array *list2,struct Array *list3){
	int i=0,j=0,k=0;
	while(i<list1->length && j<list2->length){
		if(list1->array[i]<list2->array[j]){
			list3->array[k++]=list1->array[i++];
		}else{
			list3->array[k++]=list2->array[j++];
		}
	}
	
	while(i<list1->length){
		list3->array[k++]=list1->array[i++];
	}
	while(j<list2->length){
		list3->array[k++]=list2->array[j++];
	}
	list3->length=k;
}

int main(){
	int size1; // varable for size of list
	printf("Enter size of list1: "); // message to enter size
	scanf("%d",&size1); // taking size from user
	struct Array list1;
	initList(&list1,size1);
	
	for(int i=0;i<size1;i++){
		list1.array[i]=i;
	}
	list1.length=size1;
	
	
	int size2; // varable for size of list
	printf("Enter size of list2: "); // message to enter size
	scanf("%d",&size2); // taking size from user
	struct Array list2;
	initList(&list2,size2);
	
	for(int i=0;i<size2;i++){
		list2.array[i]=i+1;
	}
	list2.length=size2;

	printf("List1 elements: ");
	for(int i=0;i<list1.length;i++)
		printf("%d ",list1.array[i]);
	
	printf("\nList2 elements: ");
	for(int i=0;i<list2.length;i++)
		printf("%d ",list2.array[i]);
		
	
	struct Array mergeSortedList;
	initList(&mergeSortedList,size1+size2);
		
	mergeArrays(&list1,&list2,&mergeSortedList);
	
	printf("\nElement of merge sorted list: ");
	for(int i=0;i<mergeSortedList.length;i++)
		printf("%d ",mergeSortedList.array[i]);
		
	freeList(&list1);
	freeList(&list2);
	freeList(&mergeSortedList);
	
	return 0;
}

