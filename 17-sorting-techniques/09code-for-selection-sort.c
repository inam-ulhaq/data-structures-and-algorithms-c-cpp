// Title: Code For Insertion Sort
// Author: Inam Ul Haq
// Code:

#include <stdio.h>
void selectionSort(int A[],int n){
	int i,j,k;
	for(i=0;i<n-1;i++){
		for(j=k=i;j<n;j++){
			if(A[j]<A[k]){
				k=j;
			}
		}
		int temp=A[i];
		A[i]=A[k];
		A[k]=temp;
		
	}
}

int main(){
	int size=10;
	int arr[]={11,13,7,12,16,9,24,5,10,3};
	selectionSort(arr,size);
	
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}


