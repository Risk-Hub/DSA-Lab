#include <stdio.h>
int main()
{
    int num, i, c = 0;
    printf("\nEnter a number: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            c++;
        }
    }
    if (c == 2)
    {
        printf("\n%d is a PRIME Number", num);
    }
    else
    {
        printf("%d is not a PRIME Number", num);
    }
}