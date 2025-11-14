// Title: How Recursion Uses the Stack
// Author: Inam Ul Haq
// Description: 
// A recursive function works in two phases: the calling (ascending) phase 
// and the returning (descending) phase. These phases are managed by the program stack.
//
// In the ascending phase, each time the recursive function is called, a new stack frame 
// (also called an activation record) is created and pushed onto the stack. 
// A stack frame stores:
//   - The function's parameters
//   - The function's local variables
//   - The return address (where control should go back after the function ends)
//
// This process continues until the base case is reached. At that point, 
// no new stack frames are created, and recursion stops expanding.
//
// In the descending phase, function calls start returning one by one. 
// Each time a function finishes execution, its stack frame is popped from the stack. 
// This follows the LIFO (Last In, First Out) policy, meaning the most recent call 
// returns first, then the one before it, and so on.
//
// When the final return occurs, all activation records for the recursive function 
// have been removed, and the stack no longer contains any record of the recursion. 
// Control then resumes from the point where the recursive function was originally called.

#include <stdio.h>

void fun(int x){
    
    printf("Call fun(%d)->pushes frame for fun(%d) to stack.\n",x,x);
    if ( x == 0 ){
        //Base case: prevents the function from infinite calls.
        printf("Base case reached.\n");
    }
    else{
        //Recursive case: function calling itself with smaller input.
        fun(x-1);
    }
     printf("Return fun(%d)->pop frame for fun(%d) from stack.\n",x,x);
}
int main(){
    int x;
    printf("Enter number of calls: ");
    scanf("%d",&x);
    fun(x);
    return 0;
}