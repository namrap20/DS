//Write a program to perform following operation on singly linked list:  
//a. insert a node after the specific node  
//b. insert a node before the specific node.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// a. Insert a node AFTER a specific target value
void insertAfter(struct Node* head, int target, int newValue) {
    struct Node* temp = head;

    // Traverse to find the target node
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    // If target is not found
    if (temp == NULL) {
        printf("Target element %d not found in the list.\n", target);
        return;
    }

    // Insert new node after target node
    struct Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d AFTER %d.\n", newValue, target);
}

// b. Insert a node BEFORE a specific target value
void insertBefore(struct Node** head, int target, int newValue) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Special Case: If target is the head node, update head
    if ((*head)->data == target) {
        struct Node* newNode = createNode(newValue);
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d BEFORE %d (at the head).\n", newValue, target);
        return;
    }

    struct Node* temp = *head;

    // Traverse to find the node BEFORE target node
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    // If target is not found
    if (temp->next == NULL) {
        printf("Target element %d not found in the list.\n", target);
        return;
    }

    // Insert new node before target node
    struct Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d BEFORE %d.\n", newValue, target);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Manually initializing a sample list: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    displayList(head);

    // a. Insert AFTER a specific node
    insertAfter(head, 20, 25); // Insert 25 after 20
    displayList(head);

    // b. Insert BEFORE a specific node
    insertBefore(&head, 20, 15); // Insert 15 before 20
    displayList(head);

    // Testing insertion before the head node
    insertBefore(&head, 10, 5);  // Insert 5 before 10
    displayList(head);

    return 0;
}