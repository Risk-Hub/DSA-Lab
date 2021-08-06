#include <stdio.h>
int main()
{
    int a, b, *p1, *p2;
    printf("\nEnter two numbers a and b: ");
    scanf("%d%d", &a, &b);
    p1 = &a;
    p2 = &b;
    printf("\nThe sum of %d and %d is %d", *p1, *p2, *p1 + *p2);
}