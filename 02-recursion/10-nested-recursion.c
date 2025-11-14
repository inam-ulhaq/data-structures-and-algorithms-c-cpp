// Title: Nested Recursion
// Author: Inam Ul Haq 
// Description: 
// A nested recursion occurs when a function’s argument itself is a call to the
// same function.

// In other words:

// “The function is called inside its own argument.”

// This is different from direct or indirect recursion because the recursion happens
// inside the parameter rather than in separate statements.

// Key Characteristics

// Function calls itself inside its own argument.
// Base case is required to stop infinite recursion.
// Can grow very fast and is harder to trace than linear recursion.

#include <stdio.h>

int fun(int n){
    printf("%d\n",n);
    if(n>100){
        return n-10;
    }else{
        return fun(fun(n+11));
    }
}

int main(){
    int x=0;
    printf("Enter value for X: ");
    scanf("%d",&x);
    fun(x);
    return 0;
}