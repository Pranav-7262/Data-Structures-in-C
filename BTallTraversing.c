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
void preorder(struct node* root) {//creating a function of preorder
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
        

    }
}
void postorder(struct node* root) {//creating a function of preorder
    if(root!=NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);

    }
}
void Inorder(struct node* root) {//creating a function of preorder
    if(root!=NULL)
    {
        
        Inorder(root->left);
        printf("%d",root->data);
        Inorder(root->right);
        

    }
}
int main()
{
    //constructing a root nodes
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);

    //Linking a root nodes to left and right children's.
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    //At last,call the function 
    printf("\n preorder traversing :");
    preorder(p);
    printf("\n");
    printf("\n postorder traversing :");
    postorder(p);
    printf("\n");
    printf("\n Inorder traversing :");
    Inorder(p);
    
    return 0;
}