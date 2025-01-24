#include<stdio.h>
#include<stdlib.h>
struct pair {
    int key;
    int value;
};
void display(struct pair ht[],int n)

{
	int i;
    printf("\nkey\tvalue\n");
    for( i=0; i<n; i++) {
        printf("%d\t%d\n",ht[i].key,ht[i].value);
    }
}
int main() {

    int i;
    int num;
    int n=10;
    //printf("\nEnter hash table size :\n");
   // scanf("%d",&n);
   struct pair ht[n];
    int arr[] = {11,22,33,44,55,66,77,88,99,100};
    for(i=0; i<n; i++) {
        ht[arr[i]%10].key = arr[i]%10;
        ht[arr[i]%10].value = arr[i];
    }

    display(ht,n);
    printf("\nEnter num for search:\n");
    
    scanf("%d",&num);
    printf("\nElement at %dth position",ht[num%10].key);
    
    return 0;
}
