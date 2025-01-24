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

void Inorder(struct node* root) {//creating a function of preorder
    if(root!=NULL)
    {
        
        Inorder(root->left);
        printf("%d",root->data);
        Inorder(root->right);
        

    }
}

struct node* Inorderpredecessor(struct node* root)
{
 root = root->left;
 while(root->right != NULL){
  root = root->right;
 
 }
 return root;
}
struct node* deleteNode(struct node* root,int value)
{
//Search for the node to be deleted. 
  struct node* iPre;
  if(root==NULL) {
   return NULL;
  }
  if(root->left==NULL && root->right==NULL){
    free(root);
    return NULL;
    }
    
    
   if(value<root->data) {
    root->left = deleteNode(root->left,value);
    }
    else if(value>root->data){
     root->right = deleteNode(root->right,value);
     
    } // Deletion statergy to delete a node...
    else 
    {
    iPre=Inorderpredecessor(root);
    root->data = iPre->data;
    root->left = deleteNode(root->left,iPre->data);
        
   } 
   return root;    
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

    printf("\n Inorder traversing :");
    Inorder(p);
    
    deleteNode(p,3);
    printf("\n");
  //  printf("[Data is %d]",p->data);
    Inorder(p);
    printf("\n node deleted successfully.."); 
    return 0;
}