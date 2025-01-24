#include<stdio.h>
int stack[100];
int top=-1;
int factorail(int num){
	stack[++top]=num;
	int result=1;
	while(top>=0){
		int n=stack[top--];
		if(n==1 || n==0){
			result=result*1;
		}
		else{
			result=result*n;
			stack[++top]=n-1;
		}
	}
	return result;
}
int main(){
	int num;
	printf("Enter the Number to Calculate Factorail:\n");
	scanf("%d",&num);
	
	printf("The Factorail of %d is %d\n",num,factorail(num));
	return 0;
}
