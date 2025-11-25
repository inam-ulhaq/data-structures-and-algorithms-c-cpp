/*
 Title: Left & Right Shift Operations in Array ADT
 Author: Inam Ul Haq

 Description:
    This program demonstrates how left shift and right shift operations
    work in an Array Abstract Data Type (ADT).

    Left Shift:
        - Moves all elements one position to the left.
        - The first element is removed.
        - The last index is filled with 0.

    Right Shift:
        - Moves all elements one position to the right.
        - The last element is removed.
        - The first index is filled with 0.

    Implementation Steps:
        1. Initialize a dynamic array using initList().
        2. Fill the array with example values.
        3. Perform a right shift operation.
        4. Display the updated array.
        5. Free the allocated memory using freeList().
    
    Analysis of time complexity:
    	The main work that the function perform is shifting and every
    	time we are shifting n elements every time so the time complexity
    	is order of n i.e. O(n)

    Note:
        - Shift operations do not change the length of the list.
        - Shifting simply moves elements within their existing positions.
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

void liftShift(struct Array *list){
	if(list->length==0){
		printf("List is empty.\n");
		exit(1);
	}
	for(int i=0;i<list->length-1;i++){
		list->array[i]=list->array[i+1];
	}
	list->array[list->length-1]=0;
}
void rightShift(struct Array *list){
	if(list->length==0){
		printf("list is empty.\n");
		exit(1);
	}
	for(int i=list->length-1;i>0;i--){
		list->array[i]=list->array[i-1];
	}
	list->array[0]=0;
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
	
	printf("Before shifting  the list is: ");
	for(int i=0;i<list.length;i++) printf("%d ",list.array[i]);
	
	printf("\n\nAfter rightshift the list is: ");
	rightShift(&list);
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	
	printf("\n\nAfter liftShift the list is: ");
	liftShift(&list);
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	freeList(&list);
	
	return 0;
}

