//Title: Tail-Recursion-VS-Loops
//Author: Inam-Ul-Haq
//Example

#include <stdio.h>

// recursive function
void recFun(int n){
    if(n > 0){
        recFun(n - 1);
    }
}

// iterative function
void itrFun(int n){
    while(n > 0){
        n--;
    }
}

int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d", &n);

    recFun(n);
    itrFun(n);

    return 0;
}

/*
 Explanation

We will compare both functions in terms of 
time complexity and space complexity.

----------------------------------------------------
1) Time Complexity of recFun(n)
----------------------------------------------------
Let T(n) = time taken by recFun(n).

Case 1: n > 0
   - The "if(n > 0)" check takes 1 unit of time.
   - Then it calls recFun(n-1), which takes T(n-1).
   => T(n) = T(n-1) + 1

Case 2: n = 0
   - Only "if(n > 0)" check runs, takes 1 unit of time.
   => T(0) = 1

Expanding:
   T(n) = T(n-1) + 1
   T(n) = T(n-2) + 2
   T(n) = T(n-3) + 3
   ...
   T(n)=T(n-k)+k
        lets
            n-k=0
            n=k 
  so
   T(n)=T(n-n)+n
   T(n) = T(0) + n
   T(n) = 1 + n

So, Time Complexity = O(n)

----------------------------------------------------
2) Time Complexity of itrFun(n)
----------------------------------------------------
The while loop executes n times.
Each iteration:
   - checks condition (n > 0)
   - decrements n

Additionally, one last check happens when n = 0.
So total = n + 1 checks = linear work.

Time Complexity = O(n)

3) Space Complexity

For recFun(n):
   - Each recursive call uses a new stack frame.
   - Total calls = n+1 (from n down to 0).
   - Space Complexity = O(n)

For itrFun(n):
   - Only one variable 'n' is updated in the loop.
   - No extra stack frames are created.
   - Space Complexity = O(1)

Final Conclusion

- Both recursion and loops have the same time complexity O(n).
- But recursion uses O(n) space (stack frames),
  while loops use O(1) space.
- Therefore, loops are more space-efficient.

*/
