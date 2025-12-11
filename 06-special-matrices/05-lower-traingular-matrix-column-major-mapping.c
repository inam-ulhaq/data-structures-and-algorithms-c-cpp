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
//		Correct formula for index (column major):
//			index M[i,j] = ( (j-1)*j ) / 2  + (i - j)
//		
//		NOTE: Only valid when i >= j because elements above diagonal are zero.
//		
//		Example:
//			index M[4,4] = (3*4)/2 + (4-4)
//			              = 6 + 0
//			              = 6
//			index M[3,4] = invalid because 3 < 4 (above diagonal ? zero)
//	
	
#include <stdio.h>
#include <stdlib.h>

struct Matrix {
	int *mPtr;
	int length;		// size of 1D array
	int n;          // dimension of matrix
};

void initMatrix(struct Matrix *M, int n){
	M->n = n;
	M->length = n * (n + 1) / 2;
	M->mPtr = (int*) malloc(M->length * sizeof(int));
}

// column major index formula
int indexOf(int i, int j){
	if(i < j)
		return -1;  // above diagonal (not stored)
	return ((j - 1) * j) / 2 + (i - j);
}

void set(struct Matrix *M, int i, int j, int value){
	int idx = indexOf(i, j);
	if(idx >= 0)
		M->mPtr[idx] = value;
}

int get(struct Matrix *M, int i, int j){
	int idx = indexOf(i, j);
	if(idx < 0)
		return 0; // above diagonal element is zero
	return M->mPtr[idx];
}
