#include<stdlib.h>

void printarray(int *A,int n)
{
 for(int i=0;i<n;i++)
 {
   printf("%d ",A[i]);
 }
 printf("\n");
}
 void bubblesort(int *A,int n)
{
  int temp;
 for(int i=0;i<n-1;i++) //For no.of passes(n-1)
 {
  for(int j=0;j<n-1-i;j++){ //For the comparisons... n-1-i
   if(A[j]>A[j+1])
   {
    temp=A[j];
    A[j]=A[j+1];
    temp=A[j+1];  
   }
  
  } 
 } 


}
int main() {
 int A[]={11,23,45,68,56,81};
 int n=6;
 printarray(A,n);
 return 0;
}