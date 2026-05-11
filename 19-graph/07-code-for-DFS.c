#include <stdio.h>
#define SIZE 8

void DFS(int A[][8],int start,int n){
	static int visited[8]={0};
	
	if(visited[start]==0){
		printf("%d ,",start);
		visited[start]=1;
		for(int i=1;i<=n;i++){
			if(A[start][i]==1 && visited[i]==0){
				DFS(A,i,n);
			}
		}
		
	}
}




int main(){
	int A[8][8]={
				   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
                   
    int start=1;
    DFS(A,start,SIZE);
        

}