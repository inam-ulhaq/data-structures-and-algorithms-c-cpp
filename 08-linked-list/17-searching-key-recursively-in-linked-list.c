/*
    Title   : Searching in Singly Linked List using Recursion
    Author  : Inam Ul Haq

    Description:
        This program implements a singly linked list and performs a
        search operation using a recursive approach. Nodes are inserted
        at the end of the linked list, and the search function recursively
        traverses the list starting from the head node to locate a given
        key.

        The recursive search checks the data of the current node and
        then calls itself on the next node until either the key is found
        or the end of the linked list is reached.

    Time Complexity (Search Function):
        - Best Case: O(1)
          The key is found at the head node in the first comparison.
        - Worst Case: O(n)
          The key is found at the last node or is not present in the list.
        - Average Case: O(n)
          On average, half of the linked list is traversed.

    Space Complexity (Search Function):
        - Due to recursion, each function call is stored on the call stack.
        - In the worst case, n recursive calls are made.
        - Therefore, the space complexity is O(n).
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Structure definition for a singly linked list node */
struct Node{
    int data;              // Stores data of the node
    struct Node *next;     // Pointer to the next node
};

/* Initializes a newly created node */
void initNode(struct Node *newNode, int value){
    newNode->data = value;
    newNode->next = NULL;
}

/* Inserts a new node at the end of the linked list */
void insertAtLast(struct Node **head, int value){
    struct Node *newNode = malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    initNode(newNode, value);

    // If the list is empty, make new node the head
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *current = *head;
    while(current->next){
        current = current->next;
    }

    // Attach new node at the end
    current->next = newNode;
}

/* 
   Recursively searches for a key in the linked list
   Returns pointer to the node if found, otherwise NULL
*/
struct Node* searchRec(struct Node *head, int key){

    // Base case: end of list
    if(head == NULL){
        return NULL;
    }

    // If key matches current node data
    if(head->data == key){
        return head;
    }

    // Recursive call on next node
    return searchRec(head->next, key);
}

/* Frees all nodes of the linked list */
void freeNodes(struct Node *head){
    if(head != NULL){
        freeNodes(head->next);
        free(head);
    }
}

int main(){
    struct Node *head = NULL;
    int size;

    // Read size of the linked list
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    // Insert elements into the linked list
    for(int i = 0; i < size; i++){
        int value;
        printf("Enter value for Node(%d): ", i + 1);
        scanf("%d", &value);
        insertAtLast(&head, value);
    }

	int key;

    printf("Enter key: ");
    scanf("%d", &key);

    // Call recursive search function
    struct Node* temp = searchRec(head, key);

    if(temp)
        printf("Key %d found!\n", temp->data);
    else
        printf("Key not found!\n");


    // Free allocated memory
    freeNodes(head);
    return 0;
}
