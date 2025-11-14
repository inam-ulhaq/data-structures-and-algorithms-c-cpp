// Title: Sum of N Natural Numbers Using Recursion
// Author: Inam Ul Haq 
// Description:
// if we want to sum first 5 natural numbers then we can do it like this:
// 1 + 2 + 3 + 4 + 5
// in samillar way the sum of frist n natural numbers is 
// 1 + 2 + 3 + ... + n

// now define recurance relaation for this is:
// sum(n) = 1 + 2 + 3 ....+ (n-1) + n
// sum(n) = sum(n-1) + n

// so the recursive formula become
// sum(n) = 0              ,n==0
// sum(n) = sum(n-1) + n   ,n>0

// now if we convert this to code it will look like:

#include <stdio.h>

int sum(int n){
    if(n > 0){
        return sum(n - 1)+n;
    }else{
        return 0;
    }
}
int main(){
    int n;
    printf("Enter the value of (n): ");
    scanf("%d",&n);
    int total=sum(n);
    printf("Sum of %d natural numbers: %d",n,total);
    return 0;
}

// Time complexity 
// lets
// "fun(n)" taking time of T(n)
//
// then form the recurance relation 
//
// case 1: n==0
//    T(n) = 0
//
// case 2: n>1
//    T(n) = T(n-1) + 1
//
// expanding
//    T(n) = T(n-1) + 1
//    T(n) = T(n-2) + 2
//    T(n) = T(n-3) + 3
//    ...
//    T(n) = T(n-k) + k 
// assume that k-n=0
//    then k=n 
// so,
//    T(n) = T(n-n) + n 
//    T(n) = T(0) + n 
//    T(n) = 1 + n 
//    T(n) = O(n)
