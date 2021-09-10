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
    int num, i = 1;
    char ch;
    printf("\nEnter Y to continue or N to exit: ");
    scanf("%c", &ch);
    while (ch == 'Y')
    {
        printf("\nEnter the data in node-%d: ", i);
        scanf("%d", &num);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL)
        {
            start = (struct node *)malloc(sizeof(struct node));
            start->next = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("\nEnter Y to continue or N to exit: ");
        scanf(" %c", &ch);
        i++;
    }
    start->data = i - 1;
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start->next;
    printf("\nValue stored in the header node: %d", start->data);
    printf("\nValues in the list are: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}