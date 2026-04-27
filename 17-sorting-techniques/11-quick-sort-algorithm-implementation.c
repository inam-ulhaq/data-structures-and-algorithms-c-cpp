#include <stdio.h>
#include <limits.h>

int partition(int A[],int l,int h){
	int pivot=A[l];
	int i,j;
	i=l,j=h;
	do{
		do{i++;}while(pivot>=A[i]);
		do{j--;}while(pivot<A[j]);
		if(i<j){
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}while(i<j);
	A[l]=A[j];
	A[j]=pivot;
	return j;
}

void quickSort(int A[],int l,int h){
	int j;
	if(l<h){
		j=partition(A,l,h);
		quickSort(A,l,j);
		quickSort(A,j+1,h);
	}
	
}

int main(){
	
	int A[]={12,24,5,6,3,7,2,10,35,4,6,10,INT_MAX};
	quickSort(A,0,12);
	
	for(int i=0;i<12;i++){
		printf("%d ",A[i]);
	}
	
}