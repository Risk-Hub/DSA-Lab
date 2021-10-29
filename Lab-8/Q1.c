#include <stdio.h>
#include <malloc.h>
int queue[100], front = -1, rear = -1;
void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);
void isEmpty(void);
void isFull(void);
int main()
{
    int choice, val;
    do
    {
        printf("\n****MENU****");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            val = dequeue();
            if (val != -1)
            {
                printf("\nThe number deleted is: %d", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("\nThe first value in queue is: %d", val);
            }
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);
    return 0;
}
void enqueue()
{
    int num;
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &num);
    if (rear == 99)
    {
        isFull();
        exit(0);
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}
int dequeue()
{
    int val;
    if (front == -1 || rear == -1)
    {
        isEmpty();
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}
int peek()
{
    if (front == -1 || front > rear)
    {
        isEmpty();
        return -1;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    int i;
    printf("\n");
    if (front == -1 || front > rear)
    {
        isEmpty();
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
void isEmpty()
{
    printf("\nQUEUE IS EMPTY");
}
void isFull()
{
    printf("\nQUEUE IS FULL");
}