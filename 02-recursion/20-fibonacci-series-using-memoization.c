
// Title: Fibonacci using Memoization
// Author: Inam Ul Haq
// Description:
// - We use a global array "arr[]" for memoization.
// - Initialize "arr[]" with -1, meaning "not computed yet".
// - Base case:
//     fib(0) = 0, fib(1) = 1
// - Recursive case:
//     fib(n) = fib(n-1) + fib(n-2)
//   But before recomputing, check if value already exists in arr[].
// - This reduces time complexity from O(2^n) (plain recursion) to O(n).


#include <stdio.h>
#define max 1000
int arr[max];
int fib(int n){
    if(n<=1){
        if(arr[n]==-1)
            arr[n]=n;
        return arr[n];
    }
    else{
        if(arr[n-2]==-1)
            arr[n-2]=fib(n-2);
        if(arr[n-1]==-1)
            arr[n-1]=fib(n-1);
            arr[n]=arr[n-2]+arr[n-1];
        return arr[n];
    }
}
int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        arr[i]=-1;
    int result=fib(n);
    printf("fib(%d)= %d",n,result);
    return 0;
}