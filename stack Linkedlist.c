#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};

struct Node* top = NULL;
void  linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int data){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node *tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = tp->next;
        int data = n->data;
        free(n);
        return data; 
    } 
}
 
int main(){
    top = push(top,12);
    top = push(top,23);
    top = push(top,25);
    
    int element = pop(top);
    printf("popped element is %d\n",element);
    linkedListTraversal(top);
    
    return 0;
            
            
}
