/*
 Analysis:
 	To add all elements, we must traverse the entire list of n elements,
 	so the time complexity will be O(n).

 Step-by-step analysis:
 	1. Check whether the list is empty: 1 unit
 	2. Declare totalSum variable: 1 unit
 	3. Loop initialization i=0: 1 unit
 	   Loop condition i<list->length: n+1 units
 	   Increment i++: n units
 	4. totalSum += list->array[i]: n units
 	5. Return totalSum: 1 unit

 Total operations: 1 + 1 + 1 + (n+1) + n + n + 1 = 3n + 5
 Dropping constants ? Time complexity: O(n)
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
}

int sum(struct Array *list){
	if(list->length==0){
		printf("List is empty.\n");
		return -1;
	}
	int totalSum=0;
	for(int i=0;i<list->length;i++){
		totalSum+=list->array[i];
	}
	return totalSum;
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
	int totalSum=sum(&list);
	if(totalSum!=-1)
	printf("Total sum of the list is: %d",totalSum);
	
	freeList(&list);
	
	return 0;
}

