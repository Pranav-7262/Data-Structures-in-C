#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *head =NULL;

void linkedListTraversal(struct Node *head ){
struct Node*temp=head;
while(temp!=NULL) 
{
printf("%d->\n",temp->data);
   
   temp=temp->next;
}
printf("NULL");

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


int main()
{

insertFirst();
insertFirst();
printf("\n after insert at 1st\n");
linkedListTraversal(head);
insertLast();
printf("\n after inserting at last\n");
linkedListTraversal(head);
randomInsert();
printf("\n after randomly insert\n");
linkedListTraversal(head);

}