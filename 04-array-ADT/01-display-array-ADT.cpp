// Title: Array Abstract Data type
// Author: Inam Ul Haq
// Explanation:
//     The Display operation is used to traverse the array and print
//     all the elements stored in it. Traversing means visiting
//     each element one by one, starting from index 0 up to
//     index (length - 1). The traversal depends only on the
//     current length (number of elements filled), not on the
//     total size (capacity) of the array.
//
// Example:
//     If the array is {1, 2, 3, 4, 5} and length = 5,
//     the display function will print: 1 2 3 4 5
//
#include <stdio.h>

struct array {
    int A[10];   // Array space (capacity = 10 elements)
    int size;    // Maximum number of elements that can be stored
    int length;  // Current number of elements stored
};

void display(struct array *arr) {               
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);          
    }
    printf("\n");
}

int main() {
    struct array arr = {{1,2,3,4,5}, 10, 5};
    display(&arr);     
}

/*
    Time and Space Complexity Analysis

Time Complexity (step by step):
    1. Initialization (int i = 0)        -> 1 unit
    2. Loop condition check (i < length) -> (n + 1) units
    3. Increment (i++)                   -> n units
    4. Print each element (printf)       -> n units
    5. Print newline (printf("\n"))      -> 1 unit

Total cost:
    f(n) = 1 + (n + 1) + n + n + 1
    f(n) = 3n + 3

Asymptotic Time Complexity:
    f(n) ? O(n)

--------------------------------------------------------

Space Complexity (step by step):
    1. Input array (arr->A) is already allocated ? Not counted
    2. Size variable (arr->size)                 ? Already part of struct
    3. Length variable (arr->length)             ? Already part of struct
    4. Loop counter variable (int i)             ? 1 unit
    5. No extra arrays or dynamic allocations

Total cost:
    g(n) = 1

Asymptotic Space Complexity:
    g(n) ? O(1) ? Constant extra space

*/
