#include <stdio.h>
#include <stdlib.h>
struct node
{
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
    char ch;
    int i = 1;
    printf("\nEnter Y to continue OR N to exit: ");
    scanf("%c", &ch);
    while (ch == 'Y')
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value in node-%d: ", i);
        scanf("%d", &new_node->data);
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
        printf("\nEnter Y to continue OR N to exit: ");
        scanf(" %c", &ch);
        i++;
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    int large = ptr->data, small = ptr->data;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (ptr->data > large)
        {
            large = ptr->data;
        }
        if (ptr->data < small)
        {
            small = ptr->data;
        }
    }
    printf("\nLargest value is: %d", large);
    printf("\nSmallest value is: %d", small);
}