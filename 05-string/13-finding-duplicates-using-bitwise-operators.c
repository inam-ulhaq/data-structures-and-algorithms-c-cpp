/*
 Title: Find Duplicate Characters in a String
 Author: Inam Ul Haq
 Description:
 	This program prompts the user to enter a string (assumed to contain
    only lowercase English letters) and then uses a bitwise operation
    (a single integer called 'hashMap' acting as a bit vector or bitmask)
    to efficiently find and print any duplicate lowercase characters within that string.

    The technique works by mapping each of the 26 possible lowercase letters ('a' to 'z')
    to a unique bit position (0 to 25) within the 'hashMap' integer.

    1. Mapping: The expression 's[i] - 97' (or 's[i] - 'a'') calculates the
       0-based index for the character (e.g., 'a' is 0, 'b' is 1).
    2. Mask Creation: The expression '1 << index' creates a mask ('x')
       where only the character's corresponding bit is set to 1.
    3. Duplicate Check: The bitwise AND operation ' (hashMap & x) > 0 '
       checks if that bit is already set in 'hashMap', indicating a duplicate.
    4. Marking: If it's not a duplicate, the bitwise OR operation ' hashMap = x | hashMap '
       sets the corresponding bit in 'hashMap' to 1, marking the character as seen.

    This method is highly efficient in terms of memory, using only one integer
    to track the presence of all 26 possible letters.
*/
#include <stdio.h>

void findDuplicates(char *s){
	int hashMap=0;
	for(int i=0;s[i]!='\0';i++){
		int x=1<<s[i]-97;
		if((hashMap&x)>0){
			printf("%c ",s[i]);
		}else{
			hashMap=x|hashMap;
		}
		
	}
}

int main(){
	char  string[100];
	printf("Enetr string: ");
	scanf("%s",string);
	findDuplicates(string);
	return 0;
}