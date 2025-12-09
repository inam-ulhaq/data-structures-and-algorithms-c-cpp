/*
 Title: Permutation of string using swapping (in-place) method
 Author: Inam Ul Haq
 Description:
    This program generates all permutations of an input string using recursion 
	and backtracking with a swapping mechanism. The algorithm works by modifying 
	the string in place, making it memory efficient.

 How it works (Implementation Details):
 
 1. Swap Function: A utility function used to exchange the positions of two 
 	characters within the string array.
 
 2. Perm Function (Recursive Core):
       Base Case: The recursion terminates when s[l] is the null terminator (\0),
	    indicating a complete permutation has been formed and is ready to be printed.
	    
       Recursive Step (Loop/Explore): A for loop iterates from the current fixed position 
	   l to the end of the string.
        swap(l, i, s);: The character at the current start index l is swapped with the 
		   character at loop index i to select a character for the current position.
        perm(s, l + 1);: Recursively calls the function for the next index (l + 1), 
		   fixing subsequent positions.
        swap(l, i, s);: Backtracking Step: Swaps the characters back to their original 
		   order to reset the state and explore the next possible character choice in the 
		   loop iteration.
*/

#include <stdio.h>
void swap(int l,int i,char *s){
	char temp=s[i];
	s[i]=s[l];
	s[l]=temp;
}
void perm(char *s,int l){
	int i=0;
	if(s[l]=='\0'){
		printf("%s ,",s);
		return;
	}else{
		for(i=l;s[i]!='\0';i++){
			swap(l,i,s);
			perm(s,l+1);
			swap(l,i,s);
		}
	}
	
}



int main(){
	char s[100];
	printf("Enter string: ");
	scanf("%s",s);
	int size=0;
	perm(s,0);
	return 0;
}
		   
	   
 					    