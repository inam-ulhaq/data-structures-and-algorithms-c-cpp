// Title: Power of a Number Using Recursion
// Author: Inam Ul Haq
// Description:
// The power of a number m raised to n (written as m^n) is defined as the 
// product of multiplying m by itself n times.
//
// Example:
//     5^3 = 5 * 5 * 5 = 125
//
// In general:
//     m^n = m * m * m * ... * m   (n times)
//
// Recursive definition:
//     m^0 = 1          , if n == 0
//     m^n = m * m^(n-1), if n > 0
//
// This recursive formula can be directly implemented in code.

#include <stdio.h>

int power(int m,int n){
    if(n==0){
        return 1;
    }else{
        return m * power(m,n-1);
    }
} 
int main(){
    
    printf("To find power of number m raised to the power n (m^n)\n");
    int n,m;

    printf("Enter value of m: ");
    scanf("%d",&m);
    printf("Enter value for n: ");
    scanf("%d",&n);

    int result = power(m,n);
    printf("Power of %d^%d is %d",m,n,result);

    return 0;

}
