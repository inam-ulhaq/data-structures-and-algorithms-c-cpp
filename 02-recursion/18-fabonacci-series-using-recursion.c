// Title: Fibonacci Number Using Recursion
// Author: Inam Ul Haq
// Description:
// The Fibonacci sequence is defined as:
//   F(0) = 0
//   F(1) = 1
//   F(n) = F(n-1) + F(n-2), for n > 1
//
// Example:
//   If n = 6
//   Then the series will be: 0, 1, 1, 2, 3, 5, 8
//   And F(6) = 8
//
// Now define the recurrence relation for this:
//
//   F(n) = F(n-1) + F(n-2)
//
// With base cases:
//   F(0) = 0
//   F(1) = 1
//
// So the recursive formula becomes:
//   F(n) = 0                  , n == 0
//   F(n) = 1                  , n == 1
//   F(n) = F(n-1) + F(n-2)    , n > 1
//
// Now if we convert this into code, it will look like:

#include <stdio.h>

int fib(int n){
    if(n == 0){
        return 0; // base case
    }else if(n == 1){
        return 1; // base case
    }else{
        return fib(n-1) + fib(n-2); // recursive step
    }
}

int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d", &n);
    printf("Fibonacci number F(%d) = %d", n, fib(n));
    return 0;
}

// ---------------- Time Complexity ----------------
//
// Let T(n) = time taken by fib(n)
//
// Case 1: n == 0 or n == 1
//   T(n) = O(1)
//
// Case 2: n > 1
//   T(n) = T(n-1) + T(n-2) + O(1)
//
// Expanding this recurrence:
//   T(n) = T(n-1) + T(n-2)
//   T(n-1) = T(n-2) + T(n-3)
//   T(n-2) = T(n-3) + T(n-4)
//   ...
// This expansion grows almost like the Fibonacci numbers themselves.
//
// So the total number of calls ≈ 2^n
//
// Therefore:
//   Time Complexity = O(2^n)  (exponential)
//   Space Complexity = O(n)   (recursion stack depth)
