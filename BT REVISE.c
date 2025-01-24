#include<stdio.h>
#include<stdlib.h>
struct Node{
 int data;
 struct node*left;
 struct node*right;
};
typedef struct Node Node;
//Node*root = NULL;
Node*create(int val){

 Node*node=(Node*)malloc(sizeof(Node));
 node->data=val;
 node->left=NULL;
 node->right=NULL;
 return node;

}
Node*root=NULL;
void populateTree(Node*node){

 int left;
 printf(" enter 1 to set left value  of %d otherwise 0\n",node->data);
 scanf("%d",&left);
 if(left==1){
 int val;
 printf("enter left value:\n");
 scanf("%d",&val);
  node->left=create(val);
  populateTree(node->left);
 }
 int right;
 printf(" enter 1 to set right value  of %d otherwise 0\n",node->data);
 scanf("%d",&right);
 if(right==1){
 int val;
 printf("enter the right value:\n");
 scanf("%d",&val);
  node->right=create(val);
  populateTree(node->right);
 }
 
}
void populate(){
  int val;
  printf("\n enter thr root valuee...");
  scanf("%d",&val);
  root=create(val);
  populateTree(root);
}
void displayTree(Node* node,int level){
  if(node==NULL){
    return;
  }
  displayTree(node->right,level+1);
  if(level!=0){
     int i;
     for(i=1;i<level;i++){
     
      printf("|\t");
     }
     printf(" ----->%d\n",node->data);
    
  }
  else {
    printf("%d\n",node->data);
  }
  
displayTree(node->left,level+1);

}

display(){
  displayTree(root,0);
}

int main(){

 populate();
 display();
  
}