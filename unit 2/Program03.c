//program for peek
#include<stdio.h>
#include<conio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int value)
{
    if (top == MAX - 1)
    printf("\n Stack overflow");
    else
    {
        top++;
        stack[top] = value;
    }
}

void peek()
{
    if(top == -1)
        printf("\nStack Underflow");
        else
        printf("\nTop Element = %d", stack[top]);
}
void main()
{
    push(10);
    push(20);
    push(30);

    peek();

    getch();
}
