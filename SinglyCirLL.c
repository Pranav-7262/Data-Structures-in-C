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


return head;
}
struct Node *deleteAtFirst(struct Node *head)
{
//int data;
struct Node *ptr=head;

 while(ptr->next!=head){
  ptr=ptr->next;
 }
  
  ptr->next=head->next;
  struct Node*p=head->next;
  head=head->next;
  //ptr->next=hea
  free(p);
  return head;
  
  printf("\n node deleted");
 
}
 
 struct Node *lastDelete(struct Node *head)
{
  struct Node *ptr;
  struct Node *temp=head->next;
  ptr=head;
  while(ptr->next!=head){
    temp=ptr;
   ptr=ptr->next;
   
  }
   ptr=head;
   temp->next=head;
   free(ptr);
   return head;
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

A=deleteAtFirst(A); 
printf("\n After deleting 1st element");
//deleteAtFirst(A);
linkedListTraversal(A);
A=lastDelete(A);
printf("\n after deletion at last");
linkedListTraversal(A);
}