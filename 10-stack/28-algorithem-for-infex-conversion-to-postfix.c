#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
	int size;
	int top;
	char *s;
};

int isEmpty(struct Stack *stk){
	if(stk->top==-1)
		return 1;
	return 0;
}

char pop(struct Stack **stk){
	if((*stk)->top==-1)
		return 0;
	char operat=(*stk)->s[(*stk)->top];
	(*stk)->top--;
	return operat;
}

void push(struct Stack **stk,char operat){
	if((*stk)->top==(*stk)->size-1)
		return;
	(*stk)->top++;
	(*stk)->s[(*stk)->top]=operat;
}

int isOperator(char operat){
	if(operat=='+' || operat=='-' || operat=='*' || operat=='/' || operat=='(' || operat==')' || operat=='^' )
		return 1;
	return 0;
}
int inStkPrece(char operat){
	if(operat=='+' || operat=='-')
		return 2;
	else if(operat=='*' || operat=='/')
		return 4;
	else if(operat=='^')
		return 5;
	else if(operat=='(')
		return 0;
	return 0;
}

int outStkPrece(char operat){
	if(operat=='+' || operat=='-')
		return 1;
	else if(operat=='*' || operat=='/')
		return 3;
	else if(operat=='^')
		return 6;
	else if(operat=='(')
		return 7;
	else if(operat==')')
		return 0;
}
char stackTop(struct Stack *stk){
	return stk->s[stk->top];
}

char *convertToPostfix(char *exp){
	
	int size=strlen(exp);
	struct Stack *stk=malloc(sizeof(struct Stack));
	stk->size=size;
	stk->s=malloc((size+1)*sizeof(char));
	stk->top=-1;
	char *postfix=malloc((size+1)*sizeof(char));
	int i=0;
	int j=0;
	j=i;
	while(exp[i]!='\0'){
		
		if(isOperator(exp[i])){
			if(outStkPrece(exp[i])>inStkPrece(stackTop(stk))){
				push(&stk,exp[i++]);
			}else if(outStkPrece(exp[i])==inStkPrece(stackTop(stk))){
				pop(&stk); 
				i++;
			}
			else{
				postfix[j++]=pop(&stk);
			}
		}else{
			postfix[j++]=exp[i++];
		}
	}
	while(!isEmpty(stk)){
		postfix[j++]=pop(&stk);
	}
	postfix[j]='\0';
	return postfix;
}
	

int main(){
	char exp[100];
	printf("Enter expression: ");
	scanf("%s",&exp);
	
	char *postfix=convertToPostfix(exp);
	printf("%s",postfix);
	return 0;
	
}