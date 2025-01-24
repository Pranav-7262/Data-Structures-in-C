#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Node;

Node *head=NULL;


int size=0;

Node *create(int val){
	Node*ptr = (Node*)malloc(sizeof(Node));
	
	ptr->data=val;
	
	ptr->next=NULL;
    
	return ptr;
}

void insertAtFirst(){
	int val;
    ptr=(Node*)malloc(sizeof()Node);
	printf("Enter the Value: ");
	scanf("%d",&val);
	ptr->data=item;
	size=size+1;
	
	if(head==NULL){
		head=ptr;
	}
	else{
		
		
		ptr->next=head;
		
		head=ptr;
	}
	
	printf("%d is Inserted At First!!\n",val);
	
}

void insertAtIndex(){
	printf("Enter the Value: ");
	int val;
	scanf("%d",&val);
	
	printf("Enter the position: ");
	int pos;
	scanf("%d",&pos);
	
	if(pos>size){
		printf("Position is not out of Bound!!\n");
		return;
	}
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	size++;
	Node *newNode=create(val);
	
	Node*temp1=head;
	Node*temp2=head->next;
	
	int i=1;
	
	while(i<pos-1){
		
		
		temp1=temp1->next;
		temp2=temp2->next;
		i++;
		
	}
	
	temp1->next=newNode;
	newNode->next=temp2;
	
	temp2->prev=newNode;
	newNode->prev=temp1;
	
	printf("%d is inserted at %d\n",val,pos);
}

void insertAtlast(){
	
	int val;
	printf("Enter the value\n");
	scanf("%d",&val);
	
	if(head==NULL){
	    printf("Linked List is Empty!!\n");
		return;
	}
	
	Node *newNode=create(val);
	
	Node *temp=head;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	temp->next=newNode;
	newNode->prev=temp;
	size++;
	printf("%d is inserted At Last:\n",val);
}

void printListNext(){
	Node*temp=head;
	
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void printListPrev(){
	
	Node*temp1=head;
	
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	
	
	
	Node*temp2=temp1;;
	
	
	while(temp2!=NULL){
		printf("%d->",temp2->data);
		temp2=temp2->prev;
	}
	printf("NULL\n");
}

void deleteAtFirst(){
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	
	Node *temp=head;
	head=head->next;
	head->prev=NULL;
	size--;
	printf("%d is Deleted!!\n",temp->data);
	free(temp);
}

void deleteAtLast(){
	if(head==NULL){
		printf("Lnked List is Empty!!!\n");
		return;
	}
	
	Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	Node *p=temp->prev;
	p->next=NULL;
	size--;
	printf("%d is Deleted!!\n",temp->data);
	free(temp);
	
}

void deleteAtPosition(){
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	
	printf("Enter the position: ");
	int pos;
	scanf("%d",&pos);
	
	if(pos>size){
		printf("Position is not out of Bound!!\n");
		return;
	}
	
	Node*temp1=head;
	Node*temp2=head->next;
	
	int i=1;
	
	while(i<pos-1){
		
		
		temp1=temp1->next;
		temp2=temp2->next;
		i++;
		
	}
	
	temp1->next=temp2->next;
	temp2->next->prev=temp1;
	Node *p=temp2;
	size--;
	printf("%d is Deleted!!\n",temp2->data);
	free(temp2);
	
}

void getSize(){
	printf("The Size of Linked List is : %d\n",size);
}

void first(){
	if(head==NULL){
		printf("Linked List is Empty!!!\n");
		return;
	}
	
	printf("%d is Head of Linked List!!\n",head->data);
}

void last(){
	if(head==NULL){
		printf("Linked List is Empty!!!\n");
		return;
	}
	
		
	Node*temp1=head;
	
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	printf("%d is Tail of Linked List!!\n",temp1->data);
}
int main(){
	int ch;
	
	while(1){
		printf("\nenter the choise:1.InsertAtfirst,2.InsertAtlast,3.InsertAtPosition,4.DeleteAtfirst,5.DeleteAtlast,6.DeleteAtPosition,7.PrintListFormHead,8.PrintListFromTail,9.Head,10.Tail,11.Size,12.exit:\n");
		scanf("%d",&ch);
		
	switch(ch){
		case 1:
			insertAtFirst();
			break;
		case 2:
			insertAtlast();
			break;
		case 3:
			insertAtIndex();
			break;
		case 4:
			deleteAtFirst();
			break;
		case 5:
			deleteAtLast();
			break;
		case 6:
			deleteAtPosition();
			break;
		case 7:
			printListNext();
			break;
		case 8:
			printListPrev();
			break;
		case 9:
			first();
			break;
		case 10:
			last();
			break;
		case 11:
			getSize();
			break;
		case 12:
			exit(0);
		default:
				printf("INVALID CHOICE!!\n");
			
	}
			
	}
	
	
	
}