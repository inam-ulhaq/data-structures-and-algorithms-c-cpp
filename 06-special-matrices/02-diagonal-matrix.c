// Title: Diagonal Matrix
// Author: Inam Ul Haq
// Description: 
// 	A diagonal matrix is a square matrix in which all elements other than the
// 	diagonal elements are zeros. This program implements an efficient storage
// 	method where only the non-zero diagonal elements are stored in a 1D array
// 	of integers. The size of this 1D array is exactly equal to the dimension 
// 	(length) of the conceptual square matrix. Functions are provided to initialize 
// 	the structure, set specific diagonal values, retrieve values (returning 0 
// 	for all non-diagonal coordinates), and properly free the allocated memory.
	
#include <stdio.h>
#include <stdlib.h>
struct Matrix{
	int *matrix;
	int length;
};
void initMatrix(struct Matrix *m,int length){
	m->length=length;
	m->matrix=malloc(length*sizeof(int));
}
void freeMatrix(struct Matrix *m){
	free(m->matrix);
	m->matrix=NULL;
}
void set(struct Matrix *m,int rowNo,int columnNo,int element){
	if(rowNo!=columnNo){
		return;
	}else{
		m->matrix[rowNo]=element;
	}
}
int get(struct Matrix *m,int rowNo,int columnNo){
	if(rowNo==columnNo){
		return m->matrix[rowNo];
	}
	return 0;
}

int main(){
	
	int rows,columns;
	printf("Enter dimention for matrix(must rows==columns). ");
	printf("Enter rows: ");
	scanf("%d",&rows);
	printf("Enter columns: ",&columns);
	scanf("%d",&columns);
	if(rows!=columns){
		printf("Sorry dimention is not squre.");
	}
	struct Matrix m;
	initMatrix(&m,rows);
	for(int i=0;i<m.length;i++){
		printf("Enter elements of row %d:",i+1);
		for(int j=0;j<m.length;j++){
			if(i==j){
				printf("Enter element[%d,%d]: ",i,j);
				int element;
				scanf("%d",&element);
				set(&m,i,j,element);
			}
		}
	}
	
	printf("Displaying element of matrix: \n");
	for(int i=0;i<m.length;i++){
		for(int j=0;j<m.length;j++){
			if(i==j){
				printf("%d ",get(&m,i,j));
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
	freeMatrix(&m);
	return 0;
	
}
 	
 	