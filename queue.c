#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int enqueue(int, int, int[]);
int dequeue(int, int, int[]);
void display(int, int, int[]);
// LIMITATION: UNUSED MEMORY SPACE LEFT OF THE DELETED DATA.
// DRAWBACK: fixed size of array so need to know the size of data before implementing QUEUE.
int main()
{
    int arr[SIZE];
    // increase rear when inserting and increase front when dequeue
    int front = -1;
    int rear = -1;
    int ch;
    do
    {
        printf("\nEnter your choice: \n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            rear = enqueue(rear, front, arr);
            if (front == -1)
            {
                front = 0;
            }

            break;
        }

        case 2:
        {
            front = dequeue(front, rear, arr);

            if (front > rear)
            {
                front = -1;
                rear = -1;
            }

            break;
        }

        case 3:
            display(front, rear, arr);
            break;

        default:
            exit(0);
            break;
        }

    } while (ch < 4);

    return 0;
}

int enqueue(int rear, int front, int arr[])
{
    if (rear == SIZE - 1)
    {
        printf("QUEUE is Full");
    }
    else
    {
        rear++;
        printf("\nEnter the data: ");
        scanf("%d", &arr[rear]);
        printf("\nData inserted Successfully");
    }
    return rear;
}

int dequeue(int front, int rear, int arr[])
{
    if (front == -1)
    {
        printf("\nQueue is EMPTY!");
    }
    else
    {
        printf("\nPopped value is: %d", arr[front]);
        front++;
    }

    return front;
}

void display(int front, int rear, int arr[])
{
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nPrinting Data in Queue:");

    do
    {
        printf("\n%d", arr[front]);
        front++;

    } while (front != rear + 1);
}