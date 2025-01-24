#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int r;
	int f;
	int size;
	int *a;
};

int s=0;

typedef struct Queue Queue;

Queue *q;

int isFull(){
	if(q->r==q->size-1){
		return 1;
	}
	return 0;
}

int isEmpty(){
	if(q->r==-1){
		return 1;
	}
	return 0;
}

void enQueue(){
	
	if(isFull()){
		printf("Queue is Full!!\n");
		return;
	}
	else{
		s++;
		int num;
		printf("Enter the Number: ");
		scanf("%d",&num);
		
		if(q->r==-1){
			q->r=q->f=0;
			q->a[q->r]=num;
		}
		else{
			q->r++;
			q->a[q->r]=num;
		}
		printf("%d is EnQueued!!\n",num);
	}
	
}

void deQueue(){
	
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	else{
		s--;
		int num;
		if(q->f==q->r){
			
			num=q->a[q->f];
			q->r=q->f=-1;
			
		}
		else{
			num=q->a[q->f];
			q->f++;
		}
		
		printf("%d is Dequeued!!\n",num);
	}
}

void peek(){
	
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	int pos;
	
	printf("Enter the Position: ");
	scanf("%d",&pos);
	
	int ind=q->f+pos-1;
	
	printf("%d is Peeked!!\n",q->a[ind]);
}

void front(){
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	printf("%d is Front!!\n",q->a[q->f]);
}

void rear(){
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	printf("%d is Rear!!\n",q->a[q->r]);
}

void display(){
	
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	
	int i;
	for(i=q->f;i<=q->r;i++){
		printf("%d ",q->a[i]);
	}
	printf("\n");
}

void size(){
	printf("The Size is %d\n",s);
}
int main(){
	
	q=(Queue*)malloc(sizeof(Queue));
	q->r=q->f=-1;
	printf("Enter the size of Queue:\n");
	scanf("%d",&q->size);
	q->a=(int*)malloc(q->size*sizeof(int));
	int choice;
	while(1){
		
		printf("Enter the operation: 1.EnQueue() 2.Deque 3.Peek() 4.Front() 5.Rear() 6.size() 7.Display() 8.Exit()\n");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1: enQueue();
			break;
		
			case 2: deQueue();
			break;
			
			case 3: peek();
			break;
			
			case 4: front();
			break;
			
			case 5: rear();
			break;
			
			case 6: size();
			break;
			
			case 7: display();
			break;
			
			case 8: exit(0);
			break;
			
			default:
				printf("Invalid Choice!!\n");
			
		}
	}
	
	return 0;
}
