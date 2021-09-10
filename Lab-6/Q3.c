#include <stdio.h>
#include <stdlib.h>
struct node
{
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
    printf("\n****MENU****");
    printf("\n1. Create a list");
    printf("\n2. Delete from Beginning");
    printf("\n3. Delete from End");
    printf("\n4. Delete from a particular position");
    printf("\n5. EXIT");
    int choice;
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
}
struct node *createlist(struct node *start)
{
    struct node *new_node, *ptr;
    int num, i = 1;
    char ch;
    printf("\nEnter Y to continue or N to exit: ");
    scanf(" %c", &ch);
    while (ch == 'Y')
    {
        printf("\nEnter the data in node-%d: ", i);
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
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
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr->next != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    return start;
}
struct node *deleteEnd(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    ptr = start;
    printf("\nValues in the list are: ");
    while (ptr->next != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
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
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = start->next;
        free(start);
        start = ptr->next;
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
    while (ptr->next != start)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    return start;
}