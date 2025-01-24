#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printarray(int *a,int n) //where A = array declared,  n is size of an array..
{
 for(int i=0;i<n;i++)
 {
   printf("%d ",a[i]);
 }
 printf("\n");
}
 int maximum(int a[],int n){//This function only for a declaring a maximum function.
 int max = INT_MIN;
 for(int i=0;i<n;i++)
{
   if(max < a[i]) {
   max=a[i];
   }
}
return max; 
 }

 void countsort(int *a,int n){
 int i;
 int j;
 //Finding a maximum element in array. a 
 int max = maximum(a,n);
 //Create a count array..
 int *count = (int *)malloc((max+1)*sizeof(int));
 //Initialize array element to 0..
 for(i=0;i<max+1;i++){
 count[i]=0;
 }
 //Increment rhr corresponding index in the count array..
 for(i=0;i<n;i++){
   count[a[i]] = count[a[i]]+1;
   
 }
 //Following code is only about to count array i.e Set count[i]>0 then a[j]=i
 i=0;
 j=0;
  while(i<=max){
   if(count[i]>0){
   a[j] = i;
   count[i] = count[i]-1;
   j++;
   }
   else{
      i++;
   }
  }
 
  }

int main() {
 int a[] ={8,7,5,4,2,33,45,21,76,93,15};
 int n=11;
 printf("\n Given array elements :\n");
 printarray(a,n);
 printf("\n After sorting elements of array : \n");
 countsort(a,n);
 printarray(a,n);
  return 0;
}