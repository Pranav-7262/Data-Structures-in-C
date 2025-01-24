#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Node;
int size=0;
Node*head=NULL;
Node*createnode(int val){
	Node*Newnode=(Node*)malloc(sizeof(Node));
	Newnode->data=val;
	Newnode->next=NULL;
	return Newnode;
}
void insertFirst(){
	int val;
	printf("\nEnter a val:");
	scanf("%d",&val);
	Node*Newnode=createnode(val);
	size++;
	if(head==NULL){
		head=Newnode;
	}
	else{
		Newnode->next=head;
		head=Newnode;
		
	}
	printf("\n %d is inseted ",val);
}
void insertRandom(){
	if(head==NULL){
		printf("\nLinkeed list is empty");
	}
	size++;
	int val,pos;
	printf("\nEnter a val:");
	scanf("%d",&val);
	Node*Newnode=createnode(val);
	printf("\enter the index to insert:");
	scanf("%d",&pos);
	int i=1;
	Node*temp1=head;
	Node*temp2=head->next;
	while(i<pos){
		temp1=temp2;
		temp2=temp2->next;
		i++;
	}
	temp1->next=Newnode;
	Newnode->next=temp2;
	printf("%d is Inserted At %d!!\n",pos);	

}
void insertlast(){
	if(head==NULL){
		printf("\nLinkeed list is empty");
		return;
	}
	size++;
	int val;
	printf("\nEnter a val:");
	scanf("%d",&val);
	Node*Newnode=createnode(val);
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=Newnode;
	printf("%d is Inserted At Last!!\n");
}
void deleteFirst(){
	if(head==NULL){
		printf("\nLinkeed list is empty");
		return;
	}
	size--;
	Node*temp=head;
	head=head->next;
	printf("%d is Deleted as First!!\n",temp->data);
	free(temp);
}
void deleteRandom(){
	if(head==NULL){
		printf("\nLinkeed list is empty");
		return;
	}
	int pos;
	printf("\nEnter a position:");
	scanf("%d",&pos);
	if(pos>size){
		printf("\npos out of bound");
		return;
	}
	size--;
	int i=1;
	Node*temp1=head;
	Node*temp2=head->next;
	while(i<pos){
		temp1=temp2;
		temp2->next;
		i++;
	}
	temp1->next=temp2->next;
	printf("%d is Deleted at %d position!!\n",temp2->data,pos);
	free(temp2);		
	}
void deletelast(){
	if(head==NULL){
		printf("\nLinked list is empty");
		return;
   }
    size--;
    Node*temp1=head;
    Node*temp2=head->next;
    while(temp2->next!=NULL){
    	temp1=temp2;
    	temp2=temp2->next;
	}
	temp1->next=temp2->next;
	printf("\n %d is deleted",temp2->data);
	free(temp2);
}
void display(){
	Node*temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void getSize(){
	printf("The Size of Linked List is %d\n",size);
}
int main(){
  while(1){
	int ch;
	printf("\nEnter a choice : 1.insertFirst() 2.insertRandom() 3.insertlast() 4.deleteFirst() 5.deleteRandom() 6.deletelast() 7.display() 8.getSize() 9.exit() \n");
	scanf("%d",&ch);
	switch(ch){
		case 1:insertFirst();
				break;	
			case 2:insertRandom();
				break;	
			case 3:insertlast();
				break;
			case 4:deleteFirst();
				break;
			
			case 5:deleteRandom();
				break;
				
			case 6:deletelast();
				break;
			case 7:display();
				break;
		
			case 8:getSize();
				break;	
			case 9:exit(0);
				break;	
			default:
				printf("Invalid Choice!!!\n");
		}
	}
	return 0;
	
}

