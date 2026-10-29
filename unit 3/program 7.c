//Write a program to perform following operation on Doubly linked list:
//a. insert a node after the specific node
//b. insert a node before the specific node
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a. Insert node AFTER a specific target node
void insertAfter(struct Node* head, int target, int newValue) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target %d not found.\n", target);
        return;
    }

    struct Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    printf("Inserted %d AFTER %d.\n", newValue, target);
}

// b. Insert node BEFORE a specific target node
void insertBefore(struct Node** head, int target, int newValue) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target %d not found.\n", target);
        return;
    }

    struct Node* newNode = createNode(newValue);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode; // Updating head if inserted before first node
    }
    temp->prev = newNode;

    printf("Inserted %d BEFORE %d.\n", newValue, target);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(30);
    head->next->prev = head;

    displayList(head);

    insertAfter(head, 10, 20);  // Insert 20 after 10
    displayList(head);

    insertBefore(&head, 30, 25); // Insert 25 before 30
    displayList(head);

    return 0;
}