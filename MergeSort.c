#include<stdio.h>
void printarray(int a[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i,k,j,b[20];
    i=low;//1st subarray initial pos
    k=low;//sorted original array initial pos
    j=mid+1;//2nd subarry initial pos
    int s;
    while(i<=mid && j<=high)//Check for 1st subarray 
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];//just print in the b[]array 
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)//For condition , one of subarray is not complete 
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(s=low; s<=high; s++)//It coppies elements and shift to original array..
    {
        a[s]=b[s];
    }
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);//recursive call
    }
}
int main()
{
    int i,n,a[10];
    printf("enter the array size:\n");
    scanf("%d",&n);
    printf("enter the array elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("array elements before the merge sort:\n");
    printarray(a,n);
    printf("\narray elements after the merge sort\n");
    mergesort(a,0,n-1);
    printarray(a,n);
    return 0;
}