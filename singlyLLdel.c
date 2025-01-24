//implementing all deletion in linked list
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
		printf("%d",head->data);
		head=head->next;
	}
	printf("NULL\n");
}
struct node *deleteFirst(struct node *head){
	struct node *temp=head;
	head=head->next;
	free(temp);
	return head;
}
struct node *deleteLast(struct node *head){
	struct node *temp=head->next;
	struct node *headCopy=head;
	while(temp->next!=NULL){
		temp=temp->next;
		headCopy=headCopy->next;
	}
	headCopy->next=NULL;
	free(temp);
	return head;
}
struct node *deleteAtIndex(struct node *head,int ind){
	struct node *temp=head->next;
	struct node *copy=head;
	int i=1;
	while(i<ind){
		temp=temp->next;
		copy=copy->next;
		i++;
	}
	copy->next=temp->next;
	free(temp);
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
	printf("Here Are The All Linked List Elements:\n");
	print(n1);
	printf("\nDeleting The First Element of Linked List:\n");
	n1=deleteFirst(n1);
	print(n1);
	printf("\nDeleting The Last Element of Linked List:\n");
	n1=deleteLast(n1);
	print(n1);
	printf("\nDeleting The Element Index of Linked List:\n");
	n1=deleteAtIndex(n1,2);
	print(n1);
	return 0;
}
