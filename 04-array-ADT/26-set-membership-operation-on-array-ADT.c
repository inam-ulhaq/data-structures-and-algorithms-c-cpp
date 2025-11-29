// Title: Set Membership Operation on Sorted Arrays ADT
// Author: Inam Ul Haq
//
// Description:
// 	Set membershif mean weather an entity is member or not of set mean it 
// 	exist in the set or not. If it is exist it's mean it is the member of 
// 	the set of not then it is not the member of the set.
//
// Time Complexity Analysis:
// This approach use for loop to iterate over the set and compare key with
// all element of the set, the set consist on n element so the key will compare
// n time which , So the time complexity will be O(n)
//
// How it works:
// 1. isSetMember take tow perimeters set and key.
// 2. it check weather the set empty or not to ensure there the set must be consist on 
// 	some element to check key inside it.
// 3. if the set is not empty, itreating thorugh the set elements using for loop.
// 4. comparing key with all set elements. if the key is found the function will return 1,
// otherwise 0.


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
int isSetMember(struct Array *set,int key){
	if(set->length==0){
		printf("Set is emepty.\n");
		return 0;
	}else{
		for(int i=0;i<set->length;i++){
			if(key==set->array[i])
				return 1;
		}
	}
	return 0;
}


int main(){
	int size;
	printf("Set size: ");
	scanf("%d",&size);
	
	struct Array *set;
	initList(set,size);
	
	printf("Set elements:\n");
	for(int i=0;i<size;i++)
	scanf("%d",&set->array[i]);
	set->length=size;
	
	int key;
	printf("Key: ");
	scanf("%d",&key);
	
	if(isSetMember(set,key)){
		printf("%d is the member of set",key);
	}else{
		printf("%d is not the member of set",key);
	}
	freeList(set);
}