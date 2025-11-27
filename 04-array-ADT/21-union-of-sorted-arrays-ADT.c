/*
 Title: Union Of Sorted Arrays ADT
 Author: Inam Ul Haq
 Description:
  unionOfSorted: Performs the set union operation (A U B) on two
  pre-sorted sets, set1 and set2.

  Description:
  1. Uses three pointers (i, j, k) to traverse both set1 and set2 simultaneously
     and store the result in set3.
  2. Compares elements at pointers i and j.
  3. If elements are equal, one is copied to set3, and both i and j are incremented
     (handling duplicates efficiently).
  4. If one element is smaller, it is copied to set3, and only its respective
     pointer is incremented.
  5. After one set is exhausted, the remaining elements of the other set are
     copied directly to set3.

  Time Complexity: O(n + m), where n is the length of set1 and m is the
  length of set2. This linear complexity is achieved because the input arrays
  are already sorted, allowing for a single-pass merge-like process.
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

void unionOfSorted(const struct Array *set1,const struct Array *set2,struct Array *set3){
	int i=0,j=0,k=0;
	while(i<set1->length && j<set2->length){
		if(set1->array[i]==set2->array[j]){
			set3->array[k++]=set1->array[i++];
			j++;
		}else if(set1->array[i]<set2->array[j]){
			set3->array[k++]=set1->array[i++];
		}else{
			set3->array[k++]=set2->array[j++];
		}
	}
	while(i<set1->length){
		set3->array[k++]=set1->array[i++];
	}
	while(j<set2->length){
		set3->array[k++]=set2->array[j++];
	}
	set3->length=k;
}

int main(){
	int set1Size,set2Size,set3Size;
	
	printf("Enter set1 size: ");
	scanf("%d",&set1Size);
	struct Array set1;
	initList(&set1,set1Size);
	printf("Enter set1 elements: ");
	for(int i=0;i<set1.size;i++){
		scanf("%d",&set1.array[i]);
	}
	set1.length=set1Size;
	
	printf("Enter set2 size: ");
	scanf("%d",&set2Size);
	struct Array set2;
	initList(&set2,set2Size);
	printf("\nEnter set2 elements: ");
	for(int i=0;i<set2.size;i++){
		scanf("%d",&set2.array[i]);
	}
	set2.length=set2Size;
	
	struct Array set3;
	set3Size=set1Size+set2Size;
	initList(&set3,set3Size);
	unionOfSorted(&set1,&set2,&set3);
	
	printf("Set1 elements: ");
	for(int i=0;i<set1.length;i++){
		printf("%d ",set1.array[i]);
	}
	
	printf("\nSet2 elements: ");
	
	for(int i=0;i<set2.length;i++){
		printf("%d ",set2.array[i]);
	}
	
	printf("\nSet3 elements: ");
	for(int i=0;i<set3.length;i++){
		printf("%d ",set3.array[i]);
	}
	
	
	return 0;
}

