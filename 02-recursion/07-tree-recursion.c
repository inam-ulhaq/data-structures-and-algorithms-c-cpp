//  Title: Tree Recursion
//  Author: Inam Ul Haq 
//  Description:
//   if a recursive function calling itself more than once within the body
//  (more than one recursive statment in the function body) then the function
//   is said to be tree recursive function.

//  Key Characteristics

//   1 More than one recursive call in each function execution.
//   2 The number of calls grows rapidly (often exponentially).
//   3 Uses a lot of memory and stack frames.
//   4 Often appears in problems like Fibonacci, permutations, combinations,
//   divide-and-conquer algorithms.

#include <stdio.h>

void treeRecFun(int x){
    if(x>0){
        printf("%d ",x);
        treeRecFun(x-1);
        treeRecFun(x-1);
    }
}
int main(){
    int x;
    printf("Enter the value for X: ");
    scanf("%d",&x);
    treeRecFun(x);
    return 0;
}