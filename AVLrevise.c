#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct node*left;
    struct node*right;
};
typedef struct Node Node;
Node*root = NULL;
Node*create(int val) {

    Node*node=(Node*)malloc(sizeof(Node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;

}

void max(int n,int m){
  if(n>m){
    return n;
  }
  return m;
 
 }
 void getheight(Node *node){
  if(node==NULL){
    return -1;
  }
  return node->height;
 } 
 void rotate()
 
//Node*root=NULL;

void displayTree(Node* node,int level) {
    if(node==NULL) {
        return;
    }
    displayTree(node->right,level+1);
    if(level!=0) {
        int i;
        for(i=1; i<level; i++) {

            printf("|\t");
        }
        printf(" ----->%d\n",node->data);

    }
    else {
        printf("%d\n",node->data);
    }

    displayTree(node->left,level+1);

}

display() {
    displayTree(root,0);
}
//Node*root=NULL;
Node *insertBST(Node *node,int val) {
    if(node==NULL) {
        return create(val);
    }
    if(val<node->data) {
        node->left = insertBST(node->left,val);
    }
    if(val>node->data) {
        node->right=insertBST(node->right,val);
    }
    return rotate(node);

}
void insert(int val)
{
    root = insertBST(root,val);
}
void insertarray(int nums[],int start,int end) {

    if(start>=end)
    {
        return;
    }
    int mid = (start+end)/2;
    insert(nums[mid]);
    insertarray(nums,start,mid);
    insertarray(nums,mid+1,end);

}
int main() {

   // int i;
    //for(i=4; i<=20; i=i+4) {
   //     insert(i);
    //}
    //
    
    int nums[5] = {1,2,3,4,5};
     insertarray(nums,0,5);
    display();

}