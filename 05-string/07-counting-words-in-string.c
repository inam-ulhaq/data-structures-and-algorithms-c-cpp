/*
Title: Counting Words in a String with Edge Case Handling
Author: Inam Ul Haq
Description:
	This program counts the number of words in a given C-style string, specifically
	designed to handle leading, trailing, and potentially extra spaces.
	A word is defined as a sequence of characters delimited by single or multiple spaces.

	The function int wordsCount(char *s) conceptualizes word counting as detecting
	the precise moment we transition from a non-space character to a space character,
	while ensuring we don't count spaces at the very beginning or very end of the string.

	In the implementation:
	1. The function accepts a pointer (char *s) and returns the total word count as an integer.
	2. It initializes a word counter (wCounts) to zero.
	3. It iterates through the string character by character until the null terminator (\0) is encountered.
	4. Word Boundary Logic: The core if statement includes robust checks:
		* i != 0: Ensures we are not checking an invalid s[i-1] index (prevents crashes).
		* s[i-1] != 32 (or ' '): Checks that the previous character was not a space (we were inside a word).
		* s[i] == 32 (or ' '): Checks that the current character is a space (we just exited a word).
		* s[i+1] != '\0': Crucially, this prevents counting the final trailing space in the array as the start 
		  of a "new" word count, ensuring the final +1 addition works correctly even with extra spaces at the end.
	5. The function returns wCounts + 1. This assumes that after filtering out leading/trailing spaces with the 
		loop logic, the total number of words will be exactly one more than the number of valid space transitions 
		detected mid-sentence.
*/ 


#include <stdio.h>

int wordsCount(char *s){
	int wCounts=0;
	for(int i=0;s[i]!='\0';i++){
		int charaterASCII=s[i];
		if(i!=0 && (int)s[i-1] !=32 && (int)s[i]==32 && (int)s[i+1]!='\0'){
			wCounts++;
		}
	}
	return wCounts+1;
	
}

int main(){
	char sentance[15]="Hi this is Inam";
	int totalWords=wordsCount(sentance);
	printf("Total words are: %d",totalWords);
	return 0;
}