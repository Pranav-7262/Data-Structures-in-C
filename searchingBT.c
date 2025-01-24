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

// Function to insert a new node in the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    
    // For simplicity, we insert nodes in a level order manner
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to search for a value in the binary tree
int search(struct Node* root, int value) {
    // Base case: if the tree is empty or value is found
    if (root == NULL) {
        return 0; // Value not found
    }
    if (root->data == value) {
        return 1; // Value found
    }
    
    // Recur for left and right subtrees
    return search(root->left, value) || search(root->right, value);
}

// Function for inorder traversal (for display purposes)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    // Searching for a value
    int valueToSearch = 40;
    if (search(root, valueToSearch)) {
        printf("Value %d found in the tree.\n", valueToSearch);
    } else {
        printf("Value %d not found in the tree.\n", valueToSearch);
    }

    valueToSearch = 90;
    if (search(root, valueToSearch)) {
        printf("Value %d found in the tree.\n", valueToSearch);
    } else {
        printf("Value %d not found in the tree.\n", valueToSearch);
    }

    // Free allocated memory (not shown here for simplicity)

    return 0;
}