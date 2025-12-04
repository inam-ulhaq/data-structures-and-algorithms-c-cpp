/*
 Title: Palindrome Checker
 Author: Inam Ul Haq
 Description: 
	
	What is a Palindrome?
	A palindrome is a sequence of characters (a word, phrase, number, etc.) that 
	reads the same backward as forward. Examples include "madam", "racecar", or "level".
	
	How to Check if a String is a Palindrome
	The most efficient method is a two-pointer approach:
	1. Initialize Pointers: Set one pointer (j) at the start (index 0) and another (i) at 
		the end of the string.
	2. Compare: Check if the characters at i and j are equal.
	3. Move Inward: If they match, move j forward and i backward.
	4. Exit/Result: If a mismatch occurs, it's not a palindrome. If the pointers meet or 
		cross without mismatches, it is a palindrome.

	How Our Function isPilandrome Works
	Our function implements this two-pointer strategy in-place:
	- It first calculates the length of the string to find the correct starting index for 
		the end pointer (i).
	- It initializes a start pointer (j) to 0.
	- A while (j <= i) loop compares s[j] and s[i].
	- The post-increment/decrement (j++ and i--) move the pointers inward after each 
		comparison.
	- If an if condition detects a mismatch, it immediately returns 0 (false).
	- If the loop finishes entirely, it returns 1 (true).
*/

#include <stdio.h>
int isPalindrome(char *s){
	int i=0;
	while(s[i]!='\0'){i++;}
	i--;
	int j=0;
	while(j<=i){
		if(s[j++]!=s[i--]){
			return 0;
		}
	}
	return 1;
}

int main(){
	char string[10];
	printf("Enter string: ");
	gets(string);
	printf("Is \"%s\" palindrome: %s",string,(isPalindrome(string)? "true" : "false"));
	return 0;
}