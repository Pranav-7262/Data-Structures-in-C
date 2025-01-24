#include<stdlib.h>

void printarray(int *a,int n) //where A = array declared,  n is size of an array..
{
 for(int i=0;i<n;i++)
 {
   printf("%d ",a[i]);
 }
 printf("\n");
}
 void selectionsort(int *a,int n){
// int j;
 int t;

   
 for(int i=0;i<=n-1;i++) //For run till n-1 
 
 {
   for(int j=i+1;j<n;j++) //j is now the last and j is incremented by 1
   {
    // 11 22 33 44 55  
   //   0. 1  2  3. 4
   //If a[i]=11 then j[1]=22 || t=11 
   // then swap a[i] and a[j] and give val of a[j] to t
     if(a[i]<a[j]) { //< ---  descending order sort , > for ascending sort.
      t = a[i];
      a[i]=a[j];   
      a[j]=t;
     
     }
   }

}
}
int main() {
 int a[] ={8,7,5,4,2,91,23,54};
 int n=8;
 printf("\n Given array elements :\n");
 printarray(a,n);
 printf("\n After sorting elements of array : \n");
 selectionsort(a,n);
 printarray(a,n);
  return 0;
}