
// Title: Fibonacci Series using Recursion with Static Variables
// Author: Inam Ul Haq
// Description: 
// Prints the Fibonacci series up to n terms using recursion.
// Example (n=7): 0, 1, 1, 2, 3, 5, 8


#include <stdio.h>

void fib(int n){
    static int first=0, second=1;
    if(n == 0){
        printf("%d",first);
    }else{
        fib(n-1);
        int temp =second;
        second +=first;
        first =temp;
        printf(", %d",second);
    }
}

int main(){
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    if(n<=0) {
        printf("Please enter a positive integer.");
    }else{
        fib(n-1);
    }
    return 0;
}
