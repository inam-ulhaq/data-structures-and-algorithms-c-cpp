/*
 Title: Upper Triangular Matrix row major mapping
 Author: Inam Ul Haq
 Description:
    Upper Triangular matrix is a square matrix in which all elements below
    the main diagonal are zero, while other elements are non-zero.
    i.e. if M is matrix and i represent rows and j represent columns then
    M[i,j]=0 if i>j
    M[i,j]>0 if i<=j;

    Number of zero elements and non zero elements:
    In a square matrix of order n by n, total elements = n^2
    Non zero elements in upper triangular matrix: n(n+1)/2
    Zero elements: n(n-1)/2

    Representation in program:
    We store only non-zero elements to save storage and processing time.
    Non-zero elements count = n(n+1)/2
    We can store row-wise: first row, then second row, and so on.

    Row major mapping:
    For a 4x4 matrix:
         row1      row2        row3       row4
    array = |a11|a12|a13|a14|a22|a23|a24|a33|a34|a44|
    indices: 0   1   2   3   4   5   6   7   8   9

    Accessing element M[i,j]:
    To access M[i,j], skip elements of previous rows + columns before j in current row
    Formula: index = (i-1)*(2*n - i + 2)/2 + (j - i)
*/

#include <stdio.h>
#include <stdlib.h>

struct Matrix{
    int *matrix;
    int length;
};

void initMatrix(struct Matrix *m,int n){
    m->length = n*(n+1)/2;
    m->matrix = malloc(m->length * sizeof(int));
}

void freeMatrix(struct Matrix *m){
    free(m->matrix);
    m->matrix = NULL;
}

int indexUpper(int n,int i,int j){
    return ((i-1)*(2*n - i + 2)/2 + (j - i));
}

void set(struct Matrix *m,int n,int i,int j,int element){
    if(i<=j){
        m->matrix[indexUpper(n,i,j)] = element;
    }
}

int get(struct Matrix *m,int n,int i,int j){
    if(i<=j){
        return m->matrix[indexUpper(n,i,j)];
    }else{
        return 0;
    }
}

int main(){
    int rows,columns;
    printf("Enter dimension for matrix(must rows==columns). ");
    printf("Enter rows: ");
    scanf("%d",&rows);
    printf("Enter columns: ");
    scanf("%d",&columns);

    if(rows != columns){
        printf("Sorry dimension is not square.");
        return 0;
    }

    struct Matrix m;
    initMatrix(&m,rows);

    for(int i=1;i<=rows;i++){
        printf("Enter elements of row %d:\n",i);
        for(int j=1;j<=columns;j++){
            if(i<=j){
                int element;
                printf("Enter element[%d,%d]: ",i,j);
                scanf("%d",&element);
                set(&m,rows,i,j,element);
            }
        }
    }

    printf("Displaying elements of matrix: \n");
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            printf("%d ",get(&m,rows,i,j));
        }
        printf("\n");
    }

    freeMatrix(&m);
    return 0;
}

 
	 
	 