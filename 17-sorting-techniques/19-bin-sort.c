 /*
 Title: Bin Sort
 Author: Inam Ul Haq

 Description:

	Bin Sort is a sorting technique in which we create containers
	called bins and place elements into them according to their value.

	The main idea is simple: instead of repeatedly comparing elements,
	we directly place each element into the bin that represents its value.
	After that, we collect the elements from the bins in order.

	You can imagine bins like drawers in a cabinet. Each drawer is
	responsible for storing a particular number.

	Concept:

	Assume we have the following list:

	A = {5, 2, 8, 5, 3, 2, 7, 5}

	Notice that some elements appear more than once. These are
	called duplicate values.

	Step 1: Find the maximum element

	First we find the largest element in the list because this
	tells us how many bins we need.

	In this example the maximum element is 8.

	So we create 9 bins:

	Bin[0], Bin[1], Bin[2], Bin[3], Bin[4], Bin[5], Bin[6], Bin[7], Bin[8]


	How bins are initialized:

	In the beginning all bins are empty.

	We usually create an array of pointers where each pointer
	represents a bin. Each pointer initially stores NULL,
	which means the bin is empty.

	Example:

		struct Node* Bin[9];

	Bin[0] = NULL
	Bin[1] = NULL
	Bin[2] = NULL
	...
	Bin[8] = NULL

	Each bin will use a linked list to store elements.
	The pointer in the bin will point to the first node
	of that linked list.


	Step 2: Distribute elements into bins

	Now we scan the list from left to right and place each
	element into the bin that has the same number.

	5 goes into Bin[5]
	2 goes into Bin[2]
	8 goes into Bin[8]
	5 goes into Bin[5]
	3 goes into Bin[3]
	2 goes into Bin[2]
	7 goes into Bin[7]
	5 goes into Bin[5]

	If a bin already contains an element, we simply insert
	the new element into the linked list of that bin.

	So bins conceptually look like this:

	Bin[2] -> 2 -> 2
	Bin[3] -> 3
	Bin[5] -> 5 -> 5 -> 5
	Bin[7] -> 7
	Bin[8] -> 8

	Here each bin is a linked list and the pointer stored
	in the bin points to the first node.


	Step 3: Collect elements from bins

	Now we scan the bins from the smallest index to the
	largest index.

	Bin[0]
	Bin[1]
	Bin[2] -> 2 -> 2
	Bin[3] -> 3
	Bin[4]
	Bin[5] -> 5 -> 5 -> 5
	Bin[6]
	Bin[7] -> 7
	Bin[8] -> 8

	While scanning, we remove elements from the linked list
	and copy them back into the array.

	Since we visit bins in increasing order, the elements
	automatically come out in sorted order.

	Final sorted list:

	2, 2, 3, 5, 5, 5, 7, 8


	Relation with Count Sort:

	Bin Sort and Count Sort are closely related because
	both use the value of elements as indices.

	Both algorithms first find the maximum element and
	create an auxiliary structure based on that value.

	The core idea in both algorithms is:

		element value -> index


	Difference between Bin Sort and Count Sort:

	In Count Sort we do not store elements themselves.
	We only store how many times an element appears.

	Example:

		C[5] = 3

	This means the element 5 appears three times.

	In Bin Sort we store the actual elements inside bins
	using linked lists.

	Example:

		Bin[5] -> 5 -> 5 -> 5

	So Bin Sort stores elements, while Count Sort stores counts.


	Simple way to remember:

	Count Sort counts occurrences.

	Bin Sort stores elements inside bins.
*/

#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node *next;
	int num;
};

void binSort(int A[],int n){
	int max=A[0];
	for(int i=1;i<n;i++){
		if(A[i]>max){
			max=A[i];
		}
	}
	
	struct Node **bin=malloc((max+1)*sizeof(struct Node*));
	for(int i=0;i<=max;i++){
		bin[i]=NULL;
	}
	
	for(int i=0;i<n;i++){
		struct Node *element=malloc(sizeof(struct Node));
		element->next=NULL;
		element->num=A[i];
		if(bin[A[i]]==NULL)
			bin[A[i]]=element;
		else{
			struct Node *ptr=bin[A[i]];
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=element;
		}
	}
	
	int j=0;
	for(int i=0;i<=max;i++){
		if(bin[i]!=NULL){
			struct Node *ptr=bin[i];
			while(ptr!=NULL){
				A[j++]=ptr->num;
				struct Node *temp=ptr;
				ptr=ptr->next;
				free(temp);
			}
			bin[i]=NULL;
		}
	}
	
	free(bin);
	
	
}

int main(){
	int A[]={5, 2, 8, 5, 3, 2, 7, 5};
	int n=8;
	binSort(A,n);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}
