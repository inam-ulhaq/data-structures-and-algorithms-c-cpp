/*
 Title: Validate String
 Author: Inam Ul Haq
 Description:
	This C program defines a function isValid to check if a given string consists 
	entirely of alphanumeric characters (a-z, A-Z, 0-9). 
	It achieves this by iterating through the string and verifying that each 
	character's ASCII value falls within the valid ranges for digits or letters. 
	The main function demonstrates how to use this validation function 
	with a sample string and prints the result.
	
*/
 	
#include <stdio.h>
int isValid(char *name){
	int i=0;
	while((int)name[i]!='\0'){
		if(!(((int)name[i] >= 48 && (int)name[i] <=57) || ((int)name[i] >= 65 && (int)name[i] <= 90) || ((int)name[i] >= 97 && (int)name[i] <= 122))){
			return 0;
		}
		i++;
	}
	return 1;
}
int main(){
	char *name="Inam123";
	int isTrue=isValid(name);
	if(isTrue){
		printf("\"%s\" is a valid string.\n",name);
	}else{
		printf("\"%s\" is not a valid string.\n",name);
	}
	return 0;
}