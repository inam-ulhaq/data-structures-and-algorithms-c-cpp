// Title: Taylor Series for e^x Using Recursion
// Author: Inam Ul Haq
// Description:
//
// The Taylor series expansion for the exponential function e^x is:
//
//     e^x = 1 + (x / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)
//
// Where:
//   - n is the number of terms we consider in the expansion
//   - More terms (larger n) give a more accurate approximation of e^x
//
// Recursive Approach:
// 
// We want to compute the series term by term, using recursion.
// Notice that each term depends on the previous term's power of x and factorial.
//
// Example for x = 2, n = 3:
//   e^2 ≈ 1 + 2/1! + 2^2/2! + 2^3/3!
//       = 1 + 2 + 2 + 1.333...
//       = 6.333...
//
// Implementation Details:
//
// We define a recursive function e(x, n) that computes the value of e^x
// up to n terms.
//
// - Base case:
//     If n == 0 → return 1 (because e^x starts with the constant term 1).
//
// - Recursive case:
//     Call e(x, n-1) to compute the partial sum up to (n-1) terms.
//     Then compute the nth term using:
//         power = power * x
//         factorial = factorial * n
//     and add (power / factorial) to the result.
//
// We use static variables inside the recursive function:
//     static double p = 1 → stores powers of x (x^n)
//     static double f = 1 → stores factorials (n!)
//
// These static variables retain their values across recursive calls,
// so we don’t need to recompute powers and factorials from scratch each time.
//
//
// Limitations:
// 
// - Since we are using recursion, very large n may cause stack overflow.
// - We use double for precision. Using int would lose fractional accuracy.
// - The more terms (n), the closer the approximation to the true value of e^x.

#include <stdio.h>

double e(int x, int n) {
    static double p = 1, f = 1;  // p = x^n, f = n!
    if (n == 0) {
        return 1;
    } else {
        double r = e(x, n - 1);  // recursive call for previous terms
        p *= x;                  // update power of x
        f *= n;                  // update factorial
        return r + p / f;        // add nth term
    }
}

int main() {
    int x, n;
    printf("Enter value for x: ");
    scanf("%d", &x);
    printf("Enter number of terms n: ");
    scanf("%d", &n);

    double result = e(x, n);
    printf("Approximation of e^%d using %d terms = %.10f\n", x, n, result);

    return 0;
}
