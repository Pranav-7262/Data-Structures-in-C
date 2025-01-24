#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node *n; // creating a node
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data..
    n->left = NULL; // Setting the left children to NULL
    n->right = NULL; // Setting the right children to NULL
    return n; // Finally returning the created node
}

struct node* search(struct node* root,int key)
{
 if(root==NULL){
  return NULL;
 }
 if(root->data==key){
  return root;
 }
 else if(root->data > key){
  return search(root->left,key);
 }
 else{
  return search(root->right,key);
 }
 }
 
int main()
{
    //constructing a root nodes
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(4);

    //Linking a root nodes to left and right children's.
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    struct node* n = search(p,22);
    if(n!=NULL){
     printf("%d is found successfully",n->data); 
    }
    else{
     printf("\n element is not found..");
    }
        return 0;
}