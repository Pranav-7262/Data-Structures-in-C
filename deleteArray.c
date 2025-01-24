#include<stdio.h>
#include<conio.h>
main()
{
int a[10],i,size,pos;
printf("\n enter the size of array:");
scanf("%d",&size);

for(i=0;i<size;i++)
{
printf("\n Enter a value= %d",i);
scanf("%d\n",&a[i]);

}
printf("\n arry before deletion\n");
for(i=0;i<size;i++)
{
printf("\t %d",a[i]);
}
printf("\n enter index of element which you want to delete:");
scanf("%d\n",&pos);
for(i=pos;i<size;i++)
{
a[i]=a[i+1];

}
printf("\n arry after deletion \n ");
for(i=0;i<size-1;i++)
{
 printf("%d\n",a[i]);
}
}
