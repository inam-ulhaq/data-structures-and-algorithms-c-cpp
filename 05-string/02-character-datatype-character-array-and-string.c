// Title: Character, Character Array and String
// Author: Inam Ul Haq
// Description:
// 	Character:
//		A character data type, often represented as char in many programming languages, 
//		is a fundamental data type used to store a single character.
//		Its primary purpose is to hold one character's worth of data at a time.
//		Syntax:
//			char variable_name='single character';
//			
//	Character Array:
//		A char array is a data structure used in programming to store a sequence of 
//		individual characters in contiguous memory locations. It is the fundamental 
//		way that languages like C and C++ implement the concept of a "string."
//		Syntax:
//			char arr_Name[size];
//			
//	String:
//		In C programming, a string is specifically a null-terminated sequence of characters. 
//		It is stored in a character array, and the end of the string is always marked by 
//		a special character called the 'null terminator' ('\0').
//
//		Syntax Examples (All ways to declare/initialize char arrays in C/C++):
//
//          1. Declaration only (fixed size, uninitialized contents/garbage):
//             char array_name[size]; 
//
//          2. Explicit Initialization with Brace List and Size:
//             char array_name[size] = {'C', 'h', 'a', 'r', 's'}; // Size must be sufficient
//
//          3. Explicit Initialization with Brace List (Compiler determines size):
//             char array_name[] = {'W', 'o', 'r', 'l', 'd', '\0'}; // Compiler auto-sizes
//
//          4. Initialization with a String Literal and Size:
//             char array_name = "C Language"; // Size 15, pads remaining bytes with '\0'
//
//          5. Initialization with a String Literal (Compiler determines size):
//             char array_name[] = "Programming"; // Compiler finds exact size + '\0'
//
//          6. Partial Initialization (Remaining elements become '\0' or 0):
//             char array_name = "Hi"; // creates "Hi\0\0\0\0\0\0\0\0"
//             char array_name_zeros = {0}; // initializes entire array to nulls
//
//          7. Pointer Declaration (Points to a string literal in read-only memory):
//             const char* pointer_name = "text"; // A pointer variable, not an array variable
	
	
	
	
#include <stdio.h>
#include <string.h> // Include for string functions like strlen, strcpy, strcat
#include <ctype.h>  // Include for character functions like toupper, isupper
#include <stdlib.h> // Include for dynamic memory allocation functions like malloc	
	
	
int main(){
	
	// --- DEMONSTRATING DIFFERENT WAYS TO USE CHARACTERS AND CHARACTER ARRAYS ---

	// CASE 1: Storing a single character (char data type)
	char grade = 'A'; 
	char newline_char = '\n'; // A control character
	printf("CASE 1: My grade is %c%c", grade, newline_char);


	// CASE 2: Basic String Storage (Using string literals)
	char first_name[] = "Inam";
	char last_name[] = "Ul Haq";
	printf("CASE 2: Full Name is %s %s\n", first_name, last_name);


	// CASE 3: Character-level processing (Looping and manipulation)
	char processing_text[] = "convert to uppercase";
	printf("CASE 3: Before processing: %s\n", processing_text);
	for (int i = 0; processing_text[i] != '\0'; i++) {
        // Use toupper function to change character case within the array
		processing_text[i] = toupper(processing_text[i]); 
    }
	printf("CASE 3: After processing:  %s\n", processing_text);


	// CASE 4: Using standard library functions (Concatenation and Copying)
    // FIX: Added a sufficient size [50] to the destination buffer
	char destination_buffer[50]; 

	strcpy(destination_buffer, first_name); // Copy "Inam" into the buffer
	strcat(destination_buffer, " ");       // Add a space
	strcat(destination_buffer, last_name); // Add "Ul Haq"

	printf("CASE 4: Concatenated name: %s\n", destination_buffer);
	printf("Length of concatenated string: %zu\n", strlen(destination_buffer));


	// CASE 5: Using Pointers for read-only strings
	const char* constant_message_ptr = "This message cannot be changed after creation.";
	printf("CASE 5: Pointer message: %s\n", constant_message_ptr);


	// CASE 6: Using Arrays for Buffering User Input
    // FIX: Added a sufficient size [100] to the input buffer
	char input_buffer[100]; 
	printf("CASE 6: Enter a sentence: ");
	// fgets is safer than scanf for sentences because it handles spaces
	fgets(input_buffer, sizeof(input_buffer), stdin); 
	printf("You entered: %s", input_buffer); 
    // Note: fgets captures the newline character you press, causing an extra line break in the output.


    // CASE 7: Dynamic Memory Allocation (Advanced Use Case)
    // For when you don't know the size needed until the program runs
    char* dynamic_string = (char*)malloc(25 * sizeof(char));
    if (dynamic_string != NULL) {
        strcpy(dynamic_string, "Dynamically allocated!");
        printf("CASE 7: Dynamic string: %s\n", dynamic_string);
        free(dynamic_string); // Must free the memory manually
    }

    return 0;
}
