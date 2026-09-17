#include <stdio.h>
#include <conio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void pop()
{

    if (top == - 1)
    {
        printf("\nStack Is empty(underflow)\n");
    }
    else
    {
        printf("\ndeletd element= %d ",stack[top]);

        top--;


    }
}

void main()
{
stack[0]=10;
stack[1]=20;
stack[2]=30;
top=2;


    pop();
    pop();
    pop();
    pop();
getch();
}
