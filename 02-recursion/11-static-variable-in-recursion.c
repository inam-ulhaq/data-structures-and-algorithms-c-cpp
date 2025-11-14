// Title: Static Variable in Recursion
// Author: Inam Ul Haq
// Description:
// A static variable is not stored in the stack frame. It is stored in the data segment of memory.
// This means only **one copy** of a static variable exists for the whole program, regardless of 
// how many times the function is called.

// Recursion notes:
// For every function call, a new stack frame is created. Therefore:
// 1. Local variables: A new copy is created for each function call (stored in stack).
// 2. Static variables: Not part of the stack, so no new copy is created. All calls **share the same variable**.
// Hence, a static variable will **retain its value** across recursive calls.

#include <stdio.h>

int recFun(int x){
    static int staticVar=0;
    if(x>0){
        staticVar++;
        return recFun(x-1)+staticVar;
    }
    return 0;
}

int main(){
    int x;
    printf("Enter value for X: ");
    scanf("%d",&x);
    printf("Result: %d",recFun(x));
    return 0;
}