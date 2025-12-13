/*
 Title: Upper Traingular Matrix
 Author: Inam Ul Haq
 Description: 
 	Upper traingular matrix is a square matrix which in upper traingular part
 	elements are non zero while the lower traingular part elements are zeros.
 
 Representation in program:
 	Upper triangular matrix is a square matrix of order n by n, so it consist on n^2 
 	number of elements. In upper traingular matrix the uppre traingular part elements 
 	are non zeros and lower triangular part is zeros. number of non zero elements can
 	be calculated as in first column 1,in second 2,in third 3, in fourth 4 and so on.
 	So we can calculate it like 1+2+3+4.....+(n-2)+(n-1)+n= n*(n+1)/2. While the number
 	zero element can be calculated as,number of zero elements in first column is n-1,in 
	second column n-2,in third column n-3,in fourth n-4 and so on. so in n by n matrix, 
	number zero of non zero elements are n-1+n-2+n-3+n-4+...+3+3+1=n*(n-1)/2.
	
	1- Number of non zero elements are = n*(n+1)/2
	2- Number of zero elements are = n*(n-1)/2
	
	Storing both zero and non zero element can wast mamory and compution time to avoid this
	can store only non zero elment so we can save memory and comuption time.
	
	Amount of space required for storing elements:
		The number of non zero elements is n*(n+1)/2, So the space required is 
	also n*(n+1)/2.
	
	Column major mapping:
		Storing the element column by column i.e first storing the elements of first column 
	then of second column, then of third column and then of fourth column is known as column 
	major mapping. To store upper traingular matrix using column major mapping, we will store 
	first column then second then third and so on.
	i.e 
	 |1 2 3 4|
	 |0 5 6 7|
	 |0 0 8 9|
	 |0 0 0 1| can be store as 
		 |-|---|-----|-------|
   array=|1|2|5|3|6|8|4|7|9|1|
		 |-|---|-----|-------|
	      0 1 2 3 4 5 6 7 8 9
	      
	To access M[i,j] i.e
	M[2,3]=[1+2]+1= 4           -> index for M[2,3]=array[4]=6
	M[3,4]=[1+2+3]+3= 9         -> index for M[3,4]=array[9]=1
	M[2,4]=[1+2+3]+1=7          -> index for M[2,4]=array[7]= 7
	M[i,j]=[1+2+3+...+j-1]+j-1
	M[i,j]=[j*(j-1)/2]+j-i      -> index for M[i,j]=array[j*(j-1)/2]+j-i]=element;
	So the formula used to access M[i,j] is j*(j-1)/2 +j-i
	
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
		m->mPtr[j*(j-1)/2+j-i]=element;
	}
}
int get(struct Matrix *m,int i,int j){
	if(i<=j){
		return m->mPtr[j*(j-1)/2+j-i];
	}else
	return 0;
}


int main(){
	int rows,columns;
	printf("Enter dimention(row==column):\n");
	printf("rows: ");
	scanf("%d",&rows);
	printf("columns: ");
	scanf("%d",&columns);
	if(rows!=columns){
		printf("Sorry this is not square matrix!");
	}
	struct Matrix m;
	initMatrix(&m,rows);
	for(int j=1;j<=columns;j++){
		for(int i=1;i<=j;i++){
			int element;
			printf("M[%d,%d]= ",i,j);
			scanf("%d",&element);
			set(&m,i,j,element);
		}
	}
	printf("Retreving elements from the matrix:\n");
	for(int i=1;i<=rows;i++){
		for(int j=1;j<=columns;j++){
			
			printf("%d ",get(&m,i,j));
		}
		printf("\n");
	}
	
}