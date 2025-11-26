/*
 Title: Partition Negative and Positive Numbers in an Array ADT
 Author: Inam Ul Haq

 Description:
    This program arranges an array such that:
        - All negative numbers move to the left side.
        - All positive numbers move to the right side.

    The partitioning is done using a two-pointer technique:
        - i starts from the left
        - j starts from the right
        - i moves forward until a positive number is found
        - j moves backward until a negative number is found
        - The two values are swapped when i < j
    
    Time Complexity:
        - The array is scanned once → O(n)
        - Only constant extra space → O(1)

    Note:
        - This is similar to QuickSort’s partition logic.
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

void leftNegativeRightPositive(struct Array *list){
	int i=0,j=list->length-1;
	for(;i<j;){
		while(j>i && list->array[j]>=0){
			j--;
		}
		while(i<j && list->array[i]<0){
			i++;
		}
		if(i<j){
			int temp=list->array[i];
			list->array[i]=list->array[j];
			list->array[j]=temp;
		}
		
	}
}


int main(){
	int size; // variable for size of list
	printf("Enter size of list: "); // message to enter size
	scanf("%d",&size); // taking size from user
	struct Array list;
	initList(&list,size);
	
	for(int i=0;i<size;i++){
		scanf("%d",&list.array[i]);
	}
	list.length=size;

	printf("Before arrangement the list is: ");
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		

	leftNegativeRightPositive(&list);
	
	printf("\nAfter arrangement the list is: ");
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	freeList(&list);
	
	return 0;
}

