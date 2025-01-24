#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct node*right;
};
typedef struct node node;
node*root=NULL;
node*insert(node*tree,int data);
void preorder(node*tree);
void inorder(node*tree);
void postorder(node*tree);
int main(){
	int ch;
	int digit;
	
	do {
		puts("\n 1.Enter for inserting a node:");
		puts("\n 2.Display (preorer traversal)");
		puts("\n 3.Display (inorder traversal)");
		puts("\n 4.Display (postorder traversal)");
		puts("\n 5.exit(0)");
		puts("\n Enter a choice:");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
		
			puts("\nEnter integer to insert node");
			scanf("%d",&digit);
			while(digit!=0){
				root=insert(root,digit);
				break;
				
			case 2:
			  puts("\nDisplay preorder:");
			  preorder(root);
			  break;
			  case 3:
			  puts("\nDisplay inorder:");
			  inorder(root);
			  break;
			  case 4:
			  puts("\nDisplay postorder:");
			  postorder(root);
			  break;
			  case 5:
			  puts("\nexit(0)");
			  break;								
			}
		}
	}
	while(ch!=5);
	return 0;
}
node*insert(node*p,int data){
	if(p==NULL){
		p=(node*)malloc(sizeof(node));
		if(p==NULL){
			printf("\nmemory allocation failed!!");
			exit(1);
		}
		p->left=NULL;
		p->right=NULL;
		p->data=data;
	}
	else{
		if(data<p->data){
			p->left=insert(p->left,data);
		}
		else{
			p->right=insert(p->right,data);
		}
	}
	return p;
}
void preorder(node*p){
	if(p!=NULL){
		printf("\n%d",p->data);
		preorder(p->left);
		preorder(p->right);
		
		
	}
}
void inorder(node*p){
	if(p!=NULL){
		
		inorder(p->left);
		printf("\n%d",p->data);
		inorder(p->right);
		
		
	}
}
void postorder(node*p){
	if(p!=NULL){
		
		postorder(p->left);
		postorder(p->right);
		printf("\n%d",p->data);
		
		
	}
}
