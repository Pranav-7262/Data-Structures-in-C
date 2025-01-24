#include<stdio.h>
#include<stdlib.h>
#define nov 4
#define noe 4
void createadjmat(int adjmat[][nov],int edges[][2]){
  int i;
  int j;
  for(i=0;i<nov;i++){
    for(j=0;j<nov;j++){
      adjmat[i][j]=0;
    }
  }
  for(i=0;i<noe;i++){
  int x = edges[i][0];
  int y = edges[i][1];
  
  adjmat[x][y]=1;
  adjmat[y][x]=1;
  }
}
void printadjmat(int adjmat[][nov]){
  int i;
  int j;
  for(i=0;i<nov;i++){
   for(j=0;j<nov;j++){
     printf("%d\t",adjmat[i][j]);
   }
   printf("\n");
  }
}
int main(){
 int edges[noe][2] = {{0,1},{0,2},{1,3},{2,3}};
 int adjmat[nov][nov];
 createadjmat(adjmat,edges);
 printadjmat(adjmat);
  return 0;
}