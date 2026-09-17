#include <stdio.h>
#include <conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int item;
    if (top == MAX - 1)
    {
        printf("\nStack Is Full (overflow)\n");
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;

        printf("\n%d inserted successfully.\n", item);
    }
}

void main()
{

    push();
    push();
    push();
    push();
    push();
getch();
}
