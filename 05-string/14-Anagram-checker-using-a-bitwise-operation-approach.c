
/*
 Title: Anagram Checker
 Author: Inam Ul Haq
 Description:
isAnagram Function
/*
 Title: Anagram Checker Using a Bitwise Operation Approach
 Author: Inam Ul Haq
 Description:
 isAnagram Function
	 This function checks if two input strings (s1 and s2) are anagrams of each other 
	 using a bitwise operation approach (a single integer used as a bitmask).
	 
	 Note: The code provided in the function body is different from the approach 
	 described in the original comment block (which described a frequency array). 
	 The function body uses a bitmask, which only checks for the *presence* of 
	 characters, not their *frequency* or count.
	 
 Assumptions (based on the function code logic):
	 - The strings must have the exact same characters present, but not necessarily 
	   the same count for each character (e.g., "aabb" and "ab" would return True incorrectly).
	 - Both input strings only contain lowercase English alphabetic characters ('a'-'z').
	 
 Parameters:
	 - char *s1: Pointer to the first string.
	 - char *s2: Pointer to the second string.
 
 Returns:
	 - int: 1 if the strings have the exact same set of characters present, 0 otherwise.
*/
#include <stdio.h>

int isAnagram(char *s1,char *s2){
	int i=0,j=0;
	while(s1[i]!='\0' || s2[j]!='0'){i++,j++;}
	if(i!=j){
		return 0;
	}
	
	int hashMap=0;
	for(int i=0;s1[i]!='\0';i++){
		int x=1<<s1[i]-'a';
		hashMap=hashMap|x;
	}
	for(int i=0;s2[i]!=0;i++){
		int x=1<<s2[i]-'a';
		if(!((hashMap&x)>0)){
			return 0;
		}
	}
	return 1;
	
}

int main(){
	char firstWord[100];
	char secondWord[100];
	
	printf("Enter first word: ");
	scanf("%s",firstWord);
	printf("Enter seconde word: ");
	scanf("%s",secondWord);
	printf("%s\n",isAnagram(firstWord,secondWord)?"True":"False");
	return 0;
}