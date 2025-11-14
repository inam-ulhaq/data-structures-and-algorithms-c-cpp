// Title: Horner’s Rule
// Author: Inam Ul Haq
// Taylor series expansion of e^x up to n terms:

//     e^x(n) = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!

// Expanding factorials:

//     e^x(n) = 1 + x/1 + x^2/(1*2) + x^3/(1*2*3) + ... + x^n/(1*2*3*...*n)

// Now take common factors step by step:

// 1) Take (x/1) common:
//     e^x(n) = 1 + (x/1) [ 1 + x/2 + x^2/(2*3) + ... + x^(n-1)/(2*3*...*n) ]

// 2) Inside the brackets, take (x/2) common:
//     e^x(n) = 1 + (x/1) [ 1 + (x/2) ( 1 + x/3 + x^2/(3*4) + ... + x^(n-2)/(3*4*...*n) ) ]

// 3) Again, take (x/3) common:
//     e^x(n) = 1 + (x/1) [ 1 + (x/2) [ 1 + (x/3) ( 1 + x/4 + ... ) ] ]

// Continue this process...

// Final nested form (Horner’s Rule):

//     e^x(n) = 1 + (x/1) ( 1 + (x/2) ( 1 + (x/3) ( 1 + (x/4) (... (1 + x/n) ... ))) )
// 

// using recursion
#include <stdio.h>

double e(int x,int n){
    static double result=1;
    if(n>0){
        result= 1 + (x/(double)n)*result;
        e(x,n-1);
    }else{
        return result;
    }
}

// using iteration
double itrE(int x,int n){
    double sum=1;
    while(n>0){
        sum = 1 + (x/(double)n) * sum;
        n--;
    }
    return sum;
}

int main(){
    int x;
    int n;
    printf("Enter (x and n) values: ");
    scanf("%d %d",&x,&n);

    printf("The Taylor series using recursion for %d of %d terms is: %.6f\n", x, n, e(x,n));
    printf("The Taylor series using iteration for %d of %d terms is: %.6f\n", x, n, itrE(x,n));

    return 0;
}
