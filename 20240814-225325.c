//implementation of linked list all insertion operations
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* create(int num){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	return newnode;
}
void print(struct node *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
struct node *insertFirst(struct node *head,int num){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head=newnode;
}
struct node *insertLast(struct node *head,int num){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=NULL;
	return head;
}
struct node *insertAtIndex(struct node*head,int num,int ind){
	struct node *newnode=create(num);
	struct node *temp=head;
	int i=0;
	while(i<ind){
		temp=temp->next;
		i++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	return head;
}
int main(){
	struct node* n1=create(56);
	struct node* n2=create(35);
	struct node* n3=create(89);
	struct node* n4=create(23);
	struct node* n5=create(13);
	struct node* n6=create(87);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	printf("Here Are The All Elements of Linked List:\n");
	print(n1);
	printf("\nInserting The Element At First:\n");
    
	n1=insertFirst(n1,16);
    printf(n1);
	
	printf("\nInserting The Element At Last:\n");
	n1=insertLast(n1,84);
	print(n1);
	printf("\nInserting The Element At Index 3:\n");
	n1=insertAtIndex(n1,11,3);
	print(n1);
	return 0;
}
