#include<stdio.h>
#include<conio.h>

//int sum(int n){

//if(n==1){
//return 1;
//}
//else{
//return n+sum(n-1);
//}
//}
//int main(){
//int n=5,r;
//r = sum(n);
//printf("%d\n",r);
//return 0;
//}

int fact(int n){
if(n==1)
 {
  return 1;
   }
   else{
    return n*fact(n-1);
   }
   }
int main(){
 int n = 5,r;
 r = fact(n);
 printf("%d\n",r);
 return 0;
 
}