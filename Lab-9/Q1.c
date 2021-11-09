#include <stdio.h>
int main()
{
    int a[100], num, n, count = 0;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements in the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nEnter the number to be searched: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            count++;
            printf("\n%d is found in the array at position: %d", num, i + 1);
            break;
        }
    }
    if (!count)
    {
        printf("\n%d is not found in the array", num);
    }
}