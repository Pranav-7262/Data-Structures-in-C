//implementing stack data structure by using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *top=NULL;
struct Node *create(int num){
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=num;
	newNode->next=NULL;
	return newNode;
}
int isFull(){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL){
		return 1;
	}
	return 0;
}
int isEmpty(struct Node *top){
	if(top==NULL){
		return 1;
	}
	return 0;
}
struct Node *push(int num){
	if(isFull()){
		printf("StackOverFlow!!!\n");
		return 0;
	}
	struct Node *newNode=create(num);
	newNode->next=top;
	top=newNode;
	printf("Pushed Element is %d\n",num);
	return top;
}
int pop(struct Node *tp){
	if(isEmpty(tp)){
		printf("StackUnderFlow!!\n");
		return -1;
	}
	struct Node*temp=tp;
	int num=temp->data;
	top=tp->next;
	free(temp);
	return num;
}
void printList(){
	while(top!=NULL){
		printf("%d-->",top->data);
		top=top->next;
	}
	printf("NULL\n");
}
int main(){
	top=push(561);
	top=push(896);
	top=push(657);
	top=push(765);
	top=push(665);
	top=push(856);
	top=push(776);
	top=push(976);
	top=push(345);
	printf("Poped Element is %d\n",pop(top));
	printf("Poped Element is %d\n",pop(top));
	printf("Poped Element is %d\n",pop(top));
	printf("Poped Element is %d\n",pop(top));
	printf("Poped Element is %d\n",pop(top));
	printList();
	return 0;
}