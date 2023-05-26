#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    struct queue *next;
    int data;

} queue;


int main()
{

    queue *start = NULL;
    queue *end = NULL;

    int ch = 0;

    while (ch < 4)
    {
        printf("\nEnter your choice :\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            
            break;
        }

        case 2:
        {
            
            break;
        }
        case 3:
        {
            
            break;
        }
        
        default:
            exit(0);
        }
    }
}