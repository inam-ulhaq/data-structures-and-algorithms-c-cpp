#include <stdio.h>
#include <stdlib.h>

char* reverse(char *s){
	int i=0;
	while(s[i]!='\0'){i++;}
	int size=i;
	char *revStr=malloc((size)*sizeof(char));
	int j=0;
	for(;j<size;j++){
		revStr[j]=s[--i];
	}
	revStr[j]='\0';
	return revStr;
	
}

int main(){
	char *string="inam";
	char *revStr=reverse(string);
	printf("%s",revStr);
	free(revStr);
	return 0;
}