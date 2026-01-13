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

int pop(struct Node **stk){
	(*stk)->top--;
}
int isEmpty(struct Node *stk){
	if(stk->top==-1)
		return 1;
	return 0;
}
int isBalanced(struct Node *stk,char *exp){
	
	for(int i=0;exp[i]!='\0';i++){
		if(exp[i]=='('){
			push(&stk,exp[i]);
		}else if(exp[i]==')'){
			if(isEmpty(stk))
				return 0;
			pop(&stk);
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
	scanf("%s",&exp);
	
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