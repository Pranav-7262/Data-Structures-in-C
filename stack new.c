#include<stdio.h>
#include<stdlib.h>
struct Stack{
	int top;
	int size;
	int *stack;
};
typedef struct Stack Stack;
Stack *s;
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
		printf("Stack Overflow!!\n");
		return;
	}
	int val;
	printf("Enter the Value:\n");
	scanf("%d",&val);
	s->top++;
	s->stack[s->top]=val;
	n=n+1;
	printf("%d is pushed!!\n",val);
}
void pop(){
	if(isEmpty()){
		printf("Stack Underflow!!\n");
		return;
	}
	int val;
	
	val=s->stack[s->top];
	s->top--;
	n=n-1;;
	printf("%d is poped!!\n",val);
}
void stackTop(){
	if(isEmpty()){
		printf("Stack is Empty!!\n");
		return;
	}
	printf("The Top of Stack is %d\n",s->stack[s->top]);
}
void stackBottom(){
	if(isEmpty()){
		printf("Stack is Empty!!\n");
		return;
	}
	printf("The Bottom of Stack is %d\n",s->stack[0]);
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
	s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;
	printf("Enter the size of Stack:\n");
	scanf("%d",&s->size);
	s->stack=(int*)malloc(s->size*sizeof(int));
	while(1){
		int choice;
		printf("Enter the Operation: 1.push() 2.pop() 3.Size() 4.Display() 5.Stakctop() 6.StackBottom() 7.exit():\n");
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
			case 5:stackTop();
			break;
			
			case 6:stackBottom();
			break;
			case 7:exit(0);
			default:
				printf("Invalid Chioce!!");
		}
	}
	return 0;
}
