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
	if((q->r+1)%q->size==q->f){
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
		int let;
		printf("Enter the Number: ");
		scanf("%d",&let);
		
		if(q->r==-1){
			q->r=q->f=0;
			q->a[q->r]=let;
		}
		else{
			q->r=(q->r+1)%q->size;
			q->a[q->r]=let;
		}
		printf("%d is EnQueued!!\n",let);
	}
	
}

void deQueue(){
	
	if(isEmpty()){
		printf("Queue is Empty!!\n");
		return;
	}
	else{
		s--;
		int let;
		if(q->f==q->r){
			
			let=q->a[q->f];
			q->r=q->f=-1;
			
		}
		else{
			let=q->a[q->f];
			q->f=(q->f+1)%q->size;
		}
		
		printf("%d is Dequeued!!\n",let);
	}
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
		printf("Queue is Empty!!");
		return;
	}
	printf("%d is Rear!!\n",q->a[q->r]);
}

void display(){
	
	if(isEmpty()){
		printf("Queue is Empty!!");
		return;
	}
	
	int i=q->f;
	while(i!=q->size){
		printf("%d ",q->a[i]);
		if(i==q->r){
			break;
		}
		i=(i+1)%q->size;
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
	int op;
	while(1){
		
		printf("Enter the operation: 1.EnQueue() 2.Deque 3.Front() 4.Rear() 5.size() 6.Display() 7.Exit()\n");
		scanf("%d",&op);
		
		switch(op){
			
			case 1: enQueue();
			break;
		
			case 2: deQueue();
			break;
			
			case 3: front();
			break;
			
			case 4: rear();
			break;
			
			case 5: size();
			break;
			
			case 6: display();
			break;
			
			case 7: exit(0);
			break;
			
			default:
				printf("Invalid Choice!!\n");
			
		}
	}
	
	return 0;     
}


