//Write a program to perform following operation on Doubly linked list:
//a. delete first node
//b. delete last node
//c. delete specific node
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

// a. Delete first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

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

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    printf("Deleted last node with value: %d\n", temp->data);
    free(temp);
}

// c. Delete specific node
void deleteSpecific(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list.\n", key);
        return;
    }

    if (temp == *head) {
        deleteFirst(head);
        return;
    }

    if (temp->next == NULL) {
        deleteLast(head);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);

    head->next = n2; n2->prev = head;
    n2->next = n3;   n3->prev = n2;
    n3->next = n4;   n4->prev = n3;

    displayList(head);

    deleteFirst(&head);
    displayList(head);

    deleteLast(&head);
    displayList(head);

    deleteSpecific(&head, 20);
    displayList(head);

    return 0;
}