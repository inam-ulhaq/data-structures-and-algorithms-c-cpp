//  Titile: Single Linear Recursion
//  Author: Inam Ul Haq 
//  Description: 
//   Single linear recursion is a type of recursion where a function makes 
//   exactly one recursive call during its execution of each step, and this
//   call occurs in a straight chain (not branching).

//  Key Points

//   Linear-> Only one path of recursion (like a straight line, not a tree).

//   Single-> Exactly one recursive call per function execution.

//   The recursive call can appear:

//   at the beginning (head recursion)

//   at the end (tail recursion)

//   in the middle of an expression (non-head, non-tail, like factorial).

//  example of single linear recursion is given below



#include <stdio.h>

int factorial(int x){
    if(x>0){
        return x*factorial(x-1);
    }
    return 1;
}

int main(){
    int x;
    printf("Enter value for X: ");
    scanf("%d",&x);
    printf("%d! = %d ",x,factorial(x));
    return 0;
}