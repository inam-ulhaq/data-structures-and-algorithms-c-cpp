/*Title: Introduction to Recursive Function
Author: Inam Ul Haq
Description:
A recursive function is a function that calls itself to solve a specific problem. It divides a big problem into smaller sub-problems and solves them using the same function. It stops when the condition in the base case becomes true.

Structure of a recursive function:
A recursive function has two cases:

Base case: This part of the function contains a condition that stops the recursion and prevents infinite calls.

Recursive case: This part of the function contains the recursive call, where the function calls itself with a smaller or simpler input.

Phases of a recursive function:

Calling phase: This phase starts from the beginning of the function and continues until the base case is reached.

Returning phase: This phase starts when all the function calls have ended, and the control returns to the previous calls one by one until the original call ends.
*/
#include <stdio.h>

void fun(int x){
    if(x==0){
        //Base case: stop recursion.
        return;
    }else{
        //Recursive case: function call itself with smaller input.
        printf("Value passing to next function is %d.\n",x);
        fun(x - 1);
    }
}

int main(){
    int x=5;
    fun(x);
    return 0;
}