// Write a program to create a binary tree . Traverse tree in preorder ,  postorder and inorder. 
#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the Binary Tree interactively
struct Node* createTree() {
    int data;
    printf("Enter data (-1 for no node/NULL): ");
    scanf("%d", &data);

    // Base condition: -1 represents a NULL link (no node)
    if (data == -1) {
        return NULL;
    }

    // Create the root node
    struct Node* root = createNode(data);

    // Recursively construct left and right subtrees
    printf("Enter left child of %d:\n", data);
    root->left = createTree();

    printf("Enter right child of %d:\n", data);
    root->right = createTree();

    return root;
}

// 1. Preorder Traversal: Root -> Left -> Right
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 2. Inorder Traversal: Left -> Root -> Right
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 3. Postorder Traversal: Left -> Right -> Root
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;

    printf("--- Create Binary Tree ---\n");
    root = createTree();

    printf("\n--- Tree Traversals ---\n");

    printf("Preorder Traversal  : ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal   : ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}