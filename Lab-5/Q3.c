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
struct node *deleteBeg(struct node *);
struct node *deleteEnd(struct node *);
struct node *deletePos(struct node *);
int main()
{
    int choice;
    printf("\n****MENU****");
    printf("\n1. Create a list");
    printf("\n2. Delete at Beginning");
    printf("\n3. Delete at End");
    printf("\n4. Delete a specific node");
    printf("\n5. EXIT");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = createlist(start);
            break;
        case 2:
            start = deleteBeg(start);
            break;
        case 3:
            start = deleteEnd(start);
            break;
        case 4:
            start = deletePos(start);
            break;
        case 5:
            printf("\nEXIT");
            break;
        }
    } while (choice != 5);
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
struct node *deleteBeg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    ptr = start;
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *deleteEnd(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    ptr = start;
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *deletePos(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value of the node to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = ptr->next;
        free(ptr);
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}