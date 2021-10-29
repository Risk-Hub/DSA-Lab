#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *q;
struct queue *front = NULL, *rear = NULL;
struct queue *enqueue(struct queue *, int);
struct queue *dequeue(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);
void isEmpty(void);
int main()
{
    int val, choice;
    do
    {
        printf("\n\n****MENU****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number to insert in the queue: ");
            scanf("%d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            val = peek(q);
            if (val != -1)
            {
                printf("The value at front of the queue is: %d", val);
            }
            break;
        case 4:
            q = display(q);
            break;
        }
    } while (choice != 5);
    return 0;
}
struct queue *enqueue(struct queue *q, int val)
{
    struct queue *ptr;
    ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->data = val;
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        front->next = rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
    return q;
}
struct queue *display(struct queue *q)
{
    struct queue *ptr;
    ptr = front;
    if (ptr == NULL)
    {
        isEmpty();
    }
    else
    {
        printf("The value in the queue are: ");
        while (ptr != rear)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }
    return q;
}
struct queue *dequeue(struct queue *q)
{
    struct queue *ptr;
    ptr = front;
    if (front == NULL)
    {
        isEmpty();
    }
    else
    {
        front = front->next;
        printf("The value being deleted is: %d", ptr->data);
        free(ptr);
    }
    return q;
}
int peek(struct queue *q)
{
    if (front == NULL)
    {
        isEmpty();
        return -1;
    }
    else
    {
        return front->data;
    }
}
void isEmpty()
{
    printf("\nQUEUE IS EMPTY");
}