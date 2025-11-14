// Title: Head Recursion
// Author: Inam Ul Haq 
//
// Discription:
// A function calling itself and the recrsive call is his first statment
// and what all the processing it has to do is doing after the recursive
// call then the function is said to be head recursive.
// mean there is no operation before the recursive call.
// If a function perform all it's work in decending phase and did nothing 
// during acending phase then the function is consider is head recursive 
// function.
//
// looking to head recursive functions and convrting it into loops is not
// esay.

#include <stdio.h>

void headFun(int x){
    if(x>0){
        headFun(x-1);
        printf("%d ",x);
    }
}
int main(){
    int x;
    printf("Enter value for function calls: ");
    scanf("%d",&x);
    headFun(x);
    return 0;
}