#include<stdlib.h>

void printarray(int *A,int n)
{
 for(int i=0;i<n;i++)
 {
   printf("%d ",A[i]);
 }
 printf("\n");
}
 void Insertionsort(int *A,int n){
 int key;
 int j;

   
 for(int i=0;i<=n-1;i++) //For no.of passes(n-1)
 {
   key=A[i];
   j=i-1;
   
   while(j>=0 && A[j]>key){ //using < == descending order
                             // > ==  ascending order insertion. 
   A[j+1]=A[j];                
   j--;
   
   } 
   A[j+1]=key;
 }
 

}
int main() {
 int A[]={11,43,21,57,211,3};
 int n=6;
 printarray(A,n);
 
 Insertionsort(A,n);
 printarray(A,n);
  return 0;
}