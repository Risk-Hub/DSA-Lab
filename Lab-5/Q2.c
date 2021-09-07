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
struct node *insertBeg(struct node *);
struct node *insertEnd(struct node *);
struct node *insertPos(struct node *);
int main()
{
    int choice;
    printf("\n****MENU****");
    printf("\n1. Create a list");
    printf("\n2. Insert at Beginning");
    printf("\n3. Insert at End");
    printf("\n4. Insert after a value");
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
            start = insertBeg(start);
            break;
        case 3:
            start = insertEnd(start);
            break;
        case 4:
            start = insertPos(start);
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
struct node *insertBeg(struct node *start)
{
    struct node *new_node, *ptr;
    int n;
    printf("\nEnter the data you want to insert(at beginning): ");
    scanf("%d", &n);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    start->prev = new_node;
    new_node->next = start;
    new_node->prev = NULL;
    start = new_node;
    ptr = start;
    printf("\nThe values in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *insertEnd(struct node *start)
{
    struct node *ptr, *new_node, *temp;
    int n;
    printf("\nEnter the data you want to insert(at end): ");
    scanf("%d", &n);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    temp = start;
    printf("\nThe values in the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return start;
}
struct node *insertPos(struct node *start)
{
    struct node *new_node, *ptr;
    int n, val;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &n);
    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = n;
    ptr = start;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = ptr->next;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        new_node->prev = ptr;
    }
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
