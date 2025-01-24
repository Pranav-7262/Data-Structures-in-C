#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the sum of leaf nodes
int sumOfLeafNodes(struct Node* root) {
    // Base case: if the node is NULL, return 0
    if (root == NULL) {
        return 0;
    }
    
    // If the node is a leaf node, return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    else {
    
    // Recur for left and right subtrees and return the sum
    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}
}

int main() {
    // Creating a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    // Calculate the sum of leaf nodes
    int sum = sumOfLeafNodes(root);
    printf("Sum of leaf nodes: %d\n", sum);

    // Free allocated memory (not shown here for simplicity)
    
    return 0;
}