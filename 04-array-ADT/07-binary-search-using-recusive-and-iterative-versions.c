// Title: Binary Search in List
// Author: Inam Ul Haq
// Description: 
//  Binary Search is an efficient searching algorithm that works only on
//  sorted lists. This is the first and most important requirement.
//  
//  Why is it called "Binary" Search?
//      - Because at every step, the algorithm divides (splits) the list
//        into two halves.
//      - It compares the key with the middle element, and based on this
//        comparison, it eliminates one half of the list completely.
//  
//  How it works:
//      1. Find the middle index of the sorted list.
//      2. Compare the key with the middle element:
//          - If key == middle element → search successful → return index.
//          - If key < middle element  → search continues in left half.
//          - If key > middle element  → search continues in right half.
//      3. Repeat the process until:
//          - The key is found, OR
//          - The search interval becomes empty (key not found).
//  
//  Time Complexity:
//      - Best Case:    O(1)   (key is at middle)
//      - Worst Case:   O(log n)
//      - Average Case: O(log n)
//  
//  Why Binary Search is fast?
//      - Because with each comparison, it eliminates half of the search space.
//      - This makes it much faster than linear search for large lists.

 
 
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

int binarySearch(struct Array *list,int key){
	if(list->length==0){
		printf("List is empty.\n");
		return -1;
	}
	
	int low=0,mid,high=list->length-1;
	while(low<=high){
		mid=(low+high)/2;
		if(key==list->array[mid])
		return mid;
		else if(key>list->array[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}



int binarySearchRec(struct Array *list,int low,int high,int key){
	if(list->length==0){
		printf("List is empty.\n");
		return -1;
	}
	if(low>high){
		return -1;
	}
	int mid=(low+ high)/2;
	if(key==list->array[mid])
		return mid;
	else if(key>list->array[mid])
		return binarySearchRec(list,mid+1,high,key);
	else
		return binarySearchRec(list,low,mid-1,key);
}

int main(){
	int size; // varable for size of list
	printf("Enter size of list: "); // message to enter size
	scanf("%d",&size); // taking size from user
	struct Array list;
	initList(&list,size);
	int key;
	printf("Enter key: ");
	scanf("%d",&key);
	
	for(int i=0;i<size;i++){
		list.array[i]=i+1;
	}
	list.length=size;
	
	int index=binarySearchRec(&list,0,list.length-1,key);
	if(index==-1){
		printf("Search unsuccessful.\n");
	}else{
		printf("Value found at index: %d\n",index);
	}
	
	freeList(&list);
	
	return 0;
}

