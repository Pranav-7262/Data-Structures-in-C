#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct Node{
  int data;
  struct Node *next;

};
void linkedListTraversal(struct Node *ptr) {
 while(ptr != NULL)
 {
   printf("\n element:%d\n",ptr->data);
   ptr=ptr->next; 
 
 }
 }
 struct Node * deleteAtFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
 }

struct Node *randomDelete(struct Node *head, int index){

 struct Node *p = head;
 struct Node *q = head->next;
 for(int i=0;i<index-1;i++)
 {
   p = p->next;
   q = q->next;
 
 }
  p->next = q->next;
  free(q);
  return head;
}
struct Node *deleteAtLast(struct Node *head){
  struct Node *p = head;
  struct Node *q = head->next;
  while(q->next != NULL){
  
   p = p->next;
   q = q->next;
  }
   p->next=NULL;
   free(q);
   return head;
   
}
int main() {

  struct Node *head;
  struct Node *First;
  struct Node *second;
  head = (struct Node*)malloc(sizeof(struct Node));
  First = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  head->data=12;
  head->next=First;
  
  First->data=34;
  First->next=second;
  
  second->data=45;
  second->next=NULL; 
  
  printf("\n linked list before deletion");
  linkedListTraversal(head);
  printf("\n linked list after deletion");
  head = deleteAtLast(head);
  
  linkedListTraversal(head);
  return 0;
}