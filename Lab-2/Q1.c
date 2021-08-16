#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, a[100], c = 0, i;
    int *ptr;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the elements in the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int max = ptr[0];
    for (i = 0; i < n; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
            c = 1;
        }
        else if (ptr[i] == max)
        {
            c++;
        }
    }
    printf("\nThe largest number is %d and it has occured %d times in the array.", max, c);
    free(ptr);
}