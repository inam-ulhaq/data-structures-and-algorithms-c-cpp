// Title: Tower of Hanoi using recursion
// Author: Inam Ul Haq
// Description:
//     The problem is to move 'n' disks from source rod to destination rod 
//     using an auxiliary rod, following these rules:
//     1. Only one disk can be moved at a time.
//     2. A disk can only be placed on top of a larger disk or on an empty rod.
//     3. All disks start on the source rod in decreasing size order.
//     The goal is to move all disks to the destination rod using recursion.
//
// Function ToH to perform Tower of Hanoi
// n: number of disks
// a: source rod
// b: auxiliary rod
// c: destination rod
#include <stdio.h>
void ToH(int n,int a,int b,int c){
    if(n>0){
        ToH(n-1,a,c,b);
        printf("(%d to %d)\n",a,c);
        ToH(n-1,b,a,c);
    }
}
int main(){
    int n;
    printf("Enter no of disks: ");
    scanf("%d",&n);
    ToH(n,1,2,3);
    return 0;
}