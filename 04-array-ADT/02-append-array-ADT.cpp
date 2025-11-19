// Title: Array Abstract Data type
// Author: Inam Ul Haq
// Explanation:
//     The Append operation adds a new element at the end of the array
//     if there is enough space. The element is added at index = length,
//     and then the length of the array is incremented by 1.
//
// Example:
//     If the array is {1, 2, 3, 4, 5} with length = 5,
//     Append(&arr, 7) will update the array to: {1, 2, 3, 4, 5, 7}
//     and length becomes 6.

#include <stdio.h>

struct array {
    int A[10];  
    int size;   
    int length; 
};

void display(struct array *arr) {               
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);          
    }
    printf("\n");
}

void Append(struct array *arr, int x) {
    if (arr->length < arr->size) {      // Only append if space is available
        arr->A[arr->length] = x;        // Place element at the end
        arr->length++;                  // Increment length
    } else {
        printf("Array is full!\n");
    }
}

int main() {
    struct array arr = {{1, 2, 3, 4, 5}, 10, 5};

    display(&arr);       // Display initial array
    Append(&arr, 7);     // Append 7
    display(&arr);       // Display updated array
}

/*

    Time and Space Complexity Analysis

Time Complexity:

Total cost:
    f(n) = 1 + 1 + 1 = 3

Step-by-step:
    1. Check if length < size               -> 1 unit
    2. Assign x to arr[length]             -> 1 unit
    3. Increment length                     -> 1 unit

Asymptotic Time Complexity:
    f(n) ? O(1)  -> Constant time, independent of n

Proof (why O(1)):
    - The number of operations (3) does not depend on the array length n.
    - Even if the array has 0 or 1000 elements, Append performs exactly the same steps.
    - By definition, an operation is O(1) if its execution time is bounded by a constant.
    - Therefore, Append is O(1).

--------------------------------------------------------

Space Complexity:

Total cost:
    g(n) = 0

Step-by-step:
    1. Input array (arr->A) is already allocated -> Not counted
    2. Size variable (arr->size)                 -> Already part of struct
    3. Length variable (arr->length)             -> Already part of struct
    4. No additional variables or arrays         -> 0 units

Asymptotic Space Complexity:
    g(n) ? O(1) ? Constant extra space
*/
