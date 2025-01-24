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

 Node*node=(node*)malloc(sizeof(node));
 node->data=val;
 node->left=NULL;
 node->right=NULL;
 return node;

}
Node*root=NULL;
void populateTree(Node*node){

 int left;
 printf("\n enter left value  of %d otherwise 0",node->data);
 scanf("%d",&left);
 if(left==1){
  node->left=create(val);
  populateTree(node->left);
 }
 int right;
 printf("\n enter right value  of %d otherwise 0",node->data);
 scanf("%d",&right);
 if(right==1){
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
void displayTree(Node*node,int level){
  if(node==null){
    return;
  }
  displayTree(node->right,level+1);
  if(level!=0){
     int i;
     for(i=0;i<level;i++){
     
      printf("|\t");
     }
     printf("\n ----->",node->data);
    
  }
  printf("");
  
displayTree(node->left,level+1);

}

display(){
  displayTree(node,0);
}

int main(){

 int i;
  
}