// Title: Linear Search
// Author: Inam Ul Haq
// Description:
//     Suppose we have a list of size 6, i.e., list[6] = {1, 2, 3, 4, 5, 6}.
//     The value we want to search for in the list is called the "key". 
//     For example, let the key = 4.
//
//     Linear search works by checking each element one by one, starting from 
//     the first index. For every element, we compare it with the key until we 
//     either find a match or reach the end of the list.
//
//     If the key is found, we return the index where it matches, and the search 
//     is considered successful. If we reach the end of the list without finding 
//     the key, the search is unsuccessful.
//
//     If the list contains duplicate values, linear search returns the index of 
//     the first occurrence only.
//
//     In our example, the key 4 is found at index 3, so the search is successful.


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

int linearSearch(struct Array *list,int key){
	if(list->length==0){
		printf("List is empty.\n");
		return -1;
	}
	
	for(int i=0;i<list->length;i++){
		if(key==list->array[i])
			return i;
	}
	return -1;
}


int main(){
	int size; // varable for size of list
	printf("Enter size of list: "); // message to enter size
	scanf("%d",&size); // taking size from user
	struct Array list;
	initList(&list,size);
	
	for(int i=0;i<list.size;i++){
		list.array[i]=i+1;
	}
	list.length=list.size;
	
	int key;
	printf("Enter key to search: ");
	scanf("%d",&key);
	
	int keyIndex=linearSearch(&list,key);
	if(keyIndex!=-1){
		printf("key found at index: %d\n",keyIndex);
	}
	else{
		printf("Key not found.\n");
	}

	
	freeList(&list);
	
}


/*
Time Complexity of Linear Search:

	1. Check if the list is empty:
	   if(list.length == 0)
	   - Single comparison.
	   - Time complexity: O(1) (constant time)
	
	2. Searching for the key:
	   for(int i = 0; i < list->length; i++)
	   - Best case: key is the first element ? 1 comparison ? O(1)
	   - Worst case: key is not present or last element ? n comparisons ? O(n)
	   - Average case: approximately n/2 comparisons ? O(n)
	
	3. Returning the result:
	   return i; // or return -1
	   - Single operation ? O(1)
	
	Overall Time Complexity:
	- Best case: O(1)
	- Average case: O(n)
	- Worst case: O(n)
	- Dominant factor is the search loop, so overall complexity is O(n)
*/