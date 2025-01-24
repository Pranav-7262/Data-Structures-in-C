#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;

};
struct Node *head=NULL;
void linkedListTraversal(struct Node *head){
struct Node *ptr = head;
do {
    printf("\n element is:%d\n",ptr->data);
    ptr=ptr->next;
}
while(ptr!=head);

}
struct Node *InsertAtFirst(struct Node *head,int data){
struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
ptr->data=data;
struct Node *p = head->next;
while(p->next!=head){
 p = p->next;
}
p->next=ptr;
ptr->next=head;
head=ptr;
return head;

}
struct Node *InsertAtLast(struct Node *head,int data)
{

struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
temp->data=data;
temp->next=NULL;
struct Node *ptr = head->next;
//ptr->data=data;
while(ptr->next!=head) {
 ptr=ptr->next;
}
ptr->next=temp;
temp->next=head;
//return head;


}
void deleteAtFirst()
{
struct Node *ptr;
if(head=NULL)
{
  printf("\n underflow");
}
else {
   ptr=head;
 //struct Node *ptr=head->next;
 while(ptr->next!=head){
  ptr=ptr->next;
 }
  ptr->next=head->next;
  //head=head->next;
  free(head);
  head=ptr->next;
  printf("\n node deleted");
 }
 }

int main(){
  struct Node *A;
  struct Node *B;
  struct Node *C;
  
  A=(struct Node*)malloc(sizeof(struct Node));
  B=(struct Node*)malloc(sizeof(struct Node));
  C=(struct Node*)malloc(sizeof(struct Node));
A->data=2;
A->next=B;

B->data=3;
B->next=C;

C->data=4;
C->next=A; 
printf("\n After traversing a circular linked list");
linkedListTraversal(A);

A =InsertAtFirst(A,56);
printf("\n After inserting at first");
linkedListTraversal(A);
A =InsertAtLast(A,35);
printf("\n After inserting at last");

linkedListTraversal(A);

deleteAtFirst(); 
printf("\n After deleting 1st element");
//deleteAtFirst(A);
linkedListTraversal(A);
}