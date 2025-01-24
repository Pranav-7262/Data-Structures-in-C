#include<stdio.h>
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int partition(int a[],int low,int high)
{  
  if(low>=high){
    return 1;
   }
	
	int i=low;
	int j=high;
    int mid = i +(j-i)/2;
    int pivot=a[mid];
	int temp;
    while(i<=j)
	{
		while(a[i]<pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<=j)
        
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
            i++;
            j--;
		}
	}
    partition(a,low,j);//recusive call low->>j
    partition(a,i,high);//recursive call i->>high
}
int main()
{
	int i,n,a[20];
	printf("enter the size of array:\n");
	scanf("%d",&n);
	printf("enter the array elements :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array elements before the quick sort:\n");
	printarray(a,n);
	partition(a,0,n-1);
	printf("\narray elements after the quick sort:\n");
	printarray(a,n);
	return 0;
}