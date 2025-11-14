// Titile: solution for fibonacci-series-using-iteration
// Author: Inam Ul Haq
// Example: 

#include <stdio.h>
int fib(int n){
    int istTerm=0,secTerm=1,result=0;
    for(int i=2;i<=n;i++){
        result=istTerm+secTerm;
        istTerm=secTerm;
        secTerm=result;
    }
    return result;
}
int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d",&n);
    int result=fib(n);
    printf("fib(n)= %d",result);
    return 0;
}