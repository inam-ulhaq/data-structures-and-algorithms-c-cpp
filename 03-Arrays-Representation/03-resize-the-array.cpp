// Title: Resizing a Dynamic Array
// Author: Inam Ul Haq
// Description:
//     Directly increasing the size of an array is not possible.
//     This approach creates a new array with a larger size and copies
//     the existing values into it.
//
// Steps:
//     1. Ensure an existing dynamic array and pointer exist.
//     2. Allocate a new array of the desired size.
//     3. Copy values from the old array to the new array.
//     4. Free the memory of the old array.
//     5. Point the original pointer to the new array.
//     6. Set the temporary pointer to nullptr to prevent dangling.
//
// Note:
//     The original array is not resized; a new array is created with the old values.

#include <iostream>
#include <cstdio>
#include <cstdlib>

int* arrResize(int *ptr,int newSize){

    int *q=(int *)malloc(newSize*sizeof(int)); // creating new array

    for(int i=0;i<5;i++)
        q[i]=ptr[i]; // the values
    free(ptr); // free the old memory
    return q; // to set the orignal pointer the new array
}
int main(){

    
    int *ptr=(int *)malloc(5*sizeof(int)); //creating array of size 5

    for(int i=0;i<5;i++) 
        ptr[i]=i+1; // intailizing the array

    for(int i=0;i<5;i++)
        printf("ptr[%d] = %d\n",i,ptr[i]); // printing the element of array

    int newSize; // varible to resize the array

    printf("Enter new size for re-size the array: ");
    scanf("%d",&newSize);
    ptr=arrResize(ptr,newSize); // calling the function to resize the array

    for(int i=5;i<newSize;i++)
        ptr[i]=i+1; // store new values array

    for(int i=0;i<newSize;i++){
        printf("ptr[%d] = %d\n",i,ptr[i]); // printing the values form the array
    }
    free(ptr); // freeing the mamory 
    return 0;
}