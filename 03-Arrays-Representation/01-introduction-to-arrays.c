// Title: Introduction to Arrays
// Author: Inam Ul Haq
// Description: 
//    Scalar Variable:
//      A scalar variable stores only a single value (magnitude) and does not have any direction.
//      Example: int x = 10;
//      'x' holds a single value 10
//
//    Vector Variable (Arrays):
//      An array is a collection of values of the same data type, grouped under a single name in memory.
//      Each value in the array can be accessed using an index (starting from 0 in C/C++).
//      Arrays are vector-like in nature, meaning they can store multiple values sequentially in memory.
//
// Example of an array:
//      int numbers[5] = {10, 20, 30, 40, 50};
//       'numbers' is an array of 5 integers.
//              numbers[0] = 10, numbers[1] = 20, ..., numbers[4] = 50
//
// Ways to declare and initialize arrays:
//
//    1. Declare without initialization
//        int arr1[5]; // Values are undefined (garbage)
//
//    2. Declare and initialize all elements
//        int arr2[5] = {1, 2, 3, 4, 5};
//
//    3. Partial initialization (rest elements set to 0)
//        int arr3[5] = {10, 20}; // arr3[0]=10, arr3[1]=20, arr3[2]=0, arr3[3]=0, arr3[4]=0
//
//    4. Initialize without specifying size (compiler infers size)
//        int arr4[] = {5, 10, 15, 20, 25}; // Size automatically set to 5
//
//    5. Declare first, then assign values using a loop
//        int arr5[5];
//        for(int i = 0; i < 5; i++)
//            arr5[i] = (i + 1) * 5; // arr5 = {5, 10, 15, 20, 25}
//
//    6. Initialize all elements with zero
//        int arr6[5] = {0}; // arr6 = {0, 0, 0, 0, 0}
//
// Ways to access array elements:
//
//    1. Using index
//         int x = arr2[0]; // Access first element
//
//     2. Using a loop
//         for(int i = 0; i < 5; i++)
//             printf("%d ", arr2[i]);
//    
//     3. Using pointer arithmetic
//         int *ptr = arr2;
//          int y = *(ptr + 2); // Access third element
//    
//    4. Modifying elements via index
//         arr2[1] = 50; // Changes second element to 50
//    
//    5. Modifying elements via pointer
//         *(ptr + 3) = 100; // Changes fourth element to 100

#include<stdio.h>S
int main(){
    // 1. Declare without initialization (values are garbage)
    int arr1[5];
    printf("arr1 (uninitialized): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr1[i]);
    printf("\n");

    // 2. Declare and initialize all elements
    int arr2[5]={1,2,3,4,5};
    printf("arr2 (fully initialized): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr2[i]);
    printf("\n");

    // 3. Partial initialization
    int arr3[5]={10,20};
    printf("arr3 (partial initialization): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr3[i]);
    printf("\n");

    // 4. Initialize without specifying size
    int arr4[]={5,10,15,20,25};
    printf("arr4 (compiler infers size): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr4[i]);
    printf("\n");

    // 5. Declare then assign values using loop
    int arr5[5];
    for(int i=0;i<5;i++)
        arr5[i]=(i+1)*5;
    printf("arr5 (assigned in loop): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr5[i]);
    printf("\n");

    // 6. Initialize all elements with zero
    int arr6[5]={0};
    printf("arr6 (all zeros): ");
    for(int i=0;i<5;i++)
        printf("%d ",arr6[i]);
    printf("\n");

    // ---- Accessing arrays ----
    printf("\n--- Accessing Arrays ---\n");

    // 1. Using index
    int x=arr2[0];
    printf("arr2[0]=%d\n",x);

    // 2. Using a loop
    printf("arr2 using loop: ");
    for(int i=0;i<5;i++)
        printf("%d ",arr2[i]);
    printf("\n");

    // 3. Using pointer arithmetic
    int*ptr=arr2;
    int y=*(ptr+2);
    printf("Third element of arr2 using pointer=%d\n",y);

    // 4. Modifying via index
    arr2[1]=50;
    printf("arr2 after arr2[1]=50: ");
    for(int i=0;i<5;i++)
        printf("%d ",arr2[i]);
    printf("\n");

    // 5. Modifying via pointer
    *(ptr+3)=100;
    printf("arr2 after *(ptr+3)=100: ");
    for(int i=0;i<5;i++)
        printf("%d ",arr2[i]);
    printf("\n");

    return 0;
}
