// Title: Static Vs Dynamic Array
// Author: Inam Ul Haq
// Description:
//     Static array:
//         static array mean the size of the array is static, it means that the size
//         of the array is decided at compile time only.
//     key points:
//         1-the size of array known at compile time of the program.
//         2-the array must be declare inside the function.
//         3-the array memory alloacte inside the stack(form stack frame of function).
//         4-the life time is contorled automatically tied with function socpe.

//     Variable length array(VLA);
//         1- the size of the array is constant but varible i.e int "arr[n]".
//         2- the size of the array is not decide at complite time but run time of program.
//         3- the memory still allocated on stack.
//         4- the life time is still tied with function scope.
//         5- not fully true but still consider as a static array due to its memory behaviour.
//         6- not allowed while allowed in c++ but not in standerd c++.
    
//     Dynamic array:
//         it is an array which size is decide it run time of the program.
//     key point:
//         1- the size known it run time.
//         2- memroy allcated in heap with new in c++ and with malloc with c.
//         3- life time must be controll manually in c++ with delete and in c with free();
//         4- use with pointer.
        

#include <iostream>
#include <cstdio>
#include <cstdlib> // for malloc
using namespace std;

int main(){
    // static array
    int arr1[5]={0};

    //VLA
    int n=5;
    int arr2[n];

    //Dynamic memory
    
    int *ptr1; // in c++
    ptr1=new int[5]; 
    ptr1[0]=1; // storing value
    cout<<"C++ Dynamic ptr1[0]= "<<ptr1[0]<<endl; // accessing value
    delete []ptr1; // free meomry allcat by ptr1

    int *ptr2=(int*)malloc(5*sizeof(int)); // in c language
    ptr2[0]=3; // storing value at index 
    printf("C Dynamic ptr2[0] = %d\n",ptr2[0]); // accessing value
    free(ptr2); // free memory by ptr2
    return 0;
}
