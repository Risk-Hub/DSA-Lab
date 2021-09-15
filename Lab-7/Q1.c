#include <stdio.h>
int st[100], top = -1;
int check();
void push(int[], int);
int pop(int[]);
void display(int[]);
int main()
{
    printf("\n****MENU*****");
    printf("\n1. Check if the stack is empty OR not");
    printf("\n2. PUSH");
    printf("\n3. POP");
    printf("\n4. DISPLAY");
    printf("\n5. EXIT");
    int choice, num;
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int temp = check();
            if (temp == -1)
            {
                printf("\nSTACK IS EMPTY");
            }
            else
            {
                printf("\nSTACK IS NOT EMPTY");
            }
            break;
        case 2:
            printf("\nEnter the data to be pushed on stack: ");
            scanf("%d", &num);
            push(st, num);
            break;
        case 3:
            num = pop(st);
            if (num != -1)
            {
                printf("\nThe value deleted from the stack is: %d", num);
            }
            break;
        case 4:
            display(st);
            break;
        case 5:
            printf("\nEXIT");
            break;
        }
    } while (choice != 5);
}
int check()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void push(int st[], int num)
{
    if (top == 99)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        st[++top] = num;
    }
}
int pop(int st[])
{
    int val;
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        val = st[top--];
        return val;
    }
}
void display(int st[])
{
    if (top == -1)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        printf("\nValues in the stack are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", st[i]);
        }
    }
}