#include <stdio.h>
void swap(int *, int *);
int main(void)
{
    int a, b, *p1, *p2;
    printf("\nEnter two numbers a: ");
    scanf("%d", &a);
    printf("\nEnter two numbers b: ");
    scanf("%d", &b);
    p1 = &a;
    p2 = &b;
    swap(p1, p2);
}
void swap(int *p1, int *p2)
{
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
    printf("\nAfter swapping, a = %d and b = %d", *p1, *p2);
}