/*
 Title: Parenthesis Matching Algorithem
 Author: Inam Ul Haq
 Description:
 	

*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int size;
	int top;
	char *S;
};

int sizeOfExp(char *exp){
	int i=0;
	while(exp[i]!='\0'){
		i++;
	}
	return i;
}

void push(struct Node **stk,char brace){
	(*stk)->top++;
	(*stk)->S[(*stk)->top]=brace;
}

int pop(struct Node **stk,int brace){
	int ascci=(*stk)->S[(*stk)->top];
	
	if( ascci==40 && brace==41)
		(*stk)->top--;
	else if(ascci==60 && brace==62)
		(*stk)->top--;
	else if(ascci==91 && brace==93)
		(*stk)->top--;
	else if(ascci==123 && brace==125)
		(*stk)->top--;
	else
		return 0;

	return 1;
}
int isEmpty(struct Node *stk){
	if(stk->top==-1)
		return 1;
	return 0;
}


int isBalanced(struct Node *stk,char *exp){
	
	for(int i=0;exp[i]!='\0';i++){
		
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' || exp[i]=='<'){
		
			push(&stk,exp[i]);
			
		}else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' || exp[i]=='>'){
			
			if(isEmpty(stk))
				return 0;
				
			if(!pop(&stk,exp[i]))
				return 0;
		}
	}
	if(!isEmpty(stk))
		return 0;
	return 1;
	
}

int main(){
	struct Node stk;
	char exp[100];
	printf("Enter expression: ");
	fgets(exp, sizeof(exp), stdin);
	
	stk.size=sizeOfExp(exp);
	stk.S=malloc(stk.size*sizeof(char));
	stk.top=-1;
	
	if(isBalanced(&stk,exp)){
		printf("Braces are balanced\n");
	}
	else{
		printf("Braces are unbalanced.\n");
	}
	
	free(stk.S);
	stk.S=NULL;
	return 0;
	
}