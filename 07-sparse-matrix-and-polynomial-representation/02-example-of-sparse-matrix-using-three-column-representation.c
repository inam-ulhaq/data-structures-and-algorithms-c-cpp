/*
 Title: Sparse Matrix Using Three Column Representation
 Author: Inam Ul Haq
 Description:
    This program implements a sparse matrix using the three-column
    (triplet) representation. Only non-zero elements of the matrix
    are stored along with their row and column indices, which helps
    reduce memory usage. The program allows the user to input matrix
    dimensions and non-zero elements, stores them dynamically, and
    displays the complete matrix including zero values.
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
	printf("Enter dimension:\n");
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

int main(){
	struct Sparse m;
	create(&m);
	display(m);
	free(m.e);
	return 0;
	
}