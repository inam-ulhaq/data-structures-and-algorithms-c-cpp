// Title: Lower Traingular Matrix column major mapping
// Author: Inam Ul Haq
// Description:
//	Lower traingular matrix is a special type of matrix in which all elements 
//	above the main daigonal are zero while non–zero elements form a triangular shape 
//	in the lower part of the matrix.
//	
//	Representation in a program:
//		In lower traingular matrix most of the elements are zero so we avoid
//		storing zero elements and store only non–zero elements to save memory and 
//		computation time. As we know there are two ways to store such matrix in memory 
//		i.e. row major mapping and column major mapping.
//	
//	Column major mapping:
//		Storing elements column by column is column major mapping i.e. storing elements
//		first of first column, then of second, then of third and so on.
//	
//	Determine size:
//		Number of elements in a square matrix of order n is n^2. While in lower traingular 
//		matrix the number of non–zero elements are n*(n+1)/2, and we are storing only non–zero
//		elements so the size will be n*(n+1)/2.
//		
//	Finding element in a specific index:
//		For accessing element at a specific index we use a formula. i.e 
//			col1            col2       col3    col4
//		  |---------------|-----------|-------|---|
//		M=|a11|a21|a31|a41|a22|a32|a42|a33|a43|a44|
//		  |---------------|-----------|-------|---|
//		   0    1   2   3   4   5   6   7   8   9
//
//		Examples:
//			Calculating indices of different positions:
//		i.e M[3,2] = (4)+1 = 5
//			M[4,3] = (4 + 3)+1 = 8
//			M[4,4] = (4 + 3 + 2)+0 = 9
//			M[i,j] = [n+(n-1)+(n-2)+...+(n-(j-2))]+i-j
//			M[i,j] = [n(j-1)-(1+2+3+..+(j-2))]+i-j
//			M[i,j] = [n(j-1)-((j-1)(j-2))/2]+i-j
//		So the genral formula is [n*(j-1)-[(j-1)(j-2)/2]]+i-j
//
//
	
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
	m->mPtr=NULL;
}

void set(struct Matrix *m,int i,int j,int element){
	if(i>=j){
		int index=(m->n*(j-1)-(((j-1)*(j-2))/2))+i-j;
		m->mPtr[index]=element;
	}
}
int get(struct Matrix *m,int i,int j){
	if(i>=j){
		return m->mPtr[(m->n*(j-1)-((j-1)*(j-2)/2))+(i-j)];
	}else
	return 0;
}

int main(){
	int rows,columns;
	printf("Enter Dimention: \n");
	printf("Enter rows: ");
	scanf("%d",&rows);
	printf("Enter columns: ");
	scanf("%d",&columns);
	if(rows!=columns){
		printf("Sorry This is not square matrix!");
	}
	
	struct Matrix m;
	initMatrix(&m,rows);
	for(int j=1;j<=columns;j++){
		for(int i=j;i<=rows;i++){
			if(i>=j){
				int element;
				printf("Enter M[%d,%d]=",i,j);
				scanf("%d",&element);
				set(&m,i,j,element);
			}
		}
	}
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=columns;j++){
			if(i>=j)
				printf("%d ",get(&m,i,j));
			else
				printf("0 ");
		}
		printf("\n");
	}
	freeMatrix(&m);
	return 0;
}


