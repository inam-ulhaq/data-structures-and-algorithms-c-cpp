/*
 Title: Converting String to Uppercase in C
 Author: Inam Ul Haq
 Description:
	The goal is to change the case of characters within a given C-style string, 
	specifically converting all lowercase letters to uppercase letters.

	We accomplish this by understanding the ASCII character set and modifying 
	the string in place using pointer access. The key insight is the fixed 
	difference in ASCII values between uppercase and lowercase letters.

	Consider the following function implementation:
	void intoUppercase(char *s){ ... }

	In the implementation above:
	1. The function accepts a pointer (char *s), which allows direct manipulation 
		of the characters in the original array (sentance in the main function).
	2. We iterate through the string character by character using a loop that 
		terminates only when the null character (\0) is encountered.
	3. For each character, we check its ASCII value. If the value is within 
		the range of lowercase letters (97-122), we apply a fixed offset.
	4. The crucial conversion step is subtracting 32 (s[i]=ASCII_code-charAsciiDiff;), 
		which shifts the ASCII value from the lowercase range to the corresponding 
		uppercase range (e.g., 'h' (104) becomes 'H' (72)).

	This approach ensures that the original memory block is mutated, resulting in 
	a fully uppercase string without allocating new memory.
*/

#include <stdio.h>


void intoUppercase(char *s){
	int charAsciiDiff=32;
	for(int i=0;s[i]!='\0';i++){
		int ASCII_code=s[i];
		if(ASCII_code >= 97 && ASCII_code <= 122){
			s[i]=ASCII_code-charAsciiDiff;
		}
	}
	
}

int main(){
	char sentance[15]="how are you?";
	intoUppercase(sentance);
	printf("%s",sentance);
	return 0;
}