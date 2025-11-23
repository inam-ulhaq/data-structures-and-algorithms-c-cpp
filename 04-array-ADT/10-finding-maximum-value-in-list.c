/*
 Title: Find Maximum in a List
 Author: Inam Ul Haq
 Description:
     This operation finds and returns the maximum value stored in a list
     (Array ADT). The function iterates through all elements of the list,
     compares them, and keeps track of the largest value found. 
     The list must contain at least one element for this operation to work.
*/


 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
}

int max(struct Array *list){
	if(list->length==0){
		printf("List is empty.\n");
		return (-1);
	}
	int maxValue=list->array[0];
	for(int i=1;i<list->length;i++){
		if(maxValue<list->array[i])
			maxValue=list->array[i];
	}
	return maxValue;
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
	int value=max(&list);
	if(value!=-1)
		printf("Maximum value found in list is: %d",value);	
	
	freeList(&list);
	
	
	return 0;
}

