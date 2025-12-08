/*
 Title: Anagram Checker Frequency Map
 Author: Inam Ul Haq
 Description:
isAnagram Function
	This function checks if two input strings (s1 and s2) are anagrams of each other.
	An anagram is a word or phrase formed by rearranging the letters of a different
	word or phrase, typically using all the original letters exactly once.
	
 Assumptions:
	Both input strings only contain lowercase English alphabetic characters ('a'-'z').
	The function implicitly assumes the strings are of equal length, as the character
	counting mechanism verifies all characters in s2 against the counts from s1.
 Approach:
	A frequency map (an array of size 26) is used to count character occurrences.
	Counts characters in the first string (s1).
	Decrements counts for characters found in the second string (s2).
	If any count drops below zero during the second loop, the strings
	cannot be anagrams, and the function immediately returns 0 (False).
	If the function completes the second loop without returning 0, the strings
	are anagrams, and it returns 1 (True).
 Parameters:
	char *s1: Pointer to the first string.
	char *s2: Pointer to the second string.
 Returns:
	int: 1 if the strings are anagrams, 0 otherwise.
*/


#include <stdio.h>

int isAnagram(char *s1,char *s2){
	
	
	int hashMap[26]={0};
	for(int i=0;s1[i]!='\0';i++){
		hashMap[s1[i]-'a']++;
	}
	for(int i=0;s2[i]!=0;i++){
		hashMap[s2[i]-'a']--;
		if(hashMap[s2[i]-'a']<0){
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