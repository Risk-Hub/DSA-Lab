#include <stdio.h>
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
            enqueue();
            break;
        case 2:
            val = dequeue();
            if (val != -1)
            {
                printf("\nThe deleted element is: %d", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("\nThe first element in queue is: %d", val);
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
    printf("\nEnter the number you want to insert: ");
    scanf("%d", &num);
    if (front == 0 && rear == 99)
    {
        isFull();
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}
int dequeue()
{
    int val;
    if (front == -1 && rear == -1)
    {
        isEmpty();
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == 99)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}
int peek()
{
    if (front == -1 && rear == -1)
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
    if (front == -1 && rear == -1)
    {
        isEmpty();
    }
    else
    {
        printf("The elements in the queue are: ");
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < 100; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
    }
}
void isEmpty(void)
{
    printf("\nQUEUE IS EMPTY");
}
void isFull(void)
{
    printf("\nQUEUE IS FULL");
}