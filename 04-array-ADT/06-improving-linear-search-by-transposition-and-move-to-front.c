// Title: Improving Linear Search
// Author: Inam Ul Haq
// Description: 
//  If we are searching for a key, there is a chance that the same key will be
//  searched again in the future. To improve future search time, we can move
//  frequently accessed elements closer to the beginning of the list.
//
//  Real-life Example:
//      Suppose you search your bookshelf for a specific book that you read
//      frequently. Next time you want to read it again, you would prefer that
//      it is placed near the front so you can find it faster. The same idea is
//      applied here: if a key is accessed repeatedly, we move it forward.
//
//  Two main methods:
//
//  1. Transposition:
//      - When the key is found, swap it with the previous element.
//      - Frequently used keys slowly move forward.
//      - Useful when repeated searches happen.
//      - Time Complexity:
//            Best Case:    O(1)
//            Worst Case:   O(n)
//            Average Case: O(n)
//            Adjustment Cost (swap): O(1)
//        Overall Time Complexity: O(n)
//
//  2. Move to Front (Move to Head):
//      - When the key is found, move it directly to index 0.
//      - Next time, key is found in O(1).
//      - More aggressive than transposition.
//      - Time Complexity:
//            Best Case:    O(1)
//            Worst Case:   O(n)
//            Average Case: O(n)
//            Adjustment Cost: Shifting 'i' elements ? O(i)
//        Overall Time Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *array;
    int size;
    int length;
};

// Initialize dynamic array
void initList(struct Array *list, int size) {
    list->size = size;
    list->array = (int *)malloc(size * sizeof(int));
    list->length = 0;
}

// Free allocated memory
void freeList(struct Array *list) {
    free(list->array);
}

int linearSearchTransposition(struct Array *list, int key) {
    if (list->length == 0) {
        printf("List is empty.\n");
        return -1;
    }

    for (int i = 0; i < list->length; i++) {
        if (key == list->array[i]) {
            if (i != 0) {
                // Swap with previous element
                int temp = list->array[i];
                list->array[i] = list->array[i - 1];
                list->array[i - 1] = temp;
                return i - 1;   // New index after transposition
            }
            return i;
        }
    }
    return -1; // Not found
}

int linearSearchMoveToFront(struct Array *list, int key) {
    if (list->length == 0) {
        printf("List is empty.\n");
        return -1;
    }

    for (int i = 0; i < list->length; i++) {
        if (key == list->array[i]) {
            if (i != 0) {
                int temp = list->array[i];

                // Shift all elements right
                for (int j = i; j > 0; j--) {
                    list->array[j] = list->array[j - 1];
                }

                // Move key to front
                list->array[0] = temp;
                return 0;
            }
            return i;
        }
    }
    return -1; // Not found
}


int main() {
    int size;

    printf("Enter size of list: ");
    scanf("%d", &size);

    struct Array list;
    initList(&list, size);

    // Fill list with values 1..size
    for (int i = 0; i < size; i++) {
        list.array[i] = i + 1;
    }
    list.length = size;

    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    printf("\n--- Using Transposition Search ---\n");
    for (int i = 0; i < 5; i++) {
        int index = linearSearchTransposition(&list, key);
        if (index == -1)
            printf("Search Unsuccessful.\n");
        else
            printf("%d found at index: %d\n", key, index);
    }

    printf("\n--- Using Move to Front Search ---\n");
    for (int i = 0; i < 5; i++) {
        int index = linearSearchMoveToFront(&list, key);
        if (index == -1)
            printf("Search Unsuccessful.\n");
        else
            printf("%d found at index: %d\n", key, index);
    }

    freeList(&list);
}
