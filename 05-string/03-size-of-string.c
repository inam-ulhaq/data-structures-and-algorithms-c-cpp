/*
 Title: Understanding String Size in C\C++
 Author: Inam Ul Haq
 Description:
	A string in the C\C++ programming language is fundamentally a collection of characters 
	terminated by a null character (\0). To correctly calculate the size or length of 
	such a string, we must traverse the character array sequentially and count the 
	characters only until the \0 marker appears.
	
	Consider the following character array declaration:
	char name[10]={'i','n','a','m','\0',0,0,0,0,0};
	In the above example, the total capacity of the physical array container is 10 bytes. 
	However, when we analyze the string data itself, the name "inam" only occupies four 
	effective spaces before the terminator is hit.
	Therefore, we cannot consider the whole array's capacity as the string's logical size. 
	The true string length is defined strictly by the number of characters preceding the 
	null terminator (which is 4 in this case), not the total capacity of the memory block 
	in which it resides.
	*/

#include <stdio.h>

int size(char *string){
	int i=0;
	while(string[i++]!='\0');
		
	return i-1;
}

int main(){
	char *string="inam";
	
	printf("size is: %d",size(string));
}