/*
 Title: Polynomial Operations Using Structures
 Author: Inam Ul Haq

 Description:
 This program implements basic polynomial operations in the C programming language
 using structures and dynamic memory allocation. A polynomial is represented as a
 collection of terms, where each term consists of a coefficient and an exponent.

 The program allows the user to:
 1. Create two polynomials by dynamically allocating memory for their terms.
 2. Display a polynomial in standard mathematical format.
 3. Add two polynomials by combining like terms with the same exponent.
 4. Store the resulting polynomial in a third polynomial structure.
 5. Properly free all dynamically allocated memory to avoid memory leaks.

 The addition operation assumes that the terms of each polynomial are entered in
 descending order of exponents. This ensures correct merging of terms during
 polynomial addition.

 This program demonstrates the use of structures, pointers, dynamic memory
 allocation, and basic polynomial manipulation in C.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term{
	int coffecient;
	int exponent;
};
struct Polynomial{
	int totalTerms;
	struct term *terms;
};

void display(struct Polynomial *p){
	for(int i=0;i<p->totalTerms;i++){
		if(i!=0)
		printf(" + ");
		printf("%d",p->terms[i].coffecient);
		if(p->terms[i].exponent!=0)
			printf("x");
		if(p->terms[i].exponent!=1 && p->terms[i].exponent!=0)
			printf("^%d",p->terms[i].exponent);
	}
	printf("\n");
}

int evaluate(struct Polynomial *p,int x){
	int sum=0;
	for(int i=0;i<p->totalTerms;i++){
		sum+=p->terms[i].coffecient*(pow(x,p->terms[i].exponent));
	}
	return sum;
}
void add(struct Polynomial *p1,struct Polynomial *p2,struct Polynomial *p3){
	p3->totalTerms=p1->totalTerms+p2->totalTerms;
	p3->terms=malloc(p3->totalTerms*sizeof(struct term));
	int i=0,j=0,k=0;
	while(i<p1->totalTerms && j<p2->totalTerms){
		if(p1->terms[i].exponent==p2->terms[j].exponent){
			p3->terms[k].exponent=p1->terms[i].exponent;
			p3->terms[k++].coffecient=p1->terms[i++].coffecient+p2->terms[j++].coffecient;
		}	
		else if(p1->terms[i].exponent>p2->terms[j].exponent){
			p3->terms[k].coffecient=p1->terms[i].coffecient;
			p3->terms[k++].exponent=p1->terms[i++].exponent;
		}
		else{
			p3->terms[k].coffecient=p2->terms[j].coffecient;
			p3->terms[k++].exponent=p2->terms[j++].exponent;
		}
			
	}
	for(;i<p1->totalTerms;i++){
		p3->terms[k].coffecient=p1->terms[i].coffecient;
		p3->terms[k++].exponent=p1->terms[i].exponent;
	}
	for(;j<p2->totalTerms;j++){
		p3->terms[k].coffecient=p2->terms[j].coffecient;
		p3->terms[k++].exponent=p2->terms[j].exponent;
	}
	p3->totalTerms=k;
}

void create(struct Polynomial *p){
	
	int terms;	
	printf("Enter number of terms for polynomial:\n");
	scanf("%d",&terms);
	
	p->totalTerms=terms;
	p->terms=malloc(terms*sizeof(struct term));
	
	printf("Enter terms: ");
	for(int i=0;i<p->totalTerms;i++){
		
		printf("Enter coffecient: ");
		scanf("%d",&p->terms[i].coffecient);
		
		printf("Enter exponent: ");
		scanf("%d",&p->terms[i].exponent);
		
	}


}
int main(){
	
	struct Polynomial p1;
	create(&p1);
	
	struct Polynomial p2;
	create(&p2);
	
	struct Polynomial p3;
	
	add(&p1,&p2,&p3);
	
	display(&p1);
	display(&p2);
	display(&p3);

	free(p1.terms);
	free(p2.terms);
	free(p3.terms);
	return 0;
	
}