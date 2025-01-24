#include<stdio.h>
int main(){
	int arr[100],i,pos,size;
	printf("\nEnter the array size");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nenter a number");
		scanf("%d",&arr[i]);
		
	}
	printf("\nArray before deletion");
	for(i=0;i<size;i++){
		printf("\t %d",arr[i]);
	}


	printf("\nEnter index to delete");
	scanf("%d",&pos);
		for(i=pos;i<size-1;i++){
		arr[i]=arr[i+1];
	}
	printf("\nArray after inserting");
	for(i=0;i<size-1;i++){
		printf("\t %d",arr[i]);
	}
}	

