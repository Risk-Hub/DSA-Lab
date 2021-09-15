#include <stdio.h>
int st[100], top = -1, count = 0;
int binary(int);
void push(int);
int pop();
int main()
{
    int n, temp, c, a[100];
    printf("\nEnter the decimal number: ");
    scanf("%d", &n);
    temp = binary(n);
    for (int i = 0; i < count; i++)
    {
        c = pop();
        a[i] = c;
    }
    printf("\nThe resultant binary number is: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }
}
int binary(int n)
{
    int b[100];
    while (n)
    {
        b[count] = n % 2;
        n /= 2;
        count++;
    }
    for (int j = 0; j < count; j++)
    {
        int temp = b[j];
        push(temp);
    }
}
void push(int temp)
{
    if (top == 99)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        st[++top] = temp;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        return st[top--];
    }
}