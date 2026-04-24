// Title: Code For Insertion Sort
// Author: Inam Ul Haq
// Code:

#include <stdio.h>
void insertionSort(int A[],int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int x=A[i];
		
		while(j>-1 && A[j]>x){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
}

int main(){
	int size=5;
	int arr[]={8,5,7,3,2};
	insertionSort(arr,size);
	
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}


