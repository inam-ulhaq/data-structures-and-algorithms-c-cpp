/*
 Title:
 Author: Inam Ul Haq
 Description: 
 
 This program takes a string input from the user and identifies all duplicate lowercase characters present within that string.
 It uses a frequency counting method (similar to a hash map) with a fixed-size array to store counts for 'a' through 'z'.
 The code employs safe input practices using fgets() to prevent buffer overflows and iterates through the counts to display results efficiently.
 
*/


#include <stdio.h>
#include <string.h>

void findDuplicates(char *s) {
    int hashMap[26] = {0};
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            int charIndex = s[i] - 'a';
            hashMap[charIndex]++;
        }
        i++;
    }

    printf("Duplicate characters: ");
    for (int j = 0; j < 26; j++) {
        if (hashMap[j] > 1) {
            printf("%c ", (char)(j + 'a'));
        }
    }
    printf("\n");
}

int main() {
    char string[100]; 
    printf("Enter string (lowercase only): ");
    
    if (fgets(string, sizeof(string), stdin) != NULL) {
        string[strcspn(string, "\n")] = 0; 
        findDuplicates(string);
    }

    return 0;
}