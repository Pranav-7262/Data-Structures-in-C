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
	if((q->r+1)%q->size==q->f)
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
		printf("queue overflow!\n");
	}
	q->r=(q->r+1)%q->size;
	q->arr[q->r]=val;
	printf("enqueued element is %d\n",val);
}
int deque(struct que *q)
{
	int val;
	if(empty(q))
	{
		printf("queue underflow!\n");
		return -1;
	}
	q->f=(q->f+1)%q->size;
	val=q->arr[q->f];
	return val;
}
void main()
{
	struct que *q=(struct que*)malloc(sizeof(struct que));
	q->size=5;
	q->f=q->r=0;
	q->arr=(int*)malloc(q->size*sizeof(int));
	printf("queue is full before the enqueue:%d\n",full(q));
	printf("queue is empty before the enqueue:%d\n",empty(q));
	enque(q,55);
	enque(q,23);
	enque(q,67);
	enque(q,34);
	printf("queue is full after the enqueue:%d\n",full(q));
	printf("queue is empty after the enqueue:%d\n",empty(q));
	printf("dequeued element is %d\n",deque(q));
	printf("dequeued element is %d\n",deque(q));
	printf("dequeued element is %d\n",deque(q));
	printf("dequeued element is %d\n",deque(q));
	printf("queue is full after the denqueue:%d\n",full(q));
	printf("queue is empty after the denqueue:%d\n",empty(q));
}