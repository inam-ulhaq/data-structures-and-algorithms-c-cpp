// Title: selection fromula 
// Author: Inam Ul Haq
// Description:
//  Purpose : Computes nCr (the number of ways to choose r objects from n objects)
//            using Pascal's Rule (recursive definition).
//
//  Formula :
//     nCr = (n-1)C(r-1) + (n-1)Cr
//     Base cases:
//         - nC0 = 1  (choosing 0 objects from n always has exactly 1 way: choose nothing)
//         - nCn = 1  (choosing all n objects has exactly 1 way: take all of them)
//
//  Parameters:
//     n - total number of objects
//     r - number of objects to choose
//
//  Returns:
//     Integer value of nCr

#include <stdio.h>

int c(int n,int r) {
    // Base case: if r == 0 or r == n, return 1
    // Because:
    //   - If r == 0 → only one subset possible (the empty set)
    //   - If r == n → only one subset possible (the entire set)
    if(r==0||r==n){
        return 1;
    }
    else{
        // Recursive case: apply Pascal's Rule
        // Break the problem into two smaller problems:
        //   1. Include the current element → compute (n-1, r-1)
        //   2. Exclude the current element → compute (n-1, r)
        // Add them together to get total combinations
        return c(n-1,r-1)+c(n-1,r);
    }
}

int main(){
    int n,r;

    // Ask user for input values n and r
    printf("Enter values for n and r (n r): ");
    scanf("%d %d",&n,&r);
    // Call recursive function to compute nCr
    int result = c(n, r);

    // Display result
    // Example: n=5, r=2 → Output = 10
    printf("The number of possible subsets of size %d from %d objects is %d",r,n,result);

    return 0;
}
