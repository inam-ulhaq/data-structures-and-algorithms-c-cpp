#include <stdio.h>

void merge(int A[],int l,int mid,int h){
	int i,j,k;
	i=l;
	k=0;
	j=mid+1;
	int B[100];
	while(i<=mid && j<=h){
		if(A[i]<A[j]){
			B[k++]=A[i++];
		}else{
			B[k++]=A[j++];
		}
	}
	while(i<=mid){
		B[k++]=A[i++];
	}
	while(j<=h){
		B[k++]=A[j++];
	}
	k=0;
	for(i=l;i<=h;i++){
		A[i]=B[k++];
	}
}

void mergeSort(int A[],int l,int h){
	if(l<h){
		int mid=(l+h)/2;
		mergeSort(A,l,mid);
		mergeSort(A,mid+1,h);
		merge(A,l,mid,h);
			
	}

}


int main(){
	int A[]={5,3,6,2,1,7,9,8,4};
	int n=8;
	mergeSort(A,0,n);
	for(int i=0;i<=n;i++){
		printf("%d ",A[i]);
	}
}


