#include <stdio.h>
#include <malloc.h>
struct queue
{
    int data, priority;
    struct queue *next;
};
struct queue *start = NULL;  
struct queue *enqueue(struct queue *);
struct queue *dequeue(struct queue *);
void display(struct queue *);
int main()
{
    int option;
    do
    {
        printf("\n****MENU*****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nChoose an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = enqueue(start);
            break;
        case 2:
            start = dequeue(start);
            break;
        case 3:
            display(start);
            break;
        }
    } while (option != 4);
}
struct queue *enqueue(struct queue *start)
{
    int val, pri;
    struct queue *new_node, *ptr;
    printf("\nEnter the data and its priority resp: ");
    scanf("%d%d", &val, &pri);
    new_node = (struct queue *)malloc(sizeof(struct queue));
    new_node->data = val;
    new_node->priority = pri;
    if (start == NULL || pri < start->priority)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL && ptr->next->priority <= pri)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return start;
}
struct queue *dequeue(struct queue *start)
{
    struct queue *ptr;
    if (start == NULL)
    {
        printf("\nQUEUE UNDERFLOW");
        exit(0);
    }
    else
    {
        ptr = start;
        printf("\nThe deleted elements is: %d", ptr->data);
        start = start->next;
        free(ptr);
    }
    return start;
}
void display(struct queue *start)
{
    struct queue *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nPriority queue is: ");
        while (ptr != NULL)
        {
            printf("%d[priority: %d] ", ptr->data, ptr->priority);
            ptr = ptr->next;
        }
    }
}