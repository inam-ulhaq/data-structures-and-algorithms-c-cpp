/*
 Title: Intersection Of Sorted Arrays ADT
 Author: Inam Ul Haq
 Description:
  intersectionOfSorted: Performs the set intersection operation (A INTERSECT B)
  on two pre-sorted sets, set1 and set2. The result is stored in set3.
m,
  1. This function uses a highly efficient two-pointer, merge-like algorithm.
     It initializes pointers i (for set1), j (for set2), and k (for set3, the result).
  2. The main loop runs as long as there are elements left in both input sets.
  3. Comparison Logic:
     - If set1[i] == set2[j]: The element is common to both sets. It is copied
       to set3, and both pointers i and j are incremented to move past the
       matched element. This ensures the element is added only once to the
       intersection.
     - If set1[i] < set2[j]: The element in set1 is unique to set1 at this point.
       Pointer i is incremented to look for a larger element in set1 that might
       match set2[j] or a later element in set2.
     - If set1[i] > set2[j]: The element in set2 is unique to set2 at this point.
       Pointer j is incremented to look for a larger element in set2 that might
       match set1[i] or a later element in set1.
  4. Once the loop terminates, set3 contains all common elements from set1 and
     set2 in sorted order.

  Time Complexity: O(n + m), where n is the length of set1 and m is the
  length of set2. This linear complexity is highly efficient as it requires
  only a single pass through both sorted input arrays.
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


void intersectionOfSorted(struct Array *set1,struct Array *set2,struct Array *set3){
	int i=0,j=0,k=0;
	while(i<set1->length && j<set2->length){
		if(set1->array[i]==set2->array[j]){
			set3->array[k++]=set1->array[i];
			i++;
			j++;
		}else if(set1->array[i]<set2->array[j]){
			i++;
		}else{
			j++;
		}
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
	intersectionOfSorted(&set1,&set2,&set3);
	
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

