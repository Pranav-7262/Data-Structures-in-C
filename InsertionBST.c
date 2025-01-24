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

void insert(struct node* root,int key)
{
    struct node* prev = NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data) {
            printf("%d is not inserted,already in BST",key);
            return;
        }
        else if(key<root->data)
        {
            root = root->left;
        }
        else {
            root = root->right;
        }

    }
    struct node* new = createnode(key);
    if(key<prev->left) {
        prev->left=new;
    }
    else {
        prev->right=new;
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
    insert(p,11);
    printf("\n %d is inserted successfully..",p->right->right->data);

    return 0;
}