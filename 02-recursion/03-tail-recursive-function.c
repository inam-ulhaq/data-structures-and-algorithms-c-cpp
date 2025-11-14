// Title: Tail Recursion:
// Author: Inam Ul Haq
// Description: 
// A function is tail recursive if the recursive call is the last statement 
// executed in the function. In other words, after the recursive call, 
// there is no additional computation left to perform.
//
// In recursion we think in two phases:
//   - Ascending phase: when recursive calls are made (going deeper).
//   - Descending phase: when control returns back (unwinding).
//
// If a function performs all its work during the ascending phase 
// and does nothing in the descending phase (other than returning), 
// it is considered tail recursive.
//
// Tail-recursive functions are easier to convert into iterative 
// (loop-based) solutions because their structure resembles loops. 
// Loops are generally more efficient than recursion because they 
// avoid the overhead of repeated function calls.
// 
// Some compilers are even capable of optimizing tail recursion 
// into a loop automatically (a technique called tail call optimization).
//
// Example below demonstrates a simple tail-recursive function.

#include <stdio.h>

void tailFun(int x) {
    if (x > 0) {
        printf("%d ", x);
        tailFun(x - 1); // recursive call is the last operation -> tail recursion
    }
}

int main() {
    int x;
    printf("Enter value for function calls: ");
    scanf("%d", &x);
    tailFun(x);

    return 0;
}
