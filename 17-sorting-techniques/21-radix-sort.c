#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node *next;
	int data;
};

void radixSort(int A[],int n){
	int max=A[0];
	for(int i=1;i<n;i++){
		if(max<A[i])
			max=A[i];
	}
	
	int maxCopy=max;
	int digits=0;
	while(maxCopy>0){
		digits++;
		maxCopy=maxCopy/10;
	}
	
	struct Node **bins=malloc(10*sizeof(struct Node*));
	
	for(int i=0;i<10;i++){
		bins[i]=NULL;
	}
	
	for(int i=0;i<digits;i++){
		for(int j=0;j<n;j++){
			struct Node *element=malloc(sizeof(struct Node));
			element->next=NULL;
			element->data=A[j];
			int mod=10;
			int k=i;
			while(k!=0){
				mod*=10;
				k--;
			}
			int index=(A[j]%mod)/(mod/10);
			if(bins[index]==NULL){
				bins[index]=element;
			}else{
				struct Node *ptr=bins[index];
				while(ptr->next!=NULL){
					ptr=ptr->next;
				}
				ptr->next=element;
			}
		}
		
		
		for(int k=0,l=0;k<10;k++){
			if(bins[k]!=NULL){
				struct Node *ptr=bins[k];
				while(ptr!=NULL){
					struct Node *temp=ptr;
					A[l]=ptr->data;
					l++;
					ptr=ptr->next;
					free(temp);
				}
				
				bins[k]=NULL;
			}
		}
		
		
	}
	
}





int main(){
	int A[]={237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
	int n=10;
	radixSort(A,n);
	for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
}