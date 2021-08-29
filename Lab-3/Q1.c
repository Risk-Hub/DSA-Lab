#include <stdio.h>
struct polynomial
{
    int exp, coeff;
};
int main()
{
    struct polynomial arr[100];
    int i, n, j = 0;
    printf("\nEnter the highest degree of the polynomial: ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        printf("\nEnter the coefficient of x^%d : ", i);
        scanf("%d", &arr[i].coeff);
        arr[j++].exp = i;
    }
    printf("\nRequired polynomial is: ");
    for (i = n; i >= 1; i--)
    {
        printf("%dx^%d + ", arr[i].coeff, arr[i].exp);
    }
    printf("%d", arr[0].coeff);
}