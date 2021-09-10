#include <stdio.h>
#include <stdlib.h>
struct node
{
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
    printf("\n****MENU****");
    printf("\n1. Create a List");
    printf("\n2. Insert at Beginning");
    printf("\n3. Insert at End");
    printf("\n4. Insert after a value");
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
            ptr->next = new_node;
            new_node->next = start;
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
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    printf("\nEnter the data to be inserted at beginning: ");
    scanf("%d", &num);
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
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
struct node *insertEnd(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
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
struct node *insertPos(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nOut of memory space");
        exit(0);
    }
    new_node->data = num;
    ptr = start;
    if (ptr->data == val)
    {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    else
    {
        while (ptr->data != val)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
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