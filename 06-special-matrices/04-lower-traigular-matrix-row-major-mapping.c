/*
 Title: Lower Traingular Matrix
 Author: Inam Ul Haq
 Description:
 	Lower Traingular matrix is a square matrix in which the lower triangular
 	part is non zero elements and the upper triagular part is zeros elements.
 	i.e. if M is matrix and i represent rows and j represent columns then
 	M[i,j]=0 if i<j
 	M[i,j]>0 if i>=j;
 	
 	Number of zero elements and non zero elements:
 	If the matrix is order of n by n then the total number of elements will
 	be n square(n^2). Now If we have the matrix of 5 by 5 then in first row 
 	the non zero elements will 1, in second 2, in 3rd 3, in forth 4 and in last 
 	row 5 element i.e. No of non zero elements in a 5 by 5 matrix is 1+2+3+4+5 so 
 	for n this will be n(n+1)/2 out n^2. if we look for no of zero elements
 	in first row 4, in second 3, in 3rd 2 in fourth 1 and in last 0 number of 
 	zero elements will be there, So out of n^2 total number of zero elments will be
 	n(n-1)/2.
 	
 	How to represent this in our program:
 	To represent lower triangular matrix in our program we are avoiding storing zero
 	elements so can save the the storage and processing time.Then for storing 
 	non zero elements how much space we need? the number of non zero elements are n(n+1)/2 
 	so we need n(n+1)/2 amount of space.
 	
 	Example:
 		 |1 0 0 0|
		 |2 3 0 0|
		 |4 5 6 0|
		 |7 8 9 1|
	
	This is a 4 by 4 matrix, number of non zero elements in the matrix is 4(4+1)/2 which
	is equal to 10. So we need 10 amount of space to represent this in a program.
	now There are two ways to store then non zero elements i.e. row wise  or column wise -> store first column elements, then
	second, then third and so on.
	
	Row major mapping
		This is the way to store element in a given space row wisely.i.e. first storing first row
	then second then third and so on. 
			row1  row2     row3        row4	
	 	    |---|-------|-----------|---------------|
	array = |a11|a21|a22|a31|a32|a33|a41|a42|a43|a44|
	        |---|-------|-----------|---------------|
	          0   1   2   3   4   5   6   7    8   9 (indices).
	          
	    Now How to access a spcific element.
	    	To access a spcific element i.e M[4,3]=a43 we can do this with a formula. a43 is located
	    	at fourth row and 2nd column to access that position we have to skip 4-1 rows and 3-1 colunms.
	    	In first row there is 1 element second row there are 2 while in 3rd row there are three elements
	    	So if we have to skip 3 rows we will skip 1+2+3 and by skiping two columns we will skip two more elements,
	    	For index M[4,3]=[1+2+3]+2=8 so a43 is located at index 8.This is how we can calculate the index of 
	    	a specific element. To Derive a formula lets M[i,j] where i is the number of rows and j is the number of 
			columns we calculate the index M[i,j]=[i(i-1)/2]+(j-1).	
			
*/        


	
#include <stdio.h>
#include <stdlib.h>
struct Matrix{
	int *matrix;
	int length;
};
void initMatrix(struct Matrix *m,int length){
	m->length=length*(length-1)/2;
	m->matrix=malloc(m->length*sizeof(int));
}
void freeMatrix(struct Matrix *m){
	free(m->matrix);
	m->matrix=NULL;
}
void set(struct Matrix *m,int i,int j,int element){
	if(i>=j){
		m->matrix[i*(i-1)/2+j-1]=element;
	}
}
int get(struct Matrix *m,int i,int j){
	if(i>=j){
		return m->matrix[i*(i-1)/2+j-1];
	}
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
		printf("Enter elements of row %d:\n",i+1);
		for(int j=0;j<m.length;j++){
			if(i>=j){
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
			if(i>=j){
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