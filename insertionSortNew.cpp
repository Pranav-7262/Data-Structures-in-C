#include<stdio.h>
void insertionsort(int arr[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
	   j=i-1;
	   key=arr[i];
	   while(j>=0 && arr[j]>key){
	   	 arr[j+1]=arr[j];
	   	 j--;
	   }
	   arr[j+1]=key;
	}
}
int main(){
	int arr[10],i,n;
	printf("\nEnter size of array:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter element");
		scanf("%d",&arr[i]);

	}

	
		insertionsort(arr,n);
	printf("\n after sorting:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
			
			}
	
	
}
