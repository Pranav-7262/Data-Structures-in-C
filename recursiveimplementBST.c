#include<stdio.h>
#include<conio.h>

struct node {

    struct node*left;
    int data;
    struct Node*right;
};
struct node*root = NULL;
struct node*newnode;
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
    }
    else {
        root->right = insert(root->right,n);
    }
    return root;
}
void Inorder(struct node*root){
 if(root!=NULL){
   Inorder(root->left);
   printf("%d\n",root->data);
   Inorder(root->right);
 }
}
int main() {

root = insert(root,34);
root = insert(root,20);
root = insert(root,44);
root = insert(root,14);
root = insert(root,30);
Inorder(root);
    return 0;
}
