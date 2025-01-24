#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *root=NULL;
Node *create(int val) {
    Node *node=(Node*)malloc(sizeof(Node));

    node->data=val;
    node->right=NULL;
    node->left=NULL;

    return node;
}

int max(int n,int m) {
    if(n>m) {
        return n;
    }
    return m;
}

int getHeight(Node *node) {
    if(node==NULL) {
        return -1;
    }
    return node->height;
}

Node *leftRotate(Node *c) {
    Node*p=c->right;
    Node *t=p->left;

    p->left=c;
    c->right=t;

    p->height=max(getHeight(p->left),getHeight(p->right))+1;
    c->height=max(getHeight(c->left),getHeight(c->right))+1;

    return p;
}

Node *rightRotate(Node *p) {
    Node *c=p->left;
    Node *t=c->right;

    c->right=p;
    p->left=t;

    p->height=max(getHeight(p->left),getHeight(p->right))+1;
    c->height=max(getHeight(c->left),getHeight(c->right))+1;
    return c;
}
Node *rotate(Node *node) {

    if(getHeight(node->left)-getHeight(node->right)>1) { //Now tree is a left heavy..
        if(getHeight(node->left->left)-getHeight(node->left->right)>0) { //LL rotation performs.(clockwise)
            return rightRotate(node);//clockwise rotation..
        }

        if(getHeight(node->left->left)-getHeight(node->left->right)<0) { //Else condition for LR rotation
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if(getHeight(node->left)-getHeight(node->right)<-1) { //Now right is a heavy tree...
        if(getHeight(node->right->left)-getHeight(node->right->right)<0) {
            return leftRotate(node);//RR Rotation condition..
        }

        if(getHeight(node->right->left)-getHeight(node->right->right)>0) {
            node->right=rightRotate(node->right);//RL condition.
            return leftRotate(node);
        }
    }
    return node;
}
Node *insertNode(Node *node,int val) {
    if(node==NULL) {
        return create(val);
    }

    if(val<node->data) {
        node->left=insertNode(node->left,val);
    }
    if(val>node->data) {
        node->right=insertNode(node->right,val);
    }

    node->height=max(getHeight(node->left),getHeight(node->right))+1;
    return rotate(node);

}
void insert(int val) {
    root=insertNode(root,val);
}

void displayTree(Node * node,int level) {
    if(node==NULL) {
        return;
    }

    displayTree(node->right,level+1);

    if(level!=0) {
        int i;
        for(i=1; i<level; i++) {
            printf("|\t");
        }

        printf("|----->%d\n",node->data);
    }
    else {
        printf("%d\n",node->data);
    }

    displayTree(node->left,level+1);
}
void display() {
    displayTree(root,0);
}

int main() {

    int i;
    for(i=4; i<40; i+=4) {
        insert(i);
    }
    display();
    return 0;
}