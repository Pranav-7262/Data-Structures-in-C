#include<stdio.h>
#include<stdlib.h>
struct que
{
	int f;
	int r;
	int size;
	int *arr;
};
int full(struct que *q)
{
	if(q->r==q->size-1)
	{
		return 1;
	}
	return 0;	
}
int empty(struct que *q)
{
	if(q->r==q->f)
	{
		return 1;
	}
	return 0;
}
void enque(struct que *q,int val)
{
	if(full(q))
	{
		printf("queue is full!\n");
	}
	q->r++;
	q->arr[q->r]=val;
}
int deque(struct que *q)
{
	int val;
	if(empty(q))
	{
		printf("quqe is empty!\n");
	}
	q->f++;
	val=q->arr[q->f];
	return val;
}
void main()
{
	struct que *q=(struct que *)malloc(sizeof(struct que));
	q->r=q->f=0;
	q->size=100;
	q->arr=(int*)malloc(q->size*sizeof(int));
	int un_vis[7]={0,0,0,0,0,0,0};
	int i=0 ,j;
	int a[7][7]={
		{0,1,1,1,0,0,0},
		{1,0,1,0,0,0,0},
		{1,1,0,1,1,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0},
	};
	printf("%d\n",i);
	un_vis[i]=2;
	enque(q,i);
	while(!empty(q))
	{
		int node=deque(q);
		for(j=0;j<7;j++)
		{
			if(a[node][j]==1&&un_vis[j]==0)
			{
				printf("%d\n",j);
				un_vis[j]=1;
				enque(q,j);
			}
		}
	}
}