#include <stdio.h>
#include <stdlib.h>

typedef struct clist
{
    struct clist *next;
    int data;
    int position;

} clist;

clist *insert(clist *, clist *, int);
void display(clist *, clist *);
clist *process(clist *, clist *, int);
int setQuantum(int);

int main()
{

    clist *head = NULL;
    clist *end = NULL;
    int ch = 0;
    int processCount = 0;
    int quantum = 10;
    while (ch < 5)
    {
        printf("\nEnter your choice :\n1.Add new process\n2.List all Processes\n3.Start Processing\n4.Change CPU Quantum(currently is %d)\n", quantum);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            processCount++;
            printf("\n Enter the Values for Process P%d \n", processCount);
            end = insert(head, end, processCount);
            if (end->next == end)
            {
                head = end;
            }
            break;
        }

        case 2:
        {
            display(head, end);
            break;
        }
        case 3:
        {
            head = process(head, end, quantum);
            break;
        }
        case 4:
        {
            quantum = setQuantum(quantum);
            break;
        }
        default:
            exit(0);
        }
    }
}

clist *insert(clist *head, clist *end, int position)
{

    clist *Node = (clist *)malloc(sizeof(clist));
    if (Node != NULL)
    {
        printf("\nEnter CPU burst of the Process\n");
        int x;
        scanf("%d", &x);
        Node->data = x;
        Node->position = position;
        if (head == NULL)
        {
            // Adding First Process
            Node->next = Node;
        }
        else
        {
            // If Process already exist
            end->next = Node;
            Node->next = head;
        }
        end = Node;
        printf("\nProcess successfully Added\n");
    }

    return end;
}

void display(clist *head, clist *end)
{

    if (head == NULL)
    {

        printf("\nNo process is Added!\n");
    }
    else
    {
        clist *temp = head;
        while (head != NULL)
        {
            printf("\nProcess P%d CPU Burst %d", head->position, head->data);
            head = head->next;
            if (head == temp)
                head = NULL;
        }
    }
}
clist *process(clist *head, clist *end, int quantum)
{
    int timer = 0;
    printf("\n**************Starting the Process***********\n");
    // Start processing until all Process completes and head becomes NULL.
    clist *prev = head;
    clist *temp = head;
    while (head != NULL)
    {
        // if the current process is completed than skip otherwise run the current process.
        if (head->data >= quantum)
        {
            head->data = head->data - quantum;
            timer = timer + 1;

            if (head->data <= 0)
            {
                printf("\nProcess P%d is completed at %d ms.", head->position, timer * quantum);

                // If that process is the last process left!
                if (head->next == head)
                {
                    head = NULL;
                }
                else if (head != temp && head != end)
                {
                    prev->next = head->next;
                }
                else if (head == end)
                {
                    end = prev;
                    end->next = temp;
                }
                else if (head == temp)
                {
                    end->next = head->next;
                }
            }
        }

        prev = head;
        head = head->next;
    }

    return head;
}

int setQuantum(int quantum)
{
    printf("\nEnter the Quantum for Processes: ");
    scanf("%d", &quantum);
    printf("\nNew Quantumm for Processes is: %d", quantum);
    return quantum;
}
