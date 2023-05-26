#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

int push(int, int[]);
int pop(int, int[]);
void display(int, int[]);

int main()
{
    int arr[SIZE];
    int top = -1;
    int ch;
    do
    {
        printf("\nEnter your choice: \n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(top, arr);
            break;

        case 2:
            top = pop(top, arr);
            break;

        case 3:
            display(top, arr);
            break;

        default:
            exit(0);
            break;
        }

    } while (ch < 4);

    return 0;
}

int push(int top, int arr[])
{
    if (top == SIZE - 1)
    {
        printf("Stack is Full");
    }
    else
    {
        top++;
        printf("\nEnter the data: ");
        scanf("%d", &arr[top]);
        printf("\nData inserted Successfully");
    }
    return top;
}

int pop(int top, int arr[])
{
    if (top == -1)
    {
        printf("\nStack is EMPTY!");
    }
    else
    {
        printf("\nPopped value is: %d", arr[top]);
        top--;
    }
    return top;
}

void display(int top, int arr[])
{
    if (top == -1)
    {
        printf("\nSTACK is empty!");
        return;
    }

    printf("\nPrinting Data in Stack:");

    while (top >= 0)
    {
        printf("\n%d", arr[top]);
        top--;
    }
}