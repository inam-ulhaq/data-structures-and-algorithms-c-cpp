// Title: Difference Operation on Sorted Arrays ADT
// Author: Inam Ul Haq
//
// Description:
// differenceOfSorted operation is implemented to find setA difference setB (A - B),
// i.e., finding all elements of setA that are not present in setB.
//
// Time Complexity Analysis:
// This approach uses the Two-Pointer technique on sorted arrays, achieving a highly
// efficient Time Complexity of O(n + m), where n and m are the lengths of setA and setB.
// This is significantly faster than the O(n * m) complexity for unsorted arrays.
//
// How it works:
// 1. It takes three sets as parameters: set1 (A), set2 (B), and set3 (Result).
// 2. We use two pointers, i (for set1) and j (for set2), and pointer k (for set3).
// 3. The algorithm iterates by comparing the elements at set1[i] and set2[j]:
//    - If set1[i] == set2[j]: The element is common. Both i and j advance.
//    - If set1[i] < set2[j]: set1[i] is guaranteed not to be in set2. It's appended
//      to set3, and only pointer i advances.
//    - If set1[i] > set2[j]: The smaller element in set2[j] is ignored, as it cannot
//      match any remaining element in set1. Only pointer j advances.
// 4. After the main while loop finishes (when either i or j reaches its end), a second
//    while loop ensures any remaining elements in set1 (A) are appended to set3, as they
//    must be non-common elements (the pointer for set2 already reached its end).
// 5. Finally, k holds the total count of elements in the result, which is assigned to
//    set3->length.
//

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
void differenceOfSorted(struct Array *set1,struct Array *set2,struct Array *set3){
	int i,j,k;
	i=j=k=0;
	while(i<set1->length && j<set2->length){
		if(set1->array[i]==set2->array[j]){
			i++,j++;
		}else if(set1->array[i]<set2->array[j]){
			set3->array[k++]=set1->array[i];
			i++;
		}else{
			j++;
		}
	}
	while(i<set1->length){
		set3->array[k++]=set1->array[i++];
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
	differenceOfSorted(&set1,&set2,&set3);
	
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

