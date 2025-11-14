//Title: Time Complexity of Tree Recursion
//Author: Inam Ul Haq
//Example: Anlysing the time complexity of tree recursion

#include <stdio.h>

void treeRecFun(int n){     //T(n)
    if(n>0){                //single unite of time for the current call
        treeRecFun(n-1);    //T(n-1)
        treeRecFun(n-1);    //T(n-1)
    }
}
int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d",&n);
    treeRecFun(n);
    return 0;
}

/*Time complexity

case 1: n>0
    -The check "if(n>0)" take 1 unite of time.
    -then it call treeRecFun(n-1) which take T(n-1)
    -and again the treeRecFun(n-1) is calling which take T(n-1)
    =>T(n)=T(n-1)+T(n-1)+1

case 2: n==0
    -The only check "if(n>0)" statment is exicuted and take 1 unite of time 
    =>T(0)=1

Expending 
    T(n)= T(n-1) + T(n-1) + 1
    T(n)= 2.T(n-1) + 1
    T(n)= 2 ( 2T(n-1) + 1 ) + 1
    T(n)= 4T(n-2) + 2 + 1
    T(n)= 4( 2T(n-3) + 1 ) + 2 + 1
    T(n)= 8T(n-3) + 4 + 2 + 1
    T(n)= 2^3 T(n-3) + 2^(3-1) + 2^(3-2) + 2^(3-3)
    ......
    T(n)=2^k T(n-k) +2^(k-1) + 2^(K-2) + 2^(k-3) + 2 + 1
        let n-k=0
        n=k 
    T(n)= 2^n T(n-n) + 2^n-1 + 2^n-2 +...+ 2^n-n 
    T(n)= 2^n T(0) + 2^n -1
    T(n)= 2^n (1) + 2^n -1
    T(n)= 2^n + 2^n -1
    T(n)= 2^n . 2 -1
    T(n)= O(2^n)
    */



