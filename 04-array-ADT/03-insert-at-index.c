// Title: Inserting in Array ADT at Index
// Author: Inam Ul Haq
// Description:
//
//    Inserting at a specific index in an Array ADT means adding a new element
//    at the given index without losing existing data.
//
//    We pass the element and a valid index to the insert function.
//    A valid index must not exceed the size of the array or the current length.
//
//    There are two cases:
//
//    1 ? Inserting at an empty position (index == length)
//        - No shifting is needed.
//        - Simply place the value at the given index.
//        - This is the best-case insertion.
//
//    2 ? Inserting at a non-empty position (index < length)
//        - If we directly write the new value, the old value will be overwritten.
//        - To avoid losing data, we shift all elements to the right, one-by-one,
//          starting from the last element up to the target index.
//        - After creating the free space, we insert the new value.

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int* A;
    int size;
    int length;

    Array(int size) {
        this->size = size;
        A = (int*)malloc(size * sizeof(int));
        this->length = 0;
    }
};

void insertAT(int index, int value, Array* arr) {
    if (index < 0 || index > arr->length || arr->length == arr->size) {
        printf("Invalid index or array is full.\n");
        return;
    }

    // Shift elements only if inserting in the middle
    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[index] = value;
    arr->length++;
}

int main() {
    int size;
    printf("Please enter size of array: ");
    scanf("%d", &size);

    Array arr(size);

    // Insert 10 values at index 0
    for (int i = 10; i > 0; i--)
        insertAT(0, i, &arr);

    // Print results
    for (int i = 0; i < arr.length; i++)
        printf("%d  ", arr.A[i]);

    return 0;
}
