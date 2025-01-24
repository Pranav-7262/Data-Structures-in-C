#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	int height;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

Node *root=NULL;

Node *create(int val){
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int getHeight(Node *node){
	if(node==NULL){
		return -1;
	}
	return node->height;
}

int max(int n1,int n2){
	if(n1>n2){
		return n1;
	}
	return n2;
}

Node *rightRotate(Node*p){
	Node *c=p->left;
	Node *t=c->right;
	
	c->right=p;
	p->left=t;
	
	p->height=max(getHeight(p->left),getHeight(p->right))+1;
	c->height=max(getHeight(c->left),getHeight(c->right))+1;
	return c;
}

Node *leftRotate(Node*c){

	Node *p=c->right;
	Node *t=p->left;
	
	p->left=c;
	c->right=t;
	
	p->height=max(getHeight(p->left),getHeight(p->right))+1;
	c->height=max(getHeight(c->left),getHeight(c->right))+1;
	return p;
}
Node*rotate(Node *node){
	if(getHeight(node->left)-getHeight(node->right)>1){
		//Left heavy
		if(getHeight(node->left->left)-getHeight(node->left->right)>0){
			//ll
			return rightRotate(node);
		}
		if(getHeight(node->left->left)-getHeight(node->left->right)<0){
			//lr
			node->left=leftRotate(node->left);
			return rightRotate(node);
		}
		
	}
	if(getHeight(node->left)-getHeight(node->right)<-1){
		//right heavy
		
		if(getHeight(node->right->left)-getHeight(node->right->right)<0){
			//rr
			return leftRotate(node);
		}
		
		if(getHeight(node->right->left)-getHeight(node->right->right)>0){
			//rl
			node->right=rightRotate(node->right);
			return leftRotate(node);
		}
		
	}
	return node;
	
}
Node*insertNode(Node*node,int val){
	if(node==NULL){
		return create(val);
	}
	
	if(val<node->data){
		node->left=insertNode(node->left,val);
	}
	
	if(val>node->data){
		node->right=insertNode(node->right,val);
	}
	node->height=max(getHeight(node->left),getHeight(node->right))+1;
	return rotate(node);
}
void insert(int val){
	root=insertNode(root,val);
}

void displayTree(Node *node,int level){
	if(node==NULL){
		return;
	}
	
	displayTree(node->right,level+1);
	if(level!=0){
		int i;
		for(i=1;i<level;i++){
			printf("|\t");
		}
		printf("|---->%d\n",node->data);
	}
	else{
		printf("%d\n",node->data);

	}
	displayTree(node->left,level+1);
}
void display(){
	displayTree(root,0);
}
int main(){
	int i;
	for(i=1;i<=8;i++){
		insert(i);
	}
	display();
	return 0;
}

