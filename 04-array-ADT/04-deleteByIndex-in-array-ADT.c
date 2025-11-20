// Title: Delete Element by Index from Array ADT
// Author: Inam Ul Haq
// Description:
//     Delete operation removes an element from a given index in the Array ADT.
//     When deleting, we specify the index whose element should be removed.
//     After removing the element, the position becomes vacant. We cannot leave
//     a vacant position in an array because it becomes difficult to determine
//     whether a location contains a valid value or garbage data.
//     
//     To avoid this, after deleting the element we shift all elements to the
//     left by one position so that the array remains continuous and no empty
//     space is left inside the array.
// 
// Example

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Array{
	int *array;
	int length;
	int size;
};

void initArray(struct Array *list,int size){
	list->size=size;
	list->array=(int *)malloc(size * sizeof(int));
	list->length=0;
}
void freeArray(struct Array *list){
	free(list->array);
}



bool deleteByIndex(int index,struct Array *list){
	if(index>=list->length || index<0){
		return false;
	}
	for(int i=index;i<list->length-1;i++)
		list->array[i]=list->array[i+1];
	list->length--;
	return true;
}


int main(){
	int size;
	printf("Enter size of list: ");
	scanf("%d",&size);
	struct Array list;
	initArray(&list,size);
	for(int i=0;i<size;i++){
		list.array[i]=i+1;
		list.length++;
	}
	
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
	
	deleteByIndex(2,&list);
	
	printf("\n");
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
		
	freeArray(&list);
	return 0;
}


/*
Time Complexity Analysis of deleteByIndex:

1. Index Check:
   - Operation: Check if the index is valid (index >= length or index < 0)
   - Number of operations: 1
   - Time Complexity: O(1)

2. Shifting Elements:
   - Operation: Move each element after the deleted index one position to the left
   - Number of operations depends on the index:
       * Worst case (deleting first element): shift (n-1) elements -> O(n)
       * Best case (deleting last element): shift 0 elements -> O(1)
       * Average case: roughly n/2 shifts -> O(n)
   - Each shift is O(1)

3. Decrement Length:
   - Operation: Reduce the length of the array by 1
   - Time Complexity: O(1)

4. Return Operation:
   - Operation: Return true/false to indicate success
   - Time Complexity: O(1)

Overall Time Complexity:
   - Best case: O(1)
   - Worst case: O(n)
   - Average case: O(n)

Space Complexity:
   - No extra memory is used; operation is done in-place
   - Space Complexity: O(1)
*/
