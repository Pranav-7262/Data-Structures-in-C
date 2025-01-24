#include<stdio.h>
int main(){
	int arr[100],i,n,pos,size;
	printf("\nEnter the array size");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nenter a number");
		scanf("%d",&arr[i]);
		
	}
	printf("\nArray before insert");
	for(i=0;i<size;i++){
		printf("\t %d",arr[i]);
	}
	printf("\nEnter a index to insert");
	scanf("%d",&pos);
	for(i=size-1;i>=1;i--){
		arr[i+1]=arr[i];
	}
	printf("Enter num to insert");
	scanf("%d",&n);
	arr[pos]=n;
	printf("\nArray after inserting");
	for(i=0;i<=size;i++){
		printf("\t %d",arr[i]);
	}
}	

