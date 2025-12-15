/*
 Title: Toeplitz Matrix
 Author: Inam Ul Haq

 Description:
    This program implements a Toeplitz matrix using a one-dimensional
    dynamically allocated array. A Toeplitz matrix is a square matrix
    in which all elements along each diagonal (from left to right) are
    equal, i.e., M[i][j] = M[i-1][j-1].

 Representation in program:
    Instead of using a two-dimensional array, the matrix is stored in a
    one-dimensional array to optimize memory usage. The matrix dimension
    (n × n) is provided by the user at runtime.

    The program stores only:
        - The first row of the matrix
        - The first column of the matrix

    All remaining elements are implicitly determined by the Toeplitz
    property of equal diagonal elements.

 Space required:
    The total number of diagonals in a Toeplitz matrix is:
        (n - 1) upper diagonals + 1 main diagonal + (n - 1) lower diagonals
        = 3n - 2

    Therefore, only (3n - 2) memory locations are required instead of
    n × n, reducing space complexity from O(n²) to O(n).

 Storage mapping (1D array, 1-based indexing):
    Elements are mapped into the one-dimensional array as follows:

        If i = j  (upper diagonals and main diagonal):
            index = j - i

        If i > j  (lower diagonals):
            index = n + i - j - 1

    All elements on the same diagonal share the same array index, ensuring
    that diagonal values remain constant throughout the matrix.

 Accessing random elements:
    Any matrix element M[i][j] can be accessed in constant time O(1) by
    computing its corresponding index in the one-dimensional array using
    the above mapping rules.

 Input:
    The user is prompted to enter values only for the first row and the
    first column of the matrix. These values uniquely define the entire
    Toeplitz matrix.

 Display:
    The display function reconstructs the complete matrix by retrieving
    each element through the get() function and printing the result.

 Conclusion:
    This program demonstrates an efficient method for representing a
    Toeplitz matrix using array mapping, minimizing memory usage while
    maintaining fast access to matrix elements.
*/


#include <stdio.h>
#include <stdlib.h>

struct Matrix{
	int *mPtr;
	int n;
};
void initMatrix(struct Matrix *m,int n){
	int size=3*n-2;
	m->n=n;
	m->mPtr=malloc(size*sizeof(int));
}
void freeMatrix(struct Matrix *m){
	free(m->mPtr);
}
void set(struct Matrix *m,int i,int j,int element){
	if(i<=j){
		m->mPtr[j-i]=element;
	}else if(i>j){
		m->mPtr[m->n+i-j-1]=element;
	}
}

int get(struct Matrix *m,int i,int j){
	if(i<=j){
		return m->mPtr[j-i];
	}else if(i>j){
		return m->mPtr[m->n+i-j-1];
	}else 
		return 0;
}

void display(struct Matrix *m){
	
	for(int i=1;i<=m->n;i++){
		for(int j=1;j<=m->n;j++){
			if(1){
				printf("%d ",get(m,i,j));
			}
		}
		printf("\n");
	}
}


int main(){
	int n;
	printf("Enter dimention: ");
	scanf("%d",&n);
	
	struct Matrix m;
	initMatrix(&m,n);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == 1||j == 1 ){
				int element;
				printf("M[%d,%d]: ",i,j);
				scanf("%d",&element);
				set(&m,i,j,element);
			}
		}
	}
	
	display(&m);
	
	freeMatrix(&m);
	
	return 0;
}