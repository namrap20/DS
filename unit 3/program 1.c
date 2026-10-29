// Write a program to perform following operation on singly linked list:  
//a. Create a linked list  
//b. Display it  
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list with 'n' nodes
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    if (n <= 0) {
        return NULL;
    }

    for (i = 1; i <= n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return head;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            // First node becomes the head
            head = newNode;
            temp = head;
        } else {
            // Link the previous node to the new node
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nLinked List Elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // a. Create linked list
    head = createList(n);

    // b. Display linked list
    displayList(head);

    return 0;
}