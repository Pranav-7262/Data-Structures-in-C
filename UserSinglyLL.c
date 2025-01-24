#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
 
struct Node *head=NULL;




struct Node *create(int val){
	struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
	
	ptr->data=val;
	
	ptr=ptr->next;
	
	
	return ptr;

}

void insertFirst()
{
int item; 
struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\n enter the value");
scanf("%d",&item);
ptr->data=item;
if(head==NULL){
   head=ptr;
}

else {
  ptr->next=head;
  head=ptr;
}

}
void insertLast(){
 struct Node *ptr,*temp;
 int item;
 ptr=(struct Node*)malloc(sizeof(struct Node));
 printf("\n enter a value for insert at end or last");
 scanf("%d",&item);
 ptr->data=item;
ptr->next=NULL;

if(head==NULL){
head=ptr;
printf("\n Node inserted");
}
else {
temp=head;
while(temp->next!=NULL){
temp=temp->next;

}
temp->next=ptr;
printf("\n Node inserted");
}
}
void randomInsert(){
int i,loc,item;
struct Node *ptr,*temp;
ptr=(struct Node*)malloc(sizeof(struct Node));
printf("\n enter element for random");
scanf("%d",&item);
ptr->data=item;
printf("\n enter location which you want to insert");
scanf("%d",&item);
temp=head;
for(i=1;i<=loc-1;i++){
   temp=temp->next;}
   if(temp==NULL)
   {
   
   printf("\n cant insert");
   return;
   }
  temp->next=ptr->next,
  temp->next=ptr;
  
  printf("\n Node inserted");
}

void linkedListTraversal(struct Node *ptr){
while(ptr!=NULL)
{
printf("\n element:%d->",ptr->data);

  ptr=ptr->next;
}
printf("\n NULL");
}
int main()
{

int ch;
while(1)
{
printf("\n enter a choice : \n\t1.insertFirst \n\t2.insertLast \n\t3.randomInsert \n\t4.linkedListTraversal \n\t5.exit\n");
scanf("%d",&ch);

switch(ch){
case 1:
  insertFirst(); break;
  case 2:
  insertLast(); break;
  case 3:
  randomInsert(); break;
  case 4:
  linkedListTraversal(head); break;
  case 5:
  exit(0); break;
  default:
  printf("\n wrong choice");
}
}
}