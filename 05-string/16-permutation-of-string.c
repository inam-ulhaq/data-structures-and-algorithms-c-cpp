/*
 Title: Permutation of string
 Author: Inam Ul Haq
 Description:
	In Mathematics, a Perutation is defined as a mathematical concept that 
	determines the number of possible arrangments for a specific set of elements.
	Therefore, it plays a big role in computer science, cryptography, and operations research.
	
	Note: In Permutations, order matters; for example, (2, 1) and (1, 2) are counted as different.
 Example:
 	Let's we have a set of three elements i.e. {A,B,C}, So The possible arrangment are give below
 	
 							(	START   )
 						    / 	   | 	 \
 						   A 	   B 	  C
 						  /\ 	  /\ 	  /\
 						 B  C    A  C    A  B
 						/   \    /   \   /   \
 			  -------- C    B    C   A   B    A-------
 		     |		      /     /     \    \          \
 			{A,B,C},{A,C,B},{B,A,C},{B,C,A},{C,A,B},{C,B,A}
 					   
 	This make tree where the least are showing us results and such a tree is called "State space tree" and
	one more thing that we can observe about this tree is we are starting with an element going in deep and
	deep till the end and form there we are comming back and going with a new root, this is calles as "Back tracking".
	Total possible arrangments are: {A,B,C},{A,C,B},{B,A,C},{B,C,A},{C,A,B},{C,B,A},  In which the total 
	elements are 3 and the possible arrangments are 6 which is equal to 3!(3 factorial), So for n number of 
	elements the total possible arrangements will be equal to n! and that can be determines by the formula nCr=n!/(n-r)!.
	In this way we can find all possible solution, While finding all posible solution is known as brute force.
	
 How to implement:
 	If we look to the whole process we are going in one direction and then go back and taking another root, These
 	type of procedure can be implemented using recursion. We are using recursion to achvie back tracking and by 
 	back tracking we can perform brute force.

*/

#include <stdio.h>

void perm(char *s,int k){
	static int H[10]={0};
	static char r[10]={0};
	int i=0;
	if(s[k]=='\0'){
		r[k]='\0';
		printf("%s ,",r);
		return;
	}else{
		for(i=0;s[i]!='\0';i++){
			if(H[i]==0){
				H[i]=1;
				r[k]=s[i];
				perm(s,k+1);
				H[i]=0;
			}
		}
	}
	
}



int main(){
	char s[100];
	printf("Enter string: ");
	scanf("%s",s);
	perm(s,0);
	return 0;
}
		   
	   
 					    