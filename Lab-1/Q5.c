#include <stdio.h>
int main()
{
    int a, *p;
    printf("\nEnter the value of a: ");
    scanf("%d", &a);
    p = &a;
    printf("\nThe inputted number is: %d", *p);
}