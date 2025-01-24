#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top;
	int size;
	int *stack;
};
typedef struct stack stack;
stack *s;
int n=0;
int isEmpty(){
	if(s->top==-1){
		return 1;
	}
	return 0;
}
int isFull(){
	if(s->top==s->size-1){
		return 1;
	}
	return 0;
}
void push(){
	if(isFull()){
		printf("\nStack is Overflow");
		return;
	}
		int val;
		printf("enter val to push");
		scanf("%d",&val);
		s->top++;
		s->stack[s->top]=val;
		n=n+1;
		printf("\n%dis inserted",val);
	
	
}
void pop(){
if(isEmpty()){
		printf("\nStack is Underflow");
		return;
	}
		int val;
	
		val=s->stack[s->top];
		s->top--;
		n=n-1;
		printf("\n %d is deleted",val);
	
	
}
void stacktop(){
     	if(isEmpty()){
		printf("Stack is Empty!!\n");
		return;
	}
	printf("The Top of Stack is %d\n",s->stack[s->top]);
}
void size(){
	printf("The Size of Stack is %d\n",n);
}
void display(){
	if(isEmpty()){
		printf("Stack is Empty!!\n");
		return;
	}
	int i;
	
	for(i=s->top;i>=0;i--){
		printf("%d ",s->stack[i]);
	}
	
	printf("\n");
}
int main(){
	s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	printf("\nEnter size of stack");
	scanf("%d",&s->size);
	s->stack=(int*)malloc(s->size*sizeof(int));
	while(1){
		int choice;
		printf("\nEnter the Operation: 1.push() 2.pop() 3.Size() 4.Display() 5.Stakctop() 6.exit():\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:size();
			break;
			case 4:display();
			break;
			case 5:stacktop();
			break;
			case 6:exit(0);
			break;
			default:
				printf("invalid choice");
}
}
return 0;
}

