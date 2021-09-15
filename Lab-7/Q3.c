#include <stdio.h>
#include <string.h>
int st[100], top = -1;
void push(char);
char pop();
int main()
{
    int i;
    char a[100],c;
    printf("\nEnter the string to be reversed: ");
    scanf("%[^\n]", a);
    for (i = 0; i < strlen(a); i++)
    {
        push(a[i]);
    }
    for (i = 0; i < strlen(a); i++)
    {
        c = pop();
        a[i] = c;
    }
    printf("\nThe reversed string is: ");
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", a[i]);
    }
}
void push(char c)
{
    st[++top] = c;
}
char pop()
{
    return st[top--];
}