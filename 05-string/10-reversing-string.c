/*
 Title:: Reversing String In-Place
 Author: Inam Ul Haq
 Description:
	This program defines a function named reverse that reverses the characters 
	of a given string in place. 
	It first calculates the length of the string to find the last index, then 
	uses a two-pointer approach 
	(indices 'i' and 'j') that move inward from both ends, swapping characters 
	until the middle of the string is reached. 
	The main function demonstrates this by reversing the string "inam" and 
	printing the result.
*/

#include <stdio.h>

void reverse(char *s){
	int i=0;
	while(s[i]!='\0'){i++;}
	i--;
	
	for(int j=0;j<i;j++,i--){
		char temp=s[j];
		s[j]=s[i];
		s[i]=temp;
	}
	
}

int main(){
	char string[]="inam";
	reverse(string);
	printf("%s",string);
	return 0;
}