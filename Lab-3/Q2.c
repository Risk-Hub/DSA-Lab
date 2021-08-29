#include <stdio.h>
struct polynomial
{
    int exp, coeff;
};
int main()
{
    struct polynomial arr1[100], arr2[100], arr3[100];
    int i, n1, n2, k = 0, l = 0, m = 0;
    printf("\nEnter the highest degree of first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i <= n1; i++)
    {
        printf("Enter the coefficient of x^%d : ", i);
        scanf("%d", &arr1[i].coeff);
        arr1[k++].exp = i;
    }
    printf("\n\nEnter the highest degree of second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i <= n2; i++)
    {
        printf("Enter the coefficient of x^%d : ", i);
        scanf("%d", &arr2[i].coeff);
        arr2[l++].exp = i;
    }
    if (n1 > n2)
    {
        for (i = 0; i <= n2; i++)
        {
            arr3[m].coeff = arr1[i].coeff + arr2[i].coeff;
            arr3[m].exp = arr1[i].exp;
            m++;
        }
        for (i = n2 + 1; i <= n1; i++)
        {
            arr3[m].coeff = arr1[i].coeff;
            arr3[m].exp = arr1[i].exp;
            m++;
        }
    }
    else
    {
        for (i = 0; i <= n1; i++)
        {
            arr3[m].coeff = arr1[i].coeff + arr2[i].coeff;
            arr3[m].exp = arr1[i].exp;
            m++;
        }
        for (i = n1 + 1; i <= n2; i++)
        {
            arr3[m].coeff = arr2[i].coeff;
            arr3[m].exp = arr2[i].exp;
            m++;
        }
    }
    printf("\nRequired polynomial after addition is =  ");
    for (i = m-1; i >= 1; i--)
    {
        printf("%dx^%d + ", arr3[i].coeff, arr3[i].exp);
    }
    printf("%d",arr3[0].coeff);
}