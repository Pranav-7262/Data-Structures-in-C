#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;
void linkedListTraversal(struct Node *ptr) {
 
 while(ptr!=NULL)
{
 printf(" printing elements of this linked list\n ");
 printf("element:%d\n", ptr->data);
 ptr=ptr->next;

}

}
 void enqueue(int val) {
 struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if(n==NULL){
      printf("queue is full");  
  }
  else {
  n->data=val;
  n->next=NULL;}
  
  if(f==NULL){
     f=r=n;
  }
  else {
    r->next=n;
    r=n;
  
  }
}

int dequeue(){
int val=-1;
struct Node *ptr = f;
if(f==NULL)
{
  printf("\n Queue is Empty");
}
else {
   f=f->next;
   val=ptr->data;
   free(ptr);
    
}
 return val;
}

int main() {
   linkedListTraversal(f);
   enqueue(12);
   enqueue(33);
   enqueue(45);
   printf("\n dequeueing element:%d\n",dequeue());
   printf("\n dequeueing element:%d\n",dequeue());
  printf("\n dequeueing element:%d\n",dequeue());
   linkedListTraversal(f);
   
   return 0;





}
