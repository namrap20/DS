//Write a program to perform following operation on Doubly linked list:
//a. Create a linked list
//b. Display it
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// a. Create a doubly linked list with n nodes
struct Node* createDoublyList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    if (n <= 0) return NULL;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

// b. Display the doubly linked list
void displayDoublyList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createDoublyList(n);
    displayDoublyList(head);

    return 0;
}