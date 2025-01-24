#include<stdio.h>
void bubblesort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
			 temp=arr[j];
			 arr[j]=arr[j+1];
			 arr[j+1]=temp;	
			}
		}
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

	
		bubblesort(arr,n);
	printf("\n after sorting:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
			
			}
	
	
}
