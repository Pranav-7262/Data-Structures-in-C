#include<stdlib.h>

void printarray(int *A,int n) //where A = array declared,  n is size of an array..
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
 int A[]={11,43,25,31,97,62,78,31,9,88};
 int n=10;
 printf("\n Given array elements :\n");
 printarray(A,n);
 printf("\n After sorting elements of array : \n");
 Insertionsort(A,n);
 printarray(A,n);
  return 0;
}