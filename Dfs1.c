#include<stdio.h>
#include<stdlib.h>
#define nov 4
#define noe 4
int stack[nov];
int top = -1;
void push(int n) {
    top = top+1;
    stack[top] = n;
}
int pop() {
    int val = stack[top];
    top = top-1;
    return val;
}


void createadjmat(int adjmat[][nov],int edges[][2]) {
    int i;
    int j;
    for(i=0; i<nov; i++) {
        for(j=0; j<nov; j++) {
            adjmat[i][j]=0;
        }
    }
    for(i=0; i<noe; i++) {
        int x = edges[i][0];
        int y = edges[i][1];

        adjmat[x][y]=1;
        adjmat[y][x]=1;
    }
}

void printadjmat(int adjmat[][nov]) {
    int i;
    int j;
    for(i=0; i<nov; i++) {
        for(j=0; j<nov; j++) {
            printf("%d\t",adjmat[i][j]);
        }
        printf("\n");
    }
}
void dfs(int adjmat[][nov],int visited[],int s) {
    int i;
    push(s);
    while(top!=-1)
    {
        int val = pop();
        if(visited[val]==0) {
            printf("%d\n",val);
            visited[val]=1;

        }
        for(i=nov-1; i>=0; i--) {

            if(adjmat[val][i]==1 && visited[i]==0) {
                push(i);
            }

        }

    }
}
int main() {
    int i;
    int edges[noe][2] = {{0,1},{0,2},{1,3},{2,3}};
    int adjmat[nov][nov];
    createadjmat(adjmat,edges);
    printadjmat(adjmat);
    int visited[nov];
    for(i=0; i<nov; i++) {
        visited[i]=0;
    }
    printf("\n After the DFS traversing \n: ");
    dfs(adjmat,visited,0);
    return 0;
}
