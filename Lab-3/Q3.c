#include <stdio.h>
int main()
{
    int i, j, n1, n2;
    int arr1[100], arr2[100], arr3[100];
    printf("\nEnter the highest degree of first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i <= n1; i++)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the highest degree of second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i <= n2; i++)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i <= n1 + n2; i++)
    {
        arr3[i] = 0;
    }
    for (i = 0; i <= n1; i++)
    {
        for (j = 0; j <= n2; j++)
        {
            if (arr1[i] != 0 && arr2[j] != 0)
                arr3[i + j] += arr1[i] * arr2[j];
        }
    }
    printf("\nResultant polynomial after multiplication is = ");
    for (i = n1 + n2; i >= 0; i--)
    {
        if (arr3[i] != 0)
        {
            if (i != 0)
            {
                printf("%dx^%d + ", arr3[i], i);
            }
            else
            {
                printf("%d", arr3[i]);
            }
        }
    }
}