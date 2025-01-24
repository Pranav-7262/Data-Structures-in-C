#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next

};
void linkedListTraversal(struct Node *head){
struct Node *ptr = head;
do {
    printf("\n element is:%d\n",ptr->data);
    ptr=ptr->next;
}
while(ptr!=head);

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







}