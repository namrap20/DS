//Write a program to perform following operation on singly linked list:
//a. delete first node
//b. delete last node
//c. delete specific node
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// a. Delete first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted first node with value: %d\n", temp->data);
    free(temp);
}

// b. Delete last node
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    if (temp->next == NULL) {
        printf("Deleted last node with value: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted last node with value: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// c. Delete specific node by value
void deleteSpecific(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If key is at the head node
    if (temp->data == key) {
        *head = temp->next;
        printf("Deleted node with value: %d\n", key);
        free(temp);
        return;
    }

    // Traverse to find the key
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with value: %d\n", key);
    free(temp);
}

// Function to display list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    displayList(head);

    deleteFirst(&head);
    displayList(head);

    deleteLast(&head);
    displayList(head);

    deleteSpecific(&head, 20);
    displayList(head);

    return 0;
}