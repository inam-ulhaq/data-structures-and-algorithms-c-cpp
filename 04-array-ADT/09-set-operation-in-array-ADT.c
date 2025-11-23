// Title: set() Operation
// Author: Inam Ul Haq
// Description:
//     The set() operation replace the value stored at a specified index
//     of the Array ADT. To perform this operation, the index must be valid
//     — meaning it should be within the current length of the array.


 
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
}

int set(struct Array *list,int index,int value){
	if(index<0 || index>=list->length){
		printf("Invalid Index.\n");
		exit -1;
	}
	list->array[index]=value;
}

int main(){
	int size; // varable for size of list
	printf("Enter size of list: "); // message to enter size
	scanf("%d",&size); // taking size from user
	struct Array list;
	initList(&list,size);
	int index;
	printf("Enter index: ");
	scanf("%d",&index);
	int value;
	printf("Enter new value: ");
	scanf("%d",&value);
	
	for(int i=0;i<size;i++){
		list.array[i]=i+1;
	}
	list.length=size;
	
	set(&list,index,value);
	
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
	freeList(&list);
	
	
	return 0;
}

