#include<stdio.h>
#include<stdlib.h>
#define s 10 
struct node {
    int data;
    struct node*next;
};

struct node *ht[s];
struct node *newnode;
struct node *temp;
void display()
{ 
int i;
for(i=0;i<s;i++){
  if(ht[i]==NULL){
   printf("%d\nNULL",i);
  }
  else {
  printf("%d\t",i);
    temp = ht[i];
    while(temp!=NULL){
    printf("%d\t",temp->data);
    temp = temp->next;
    }
  }
  printf("\n");
}
   
    

}
void insert(int n){
  int key = n%10;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next = NULL;
  if(ht[key]==NULL){
     ht[key]= newnode;
  }
  else{
    temp = ht[key];
    while(temp->next!=NULL){
      temp  = temp->next;
    }
    temp->next = newnode;
  }
  
}
int search(int n){
 int key=n%10;
 int found = 0;
 if(ht[key]==NULL){
   found =0;
 }
 else {
   temp = ht[key];
   while(temp!=NULL){
    if(temp->data==n){
       found =1;
       break;
       }
       temp = temp->next;
   }
 }
 return found;
}

int main() {
      int r;
    insert(24);
    insert(34);
    insert(44);
    insert(74);
    insert(82); 
    insert(452);
    insert(92);
    display();
    r = search(452);
    if(r==1){
       printf("\n found");
    }
    else{
     printf("\nNot Found");
    }
    
       return 0;
}