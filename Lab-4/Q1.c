#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node display(struct node *);
int main()
{
    struct node *start, *second, *third;
    start = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value of node-1: ");
    scanf("%d", &start->data);
    start->next = second;
    printf("\nEnter the value of node-2: ");
    scanf("%d", &second->data);
    second->next = third;
    printf("\nEnter the value of node-3: ");
    scanf("%d", &third->data);
    third->next = NULL;
    display(start);
}
struct node display(struct node *ptr)
{
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}