#include<stdio.h>
#include<conio.h>
main()
{
  int a[100],i,pos,n,size;
  clrscr();
  printf("Enter the array size:");
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
    printf("\n Enter the no.");
    scanf("%d",&a[i]);
  }
  printf("\n Array before Inserting:");
  for(i=0;i<size;i++)
  {
    printf("\t %d",a[i]);
  }
  printf("\n Enter the index number where you want to insert the no.");
  scanf("%d",&pos);
  for(i=size-1;i>=pos;i--)
  {
    a[i+1]=a[i];
  }
  printf("\n Enter the no which you want to insert");
  scanf("%d",&n);
  a[pos]=n;
  printf("\n Array after inserting");
  for(i=0;i<=size;i++)
  {
    printf("\t %d",a[i]);
  }
  getch();
}
