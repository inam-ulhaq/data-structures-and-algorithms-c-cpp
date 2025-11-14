// Title: Indirect Recursion
// Author: Inam Ul Haq 
// Description:
//  An indirect recursive function is a function that does not call itself directly, but
//  calls another function, which eventually calls the original function, forming a recursive cycle.

// Key Points:

//  1 Multiple functions involved: Usually two or more functions call each other.
//  2 Base case required: Must have a stopping condition to prevent infinite recursion.
//  3 Can be linear or tree-like:
//  If each function calls only one other function -> linear indirect recursion.
//  If functions call more than one function -> tree indirect recursion.


#include <stdio.h>

void funB(int);
void funA(int n){
    if(n>0){
        
        funB(n-1);
        printf("%d ",n);
    }
}
void funB(int n){
    if(n>0){
        
        funA(n/2);
        printf("%d ",n);
    }
}
int main(){
    int x=0;
    printf("Enter value for X: ");
    scanf("%d",&x);
    funA(x);
    return 0;
}