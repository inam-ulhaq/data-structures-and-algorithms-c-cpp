/*
 Title: Counting Vowels and Consonants in C
 Author: Inam Ul Haq
 Description:
	The goal is to analyze a given C-style string and determine the total counts 
	of both vowels and consonants present within it.

	We accomplish this by iterating through the character array and checking each 
	character against the set of English alphabet letters (both uppercase and lowercase).

	Consider the following function implementation:
	void countVowelsAndConsonants(char *s){ ... }

	In the implementation above:
	1. The function accepts a pointer (char *s), allowing it to read the characters 
		from the original array (sentance in the main function).
	2. We initialize counters for vowels (vCounts) and consonants (cCounts).
	3. We iterate through the string character by character until the null terminator (\0) 
		is encountered.
	4. Inside the loop, we first check if the character is an alphabet letter 
		(either A-Z or a-z) to ignore spaces and punctuation.
	5. If it is a letter, we use a conditional check (if/else) to determine if the 
		specific character is a vowel ('a', 'e', 'i', 'o', 'u', and their uppercase 
		equivalents—note that 'V' and 'v' are typically treated as consonants, so 
		they are moved to the consonant count in this logic).
	6. Finally, the total counts are printed to the console.
*/


#include <stdio.h>


void countVowelsAndConsonants(char *s){
	int vCounts=0;
	int cCounts=0;
	for(int i=0;s[i]!='\0';i++){
		int ASCIIcode=s[i];
		if(ASCIIcode >= 65 && ASCIIcode <=90 || ASCIIcode >= 97 && ASCIIcode <= 122)
			if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u' || s[i]=='V' || s[i]=='v'){
				vCounts++;
			}else{
				cCounts++;
			}
	}
	printf("Consonant: %d  Vowals: %d\n",cCounts,vCounts);
	
}

int main(){
	char sentance[15]="how are you?";
	countVowelsAndConsonants(sentance);
	
	return 0;
}