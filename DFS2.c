#include<stdio.h>
#include<stdlib.h>

int visited[4]= {0,0,0,0};
int A[4][4] = {{0,1,1,0},
                {1,0,0,1},
                {1,0,0,1},
                {0,1,1,0}
              };
void dfs(int i) {
    int j;
    printf(" \n%d  ",i);
    visited[i]=1;
    
    for(j=0;j<4;j++){
     if(A[i][j]==1 && !visited[j]) {
        dfs(j);
     } 
}  
}

int main()

{

    dfs(3);
    return 0;
}