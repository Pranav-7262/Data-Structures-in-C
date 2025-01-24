#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

Node* create(int val){
	Node * node=(Node*)malloc(sizeof(Node));
	node->data=val;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}

Node *root=NULL;

void displayTree(Node * node,int level){
	if(node==NULL){
		return;
	}
	
	displayTree(node->right,level+1);
	
	if(level!=0){
		int i;
		for(i=1;i<level;i++){
			printf("|\t");
		}
		
		printf("|----->%d\n",node->data);
	}
	else{
		printf("%d\n",node->data);
	}
	
	displayTree(node->left,level+1);
}

void display(){
	displayTree(root,0);
}

Node *insertBST(Node *node,int val){
	if(node==NULL){
		return create(val);
	}
	
	if(val<node->data){
		node->left=insertBST(node->left,val);
	}
	
	if(val>node->data){
		node->right=insertBST(node->right,val);
	}
	
	return node;
}

void insert(int val){
	root=insertBST(root,val);
}

void insertArray(int nums[],int start,int last){
	if(start>=last){
		return;
	}
	
	int mid=(start+last)/2;
	
	insert(nums[mid]);
	
	insertArray(nums,start,mid);
	insertArray(nums,mid+1,last);
	
}

int main(){
	
	int i;
	for(i=4;i<40;i=i+4){
		insert(i);
	}
    
	//int nums[10]={4,8,12,16,20,24,28,32,36,40};
 	//insertArray(nums,0,10);
	
	display();
}