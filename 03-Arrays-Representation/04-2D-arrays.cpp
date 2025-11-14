// Title: 2D Arrays 
// Author: Inam Ul Haq 
// Explanation:
//     Programming languages allow n-dimensional arrays. Commonly, we use one-dimensional,
//     two-dimensional, or sometimes three-dimensional arrays.
//
// 2D Array 
//     A two-dimensional (2D) array is a collection of elements arranged in rows and columns, 
//     forming a matrix-like structure. Each element is accessed using two indices: one for the 
//     row and one for the column.
//
//     This type of array is mostly useful for implementing matrices or storing tabular data.
//
// -----------------------------------------------------------------------------
// 1st Method: Creating a Static 2D Array
//     Example: int arr1[3][3];
//     1. This creates an integer array with 3 rows and 3 columns in stack memory.
//     2. We can visualize it like a table:
//         _________________________
//         |       |       |       |
//         -------------------------
//         |       |       |       |
//         -------------------------
//         |       |       |       |
//         -------------------------
//     3. In reality, memory is allocated linearly because arrays are stored contiguously.
//        Example: int arr1[2][2];
//            -----------------
//     arr1 = |   |   |   |   | 
//            -----------------
//        If the address of the first element is 20, then the next elements are at 24, 28,
//        and the last one at 32.
//
// -----------------------------------------------------------------------------
// 2nd Method: Array of Pointers to Arrays
//     1. This is an array of pointers where each pointer points to a separate array in memory.
//     2. It has two parts:
//        - Part 1: An array of pointers (allocated on the stack).
//          Example: int* arr2[3];
//        - Part 2: Actual arrays allocated in the heap and pointed to by arr2[i].
//          Example: arr2[0] = new int[3];
//     3. Each pointer (arr2[i]) points to an integer array in the heap.
//     4. Access works like a normal 2D array, e.g., arr2[0][2] = 3.
//
// -----------------------------------------------------------------------------
// 3rd Method: Fully Dynamic 2D Array (Heap Only)
//     1. In this method, both the array of pointers and the actual arrays are allocated 
//        inside the heap.
//     2. A pointer variable on the stack points to an array of pointers in the heap.
//        Example: int** ptr = new int*[3];
//     3. Each of these pointers is then assigned to a new array in the heap:
//            ptr[0] = new int[3];
//            ptr[1] = new int[3];
//            ptr[2] = new int[3];
//     4. This results in three separate arrays in heap memory, all managed dynamically.
//
// -----------------------------------------------------------------------------


#include <iostream>

int main(){
    
    std::cout<<"\nStatic 2D Array\n";
    int arr1[3][3]={{1,2,3},{2,3,4},{6,7,8}}; // with direct intilization

    // traverse
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<"arr1["<<i<<"]["<<j<<"] = "<<arr1[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"\nArray of pointers to Arrays\n";
    int *arr2[3]; // array of pointers
    arr2[0]= new int[3]; // actual array
    arr2[1]= new int[3];
    arr2[2]= new int[3];

    // intailizing the array
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr2[i][j]=i;
        }
    }

    // traverse
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<"arr2["<<i<<"]["<<j<<"]= "<<arr2[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"\nFully Dynamic 2D Array\n";
    int **ptr=new int*[3]; // declaring array of pointers inside heap
    for(int i=0;i<3;i++){
        ptr[i]=new int[3]; // allocating actual array inside heap
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ptr[i][j]=j; // intailizing array
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<"ptr["<<i<<"]["<<j<<"]= "<<ptr[i][j]<<"  "; // traverse
        }
        std::cout<<std::endl;
    }

    for(int i=0;i<3;i++){
        delete []ptr[i]; // free the inner arrays
    }
    delete []ptr; // free the array of pointer
    return 0;

}

