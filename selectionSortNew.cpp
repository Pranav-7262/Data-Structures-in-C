#include<stdio.h>
void selectionsort(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
	 int min_index=i;
	 for(j=i+1;j<n;j++){
	 	if(arr[j]<arr[min_index]){
	 		min_index=j;
		 }
	 }
	 if(min_index!=i){
	 	temp=arr[i];
	 	arr[i]=arr[min_index];
	 	arr[min_index]=temp;
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

	
		selectionsort(arr,n);
	printf("\n after sorting:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
			
			}
	
	
}
