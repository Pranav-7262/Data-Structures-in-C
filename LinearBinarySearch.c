#include<stdio.h>
//Code for linear search......

//int linearSearch(int arr[],int size,int element){
// for(int i=0;i<size;i++){
//if(arr[i]==element){
//return i;
//  }
//}
//return -1;
//}
//int main(){
//int SearchIndex;
//int arr[]={1,2,3,4,5};
// int size=5;
//// int element=5;
//int SearchIndex =linearSearch(arr,size,element);
//printf("\n element %d is found at index %d\n",element, SearchIndex);
//  return 0;
//}



//Code For Binary Search ........

int binarySearch(int arr[],int size,int element) {
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high) {
        mid=(low+high)/2;
        if(arr[mid]==element) {
            return mid;
        }
        if(arr[mid]<element) {
           low=mid+1;
        }
        else {
            high=mid-1;
        }

    }
    return -1;

}
int main() {
//int SearchIndex;
    int arr[]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int size=13;
    int element=12;
    int SearchIndex =binarySearch(arr,size,element);
    printf("\n element %d is found at index %d\n",element, SearchIndex);
    return 0;
}