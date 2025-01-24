#include<stdio.h>
int main(){
	int arr[100],i,num,start,end,mid,size,flag=0;
	printf("\nEnter the array size");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nenter a number ");
		scanf("%d",&arr[i]);
		}
		printf("enter num to search");
		scanf("%d",&num);
		start=0;
		end=size-1;
	while(start<=end){
		mid=(start+end)/2;
	
		if(arr[mid]==num){
			printf("\nNum is present at %dth location",mid+1);
			flag=1;
			break;
		}
		else if(num<arr[mid]){
			end=mid-1;
			
		}
		else{
			start=mid+1;
		}
		
	}
	if(flag==0){
		printf("\nNum is not present");
	}
	}

	


