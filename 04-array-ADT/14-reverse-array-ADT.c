// Title: Reverse List
// Author: Inam Ul Haq
// Description:
//     To reverse an array, we have two methods:
//
//     1. Using an auxiliary (extra) array:
//          - Create a temporary array.
//          - Copy elements from the original array into this temporary array
//            in reverse order.
//          - Then copy the reversed elements back into the original array.
//          - After copying, the original array becomes reversed.
//
//     2. Using the two-pointer swapping method:
//          - Start scanning the array from both ends.
//          - Swap the first element with the last element,
//            the second with the second-last, and so on.
//          - Continue swapping until the two pointers meet or cross.
		

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *array;
    int size;
    int length;
};

void initList(struct Array *list, int size) {
    list->size = size;
    list->array = (int *)malloc(size * sizeof(int));
    if (list->array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    list->length = 0;
}

void freeList(struct Array *list) {
    free(list->array);
    list->array = NULL;
}

void reverseWithAuxiliaryArray(struct Array *list) {
    struct Array listCopy;
    initList(&listCopy, list->length);

    for (int i = 0, j = list->length - 1; i < list->length; i++, j--) {
        listCopy.array[i] = list->array[j];
    }

    for (int i = 0; i < list->length; i++) {
        list->array[i] = listCopy.array[i];
    }

    freeList(&listCopy);
}

void reverseInPlace(struct Array *list) {
    for (int i = 0, j = list->length - 1; i < j; i++, j--) {
        int temp = list->array[i];
        list->array[i] = list->array[j];
        list->array[j] = temp;
    }
}

int main() {
    int size;
    printf("Enter size of list: ");
    scanf("%d", &size);

    struct Array list;
    initList(&list, size);

    for (int i = 0; i < size; i++) {
        list.array[i] = i + 1;
    }
    list.length = size;

    printf("\nOriginal List: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.array[i]);
    }

    // Call first reverse method
    reverseWithAuxiliaryArray(&list);
    printf("\nAfter reverseWithAuxiliaryArray(): ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.array[i]);
    }

    // Call second reverse method
    reverseInPlace(&list);
    printf("\nAfter reverseInPlace(): ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.array[i]);
    }

    freeList(&list);
    return 0;
}
