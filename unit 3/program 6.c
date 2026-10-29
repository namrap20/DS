//Write a program to perform following operation on Doubly linked list:
//a. insert a node at the starting of the list
//b. insert a node at the end of the list
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

// a. Insert node at the starting of the list
void insertAtStarting(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
    printf("Inserted %d at starting.\n", value);
}

// b. Insert node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at end.\n", value);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", value);
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
    struct Node* head = NULL;

    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    displayList(head);

    insertAtStarting(&head, 10);
    displayList(head);

    return 0;
}