#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start1 = NULL, *start2 = NULL;
struct node *createlist(struct node *);
struct node *concatenate(struct node *, struct node *);
int main()
{
    start1 = createlist(start1);
    start2 = createlist(start2);
    concatenate(start1, start2);
    return 0;
}
struct node *createlist(struct node *start)
{
    struct node *new_node, *ptr;
    int n, i = 1;
    char ch;
    printf("\nEnter Y to continue or N to exit: ");
    scanf(" %c", &ch);
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
struct node *concatenate(struct node *start1, struct node *start2)
{
    struct node *ptr;
    ptr = start1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = start2;
    start2->prev = ptr;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr = start1;
    printf("\nThe concatenated list is: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}