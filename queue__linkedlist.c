#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *f=NULL;
struct node *r=NULL;
void enque(int val)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("queue id full!\n");
	}
	printf("enqeueuing element %d\n",val);
	ptr->data=val;
	ptr->next=NULL;
	if(f==NULL)
	{
		f=r=ptr;
	}
	else
	{
		r->next=ptr;
		r=ptr;
	}
}
int deque()
{
	int val=-1;
	if(f==NULL)
	{
		printf("queue is empty!\n");
	}
	struct node *ptr=f;
	f=f->next;
	val=ptr->data;
	free(ptr);
	return val;
}
void dis(struct node *ptr)
{
	printf("elements present in queue:\n");
	while(ptr!=NULL)
	{
		printf("element :%d\n",ptr->data);
		ptr=ptr->next;
	}
}
void main()
{
	enque(55);
	enque(23);
	enque(19);
	enque(78);
	enque(51);
	dis(f);
	printf("dequeueing element %d\n",deque());
	printf("dequeueing element %d\n",deque());
	printf("dequeueing element %d\n",deque());
	printf("dequeueing element %d\n",deque());
	
}