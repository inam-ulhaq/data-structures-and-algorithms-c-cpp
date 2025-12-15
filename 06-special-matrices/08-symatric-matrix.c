/*
 Title: Symatric Matrix
 Author: Inam Ul Haq
 Description: 
 	Symatric matrix is a square matrix that equals its own transfose, meaning
 	the elements are mirrored accross the main daigonal i.e. M[i,j]==M[j,i].
 	
 	
*/

#include <stdio.h>
#include <stdlib.h>
struct Matrix{
	int *mPtr;
	int n;
};

void initMatrix(struct Matrix *m,int n){
	m->n=n;
	int size=n*(n+1)/2;
	m->mPtr=malloc(size*sizeof(int));
}
void freeMatrix(struct Matrix *m){
	free(m->mPtr);
}

void set(struct Matrix *m,int i,int j,int element){
	if(i<=j){
		int index=m->n*(i-1)-(i-1)*(i-2)/2+j-i;
	 m->mPtr[index]=element;
	}
}
int get(struct  Matrix *m,int i,int j){
	if(i<=j && i<= m->n){
		return m->mPtr[(m->n*(i-1)-(i-1)*(i-2)/2)+j-i];
	}else
	return 0;
}

void display(struct Matrix *m){
	for(int i=1;i<=m->n;i++){
		for(int j=1;j<=m->n;j++){
			if(i<=j){
				printf("%d ",get(m,i,j));
			}else{
				printf("%d ",get(m,j,i));
			}
		}
		printf("\n");
	}
}


int main(){
	int rows,columns;
	printf("Enter dimension(rows and columns).\n");
	printf("Enter rows: ");
	scanf("%d",&rows);
	printf("Entere columns: ");
	scanf("%d",&columns);
	
	
	struct Matrix m;
	initMatrix(&m,rows);
	
	for(int i=1;i<=rows;i++){
		printf("Enter row %d elements:\n",i+1);
		for(int j=1;j<=columns;j++){
			if(i<=j){
				int element;
				scanf("%d",&element);
				set(&m,i,j,element);
			}
		}
	}
	display(&m);
	return 0;
}
