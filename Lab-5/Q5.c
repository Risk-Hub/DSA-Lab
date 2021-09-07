#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start1 = NULL, *start2 = NULL;
struct node *createlist(struct node *);
struct node *mergelist(struct node *, struct node *);
int main()
{
    start1 = createlist(start1);
    start2 = createlist(start2);
    mergelist(start1, start2);
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
            new_node->next = NULL;
        }
        printf("\nEnter Y to continue or N to exit: ");
        scanf(" %c", &ch);
        i++;
    }
    return start;
}
struct node *mergelist(struct node *start1, struct node *start2)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start1;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = start2;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1 = start1;
    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    ptr1 = start1;
    printf("\nThe values in the list are: ");
    while (ptr1 != NULL)
    {
        printf("%d ", ptr1->data);
        ptr1 = ptr1->next;
    }
}