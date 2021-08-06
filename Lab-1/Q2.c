#include <stdio.h>
int power(int, int);
int main()
{
    int x, y, multi = 1;
    printf("\nEnter the value of x and y: ");
    scanf("%d%d", &x, &y);
    printf("\nx^y is %d", power(x, y));
}
int power(int x, int y)
{
    int multi = 1;
    for (int i = 0; i < y; i++)
    {
        multi *= x;
    }
    return multi;
}