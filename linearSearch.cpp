#include<stdio.h>
int main(){
	int arr[100],i,num,pos,size,flag=0;
	printf("\nEnter the array size");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nenter a number ");
		scanf("%d",&arr[i]);
		
	}
	printf("\nEnter num to search");
	scanf("%d",&num);
	for(i=0;i<size;i++){
		if(arr[i]==num){
			printf("num is present at %dth position ",i+1);
			flag=1;
			
		}
	}
		if(flag==0){
			printf("\nNum is not present");
		}
	}

	


