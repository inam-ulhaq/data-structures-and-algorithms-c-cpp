// Title: Finding Multiple Duplicates in Sorted Sequnce of Numbers
// Author: Inam Ul Haq
// Description:
// 	"multipleDuplicate" is implimented to find duplicates in a sorted sequence 
// 	of numbers including multiple duplicates.
// 
// How it works
// 1- It find duplicates in a sorted sequence of numbers.
// 2- It print the duplicates value.
// 3- If mutiple duplicates are there it print it only one time by ignoring
// 	all other copies.
// 4- Counting all duplcates and printing it in last.
//
// Time complexity
// 	Let's analyse the code
// 1- int countDuplicates=0; -> take 1 unite
// 2- int lastDuplicate=-1;  -> take 1 unite 
// 3- in "for(int i=0;i<lsit-length-1;i++)"
//  int i=0 -> take 1 unite, i<list->length-1 -> take n unites, i++ -> take n unites
// 4- int currentDuplicates=list->array[i] take n unites
// 5- if(lastDuplicate=currentDuplicate) -> take n unites
// 6- printf("%d ",list->array[i]) take n unites
// 7- lastDuplicate=currentDuplicate -> take n unites
// 8- countDuplicates++ -> take n unites
// 9- printf("Total Duplicates are: %d", countDuplicates) -> take 1 unites
// 
// Lets F(n) is the total time taken 
// then 
// 	F(n)= 1+1+1+n+n+n+n+n+n+n+1
// 	F(n)= 7n + 5
//  hence the constant terms are not increasing with increase in input so 
// 	we will dorpe it 
//  F(n) = n 
//	So the time complexity is O(n)


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

void multipleDuplicates(struct Array *list){
	int countDuplicates=0;
	int lastDuplicate=-1;
	for(int i=0;i<list->length-1;i++){
		if(list->array[i]==list->array[i+1]){
			int currentDuplicate=list->array[i];
			if(currentDuplicate!=lastDuplicate){
				printf("%d ",list->array[i]);
				lastDuplicate=currentDuplicate;
			}
			countDuplicates++;
		}
	}
	printf("\nTotal duplicates are: %d",countDuplicates);
}
int main(){
	int size;
	printf("List size: ");
	scanf("%d",&size);
	
	struct Array list;
	initList(&list,size);
	printf("List elements: \n");
	for(int i=0;i<size;i++){
		scanf("%d",&list.array[i]);
	}
	list.length=size;
	
	
	printf("List elements: \n");
	for(int i=0;i<list.length;i++)
		printf("%d ",list.array[i]);
	
	printf("\nDuplicates are: ");
	multipleDuplicates(&list);
	
	freeList(&list);
	return 0;
}