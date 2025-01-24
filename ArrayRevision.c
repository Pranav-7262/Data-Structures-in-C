#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int *arr,int pos,int num){
int i;
for(i=MAX-1;i>=pos;i--)
{
 arr[i+1] = arr[i];
}
arr[pos]=num;
}
void del(int *arr,int pos){
 int i;
 for(i=pos;i<MAX-1;i++){
   //arr[i-1] = arr[i];
  // arr[i-1] = 0;
  arr[i] = arr[i+1];
 }
}
void reverse(int *arr){
 int i;
 for(i=0;i< MAX/2;i++)
 {
   int temp = arr[i];
   arr[i] = arr[MAX-1-i];
   arr[MAX-1-i] = temp;
 }
}
void search(int *arr,int num){
 int i;
 for(i=0;i<MAX;i++){
 if(arr[i]==num){
   printf("\n num %d is found at %dth position",num,i);
   return;
 }
 if(i==MAX)
{
 printf("\n num %d is not found at in array",num);
 
} }
}
void display(int *arr){
  int i;
  printf("\n");
  for(i=0;i<MAX;i++)
  {
    printf("%d\t",arr[i]);  
  
  }
}

int main()
{
 int arr[5];
 insert(arr,0,11);
 insert(arr,1,22);
 insert(arr,2,33);
 insert(arr,3,44);
 insert(arr,4,55);
 printf("\n numbers are:");
 display(arr);
  //del(arr,3);
 // del(arr,2);
 reverse(arr);
 
  printf("\n After reverse");
  display(arr);
  
  
  search(arr,22);
 
}