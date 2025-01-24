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
	int pivot=a[low];
	int i=low+1;
	int j=high;
	int temp;
	do
	{
		while(a[i]<=pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int low,int high)
{
	int part;
	if(low<high)
	{
	part=partition(a,low,high);
	quicksort(a,low,part-1);
	quicksort(a,part+1,high);
	}
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
	quicksort(a,0,n-1);
	printf("\narray elements after the quick sort:\n");
	printarray(a,n);
	return 0;
}