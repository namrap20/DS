//Write  a program to perform following operations on Binary search tree:  
//a. insert delete  
//b. height of the tree  
//c. total no. of nodes in the tree  
#include <stdio.h>
#include <stdlib.h>

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

// Helper function to find the minimum value node (in-order successor)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// a. Insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value %d ignored.\n", value);
    }

    return root;
}

// a. Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        printf("Value %d not found in tree.\n", key);
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found with 0 or 1 child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with 2 children: get in-order successor (smallest in right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// b. Calculate height of the tree
int getHeight(struct Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1 (edges count) or 0 if counting nodes
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// c. Calculate total number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to display tree in-order (sorted)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // a. Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    // c. Count total nodes
    printf("Total number of nodes: %d\n", countNodes(root));

    // b. Height of the tree
    printf("Height of the tree: %d\n", getHeight(root));

    // a. Deleting a node
    printf("\nDeleting node 20...\n");
    root = deleteNode(root, 20);
    
    printf("Deleting node 50 (Root with two children)...\n");
    root = deleteNode(root, 50);

    printf("\nIn-order Traversal after deletions: ");
    inorder(root);
    printf("\n");

    printf("Total number of nodes after deletion: %d\n", countNodes(root));
    printf("Height of the tree after deletion: %d\n", getHeight(root));

    return 0;
} 