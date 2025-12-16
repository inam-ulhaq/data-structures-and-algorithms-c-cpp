/*
 Title: Sum of Sparse Matrices Using Three Column Representation
 Author: Inam Ul Haq
 Description:
 	This program implements sparse matrices using the three-column (row, column, value) 
	 representation. It allows users to create two sparse matrices by entering only 
	 their non-zero elements, displays them in full matrix form, and computes 
	 their sum. The add function merges the non-zero elements of the two matrices 
	 in sorted order, adds elements that share the same row and column, and stores 
	 the result in a new sparse matrix while preserving sparsity. Dynamic memory 
	 allocation is used to manage the sparse elements efficiently.
   
*/

#include <stdio.h>
#include <stdlib.h>
struct Element{
	int i;
	int j;
	int element;
};
struct Sparse{
	int rows;
	int columns;
	int totalElement;
	struct Element *e;
};

void create(struct Sparse *m){
	printf("\nEnter dimension:\n");
	printf("Enter Rows: ");
	scanf("%d",&m->rows);
	printf("Enter columns: ");
	scanf("%d",&m->columns);
	printf("Enter number of non-zero elements: ");
	scanf("%d",&m->totalElement);
	m->e=malloc(m->totalElement*sizeof(struct Element));
	
	printf("Enter elements in sorted order: ");
	for(int i=0;i<m->totalElement;i++){
		printf("Enter row: ");
		scanf("%d",&m->e[i].i);
		m->e[i].i--;
		printf("Enter column: ");
		scanf("%d",&m->e[i].j);
		m->e[i].j--;
		printf("Enter element: ");
		scanf("%d",&m->e[i].element);
	}
}
void display(struct Sparse m) {
    int k=0;
    for(int i=0;i<m.rows;i++){
    	for(int j=0;j<m.columns;j++){
    		if(k<m.totalElement && i== m.e[k].i && j==m.e[k].j){
    			printf("%d ",m.e[k].element);
    			k++;
			}else{
				printf("%d ",0);
			}
		}
		printf("\n");
	}
}
void add(struct Sparse *m1,struct Sparse *m2,struct Sparse *m3 ){
	if(m1->columns == m2->columns && m1->rows == m2->rows){
		m3->e=malloc((m1->totalElement+m2->totalElement)*sizeof(struct Element));
		m3->columns=m1->columns;
		m3->rows=m1->rows;
		
		int i=0,j=0,k=0;
		while(i<m1->totalElement && j<m2->totalElement){
			if(m1->e[i].i<m2->e[j].i){
				m3->e[k].element=m1->e[i].element;
				m3->e[k].i=m1->e[i].i;
				m3->e[k].j=m1->e[i].j;
				i++;
				k++;
			}else if(m1->e[i].i>m2->e[j].i){
				m3->e[k].element=m2->e[j].element;
				m3->e[k].i=m2->e[j].i;
				m3->e[k].j=m2->e[j].j;
				j++;
				k++;
			}else if(m1->e[i].j<m2->e[j].j){
				m3->e[k].element=m1->e[i].element;
				m3->e[k].i=m1->e[i].i;
				m3->e[k].j=m1->e[i].j;
				i++;
				k++;
			}else if(m1->e[i].j>m2->e[j].j){
				m3->e[k].element=m2->e[j].element;
				m3->e[k].i=m2->e[j].i;
				m3->e[k].j=m2->e[j].j;
				j++;
				k++;
			}else{
				int sum=m1->e[i].element+m2->e[j].element;
				if(sum!=0){
					m3->e[k].element=m1->e[i].element+m2->e[j].element;
					m3->e[k].i=m1->e[i].i;
					m3->e[k].j=m1->e[i].j;
					i++;
					j++;
					k++;
				}
			}
		}
		while(i<m1->totalElement){
			m3->e[k].element=m1->e[i].element;
			m3->e[k].i=m1->e[i].i;
			m3->e[k].j=m1->e[i].j;
			i++;
			k++;
		}
		while(j<m2->totalElement){
			m3->e[k].element=m2->e[j].element;
			m3->e[k].i=m2->e[j].i;
			m3->e[k].j=m2->e[j].j;
			j++;
			k++;
		}
		m3->totalElement=k;
	}
}

int main(){
	struct Sparse m1;
	create(&m1);
	struct Sparse m2;
	create(&m2);
	struct Sparse m3;
	add(&m1,&m2,&m3);
	
	printf("\nMatrix: 1.\n");
	display(m1);
	
	printf("\nMatrix: 2.\n");
	display(m2);
	
	printf("\nMatrix: 3.\n");
	display(m3);
	
	free(m1.e);
	free(m2.e);
	free(m3.e);
	return 0;
	
}