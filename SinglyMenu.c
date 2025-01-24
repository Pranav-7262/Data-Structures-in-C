#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node*next;
};
typedef struct Node Node;
int size=0;
Node *head=NULL;
Node *create(int val){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}
void insertAtFirst(){
	int num;
	printf("Enter the Element:\n");
	scanf("%d",&num);
	Node *newNode=create(num);
	size++;
	if(head==NULL){
		head=newNode;
	}
	else{
		newNode->next=head;
		head=newNode;
	}
	printf("%d is Inserted At First!!\n",num);
}
void insertAtIndex(){	
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	size++;
	int val,pos;
	printf("Enter the Element:\n");
	scanf("%d",&val);
	Node *newNode=create(val);
	printf("Enter the Position:");
	scanf("%d",&pos);
	int i=1;
	if(pos>size){
		printf("Position does Not Exists!!\n");
		return;
	}
	Node * temp1=head;
	Node * temp2=head->next;
	
	while(i<pos){
		temp1=temp2;
		temp2=temp2->next;
		i++;
	}
	temp1->next=newNode;
	newNode->next=temp2;
printf("%d is Inserted At %d!!\n",pos);	
}
void insertAtLast(){	
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	size++;
	int num;
	printf("Enter the Element:\n");
	scanf("%d",&num);
	Node *newNode=create(num);
	Node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}	
	temp->next=newNode;
	printf("%d is Inserted At Last!!\n");
}
void deleteAtFirst(){	
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	size--;
	Node *temp=head;
	head=head->next;
	printf("%d is Deleted as First!!\n",temp->data);
	free(temp);	
}
void deleteAtIndex(){	
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}	
	int pos;
	printf("Enter the Position:");
	scanf("%d",&pos);
	if(pos>size){
		printf("Position does Not Exists!!\n");
		return;
	}
	size--;
	int i=1;
	Node * temp1=head;
	Node * temp2=head->next;
	while(i<pos){
		temp1=temp2;
		temp2->next;
		i++;
	}
	temp1->next=temp2->next;
	printf("%d is Deleted at %d position!!\n",temp2->data,pos);
	free(temp2);	
}
void deleteAtLast(){	
	if(head==NULL){
		printf("Linked List is Empty!!\n");
		return;
	}
	size--;
	Node * temp1=head;
	Node * temp2=head->next;
	while(temp2->next!=NULL){
		temp1=temp2;
		temp2=temp2->next;
	}
	
	temp1->next=temp2->next;
	printf("%d is deleted as LastNode!!\n",temp2->data);
	free(temp2);	
}
void display(){
	Node *temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void search(){
	
	if(head==NULL){
		printf("LinkedList is Empty!!\n");
		return;
	}
	int target,i=1,flag=0;
	printf("Enter the Target Element:\n");
	scanf("%d",&target);
	Node *temp=head;
	while(temp!=NULL){	
		if(temp->data==target){
			flag=1;	
			break;
		}
		i++;
		temp=temp->next;
	}
	flag?printf("Found At position %d\n",i):printf("Not Found!!\n");	
}
void getSize(){
	printf("The Size of Linked List is %d\n",size);
}
int main(){	
	while(1){		
		int op;
		printf("Enter the Operation: 1.insertAtFirst() 2.insertAtPosition() 3.insertAtLast() 4.deleteAtFirst() 5.deleteAtPosition() 6.deleteAtLast() 7.Display() 8.Search() 9.Size() 10.exit():\n");
		scanf("%d",&op);	
		switch(op){		
			case 1:insertAtFirst();
				break;	
			case 2:insertAtIndex();
				break;	
			case 3:insertAtLast();
				break;
			case 4:deleteAtFirst();
				break;
			
			case 5:deleteAtIndex();
				break;
			case 6:deleteAtLast();
				break;
			case 7:display();
				break;
			case 8:search();
				break;	
			case 9:getSize();
				break;	
			case 10:exit(0);
				break;	
			default:
				printf("Invalid Choice!!!\n");
		}
	}
	return 0;
}
