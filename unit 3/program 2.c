// Write a program to perform following operation on singly linked list:  
//a. insert a node at the starting of the list  
//b. insert a node at the end of the list 
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// a. Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    // Link the new node to point to current head
    newNode->next = *head;
    
    // Update head pointer to the new node
    *head = newNode;
    
    printf("Inserted %d at the beginning.\n", value);
}

// b. Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    // If list is empty, new node becomes the head
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Attach new node at the end
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting nodes at the end
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display current list
    displayList(head);

    // Inserting nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);

    // Display list after insertions
    displayList(head);

    // Inserting another node at the end
    insertAtEnd(&head, 40);

    // Final display
    displayList(head);

    return 0;
}