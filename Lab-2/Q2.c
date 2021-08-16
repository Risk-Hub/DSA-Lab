#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, nge;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("\nEnter the elements in the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nElement \t\tNext Greater Element(NGE)\n");
    for (i = 0; i < n; i++)
    {
        nge = -1;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                nge = a[j];
                break;
            }
        }
        printf("   %d \t\t\t\t%2d \n", a[i], nge);
    }
}