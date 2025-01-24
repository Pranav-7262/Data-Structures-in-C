#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL; // Initialize top to NULL

void push(int n) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return; // Check for memory allocation failure
    }
    newnode->data = n;
    newnode->next = top;
    top = newnode; // Update top to the new node
    printf("%d pushed onto stack\n", n);
}

void pop() {
    if (top == NULL) { // Check if stack is empty
        printf("\nUnderflow\n");
        return;
    }

    struct node* temp = top; // Temporary node to hold the top
    int item = temp->data;   // Get data from top node
    top = top->next;         // Move top to the next node
    free(temp);              // Free the memory of the old top
    printf("%d popped from stack\n", item);
}

int main() {
    push(23);
    push(56);
    push(79);
    
    // Call pop function only once
    printf("\n After poping : \n");
    pop();
    // This should display the popped value
    
    return 0;
}