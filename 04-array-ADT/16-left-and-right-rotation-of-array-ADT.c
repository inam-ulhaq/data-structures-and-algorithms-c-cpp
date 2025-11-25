/*
 Title: Left & Right Shift Operations in Array ADT
 Author: Inam Ul Haq

 Description:
    This program demonstrates how left rotation and right rotation operations
    work in an Array Abstract Data Type (ADT).

    Left rotation:
        - Moves all elements one position to the left.
        - The first element is removed.
        - The last index is filled with first element.

    Right Shift:
        - Moves all elements one position to the right.
        - The last element is removed.
        - The first index is filled with last element.

    Implementation Steps:
        1. Initialize a dynamic array using initList().
        2. Fill the array with example values.
        3. Perform a right rotation operation.
        4. Perform a lift roation operation.
        4. Display the updated array.
        5. Free the allocated memory using freeList().
    
    Analysis of time complexity:
    	The main work that the function perform is shifting, adding one 
		element in last or first and  everytime we are shifting n 
		elements every time so the time complexity is order of n i.e. O(n)

    Note:
        - rotation operations do not change the length of the list.
        - rotation simply moves elements within their existing positions.
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

int leftRotation(struct Array *list){
	if(list->length==0){
		printf("List is empty.\n");
		return -1;
	}
	int temp=list->array[0];
	for(int i=0;i<list->length-1;i++){
		list->array[i]=list->array[i+1];
	}
	list->array[list->length-1]=temp;
	return 0;
}
int rightRotation(struct Array *list){
	if(list->length==0){
		printf("list is empty.\n");
		return -1;
	}
	int temp=list->array[list->length-1];
	for(int i=list->length-1;i>0;i--){
		list->array[i]=list->array[i-1];
	}
	list->array[0]=temp;
	return 0;
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
	
	printf("\n\nAfter right rotation the list is: ");
	rightRotation(&list);
	
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	
	printf("\n\nAfter left rotation the list is: ");
	leftRotation(&list);
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	freeList(&list);
	
	return 0;
}

