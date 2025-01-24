#include<stdio.h>
#include<conio.h>

struct node {

    struct node*left;
    int data;
    struct Node*right;
};
struct node*root = NULL;
struct node*newnode;
struct node*temp;
struct node*parent;
struct node*succ;
struct node*insert(struct node*root,int n) {
    if(root==NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->left=NULL;
        newnode->data=n;
        newnode->right=NULL;
        return newnode;
    }
    if(n<root->data)
    {
        root->left = insert(root->left,n);
        return root;
            }
    else{
        root->right = insert(root->right,n);
        return root;
    }
}
void Inorder(struct node*root){
 if(root!=NULL){
   Inorder(root->left);
   printf("%d\n",root->data);
   Inorder(root->right);
 }
}
struct node*delnode(struct node*root,int n){
 if(root==NULL)
{
  return root;
}
if(n<root->data){
 root->left = delnode(root->left,n);
 return root;
 
}
else if(n>root->data){
  root->right = delnode(root->right,n);
  return root;
 }
 else{
  if(root->left==NULL){
    temp = root->right;
    free(root);
    return temp;
  }
  else if(root->right==NULL){
   temp = root->right;
   free(root);
   return temp;
  }
  else 
  {
    parent = root;
    succ = root->right;
    while(succ->left!=NULL)
   {
   parent=succ;
   succ = succ->left;
   }
   if(parent!=root){
   parent->left=succ->right;
    }
    else{
     parent->right=succ->right;
     }
    
    root->data=succ->data;
    free(succ);
    return root;
    
   
          
    }
  }
 }

int main() {

root = insert(root,34);
root = insert(root,20);
root = insert(root,44);
root = insert(root,14);
root = insert(root,30);
printf("\n the inserted elements are :\n");
Inorder(root);
root = delnode(root,44);
root = delnode(root,20);
printf("\n after deleting numbers :\n");
Inorder(root);
    return 0;
}
