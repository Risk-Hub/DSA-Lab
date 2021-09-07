#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *createlist(struct node *);
struct node *display(struct node *);
int main()
{
    start = createlist(start);
    display(start);
    return 0;
}
struct node *createlist(struct node *start)
{
    struct node *new_node, *ptr;
    int n, i = 1;
    char ch;
    printf("\nEnter Y to continue or N to exit: ");
    scanf("%c", &ch);
    while (ch == 'Y')
    {
        printf("\nEnter the data in node-%d: ", i);
        scanf("%d", &n);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = n;
        if (start == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\nEnter Y to continue or N to exit: ");
        scanf(" %c", &ch);
        i++;
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr, *temp;
    ptr = start;
    printf("\nThe values in the list in forward direction are: ");
    while (ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    printf("\nThe values in the list in backward direction are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}