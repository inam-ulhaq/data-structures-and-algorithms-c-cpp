/*
 Title: Tri Diagonal Matrix
 Author: Inam Ul Haq
 Description:
    A Tri-Diagonal Matrix is a square matrix in which non-zero elements
    exist only on:
        1. Main diagonal        (i == j)
        2. Lower diagonal       (i == j + 1)
        3. Upper diagonal       (i == j - 1)

    All other elements are zero.

 Representation in program:
    Since only three diagonals contain non-zero elements, we do not need
    to store all n*n elements. Instead, we store only:
        - (n-1) elements of lower diagonal
        - n elements of main diagonal
        - (n-1) elements of upper diagonal

 Space required:
    Total size = (n-1) + n + (n-1) = 3n - 2

 Storage mapping (1D Array):
    The elements are stored sequentially in a single array as follows:

        Lower diagonal : index 0           to (n-2)
        Main diagonal  : index (n-1)       to (2n-2)
        Upper diagonal : index (2n-1)      to (3n-3)

 Accessing random elements:
    Let the matrix index be M[i][j] (1-based indexing):

        Case 1: i - j == 1   (Lower diagonal)
                index = j - 1

        Case 2: i - j == 0   (Main diagonal)
                index = (n - 1) + (i - 1)

        Case 3: i - j == -1  (Upper diagonal)
                index = (2n - 1) + (i - 1)

        Case 4: Otherwise
                M[i][j] = 0

    Thus, any random element M[i][j] can be accessed in O(1) time
    using the above index mapping without storing the entire matrix.
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
	if(i-j==1){
		m->mPtr[j-1]=element;
	}else if(i-j==0){
		m->mPtr[(m->n-1)+i-1]=element;
	}else if(i-j==-1){
		m->mPtr[((m->n-1)+m->n)+i-1]=element;
	}
}

int get(struct Matrix *m,int i,int j){
	if(i-j==1){
		return m->mPtr[j-1];
	}else if(i-j==0){
		return m->mPtr[(m->n-1)+i-1];
	}else if(i-j==-1){
		return m->mPtr[((m->n-1)+m->n)+i-1];
	}else 
		return 0;
}

void display(struct Matrix *m){
	
	for(int i=1;i<=m->n;i++){
		for(int j=1;j<=m->n;j++){
			if(i-j == 0 || i-j == -1 || i-j == 1){
				printf("%d ",get(m,i,j));
			}else{
				printf("%d ",0);
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
			if(i-j == 0 || i-j == -1 || i-j == 1){
				set(&m,i,j,i+1);
			}
		}
	}
	
	display(&m);
	
	freeMatrix(&m);
	
	return 0;
}