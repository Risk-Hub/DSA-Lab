#include <stdio.h>
struct employee
{
    float hra, da, gPay, bPay;
    char name[50], gender, post[50];
};
int main()
{
    int n, i;
    printf("\nEnter the number of employees: ");
    scanf("%d", &n);
    struct employee e[n];
    printf("\nEnter the details of the employee:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\nFor employee-%d", i + 1);
        printf("\n Enter Name: ");
        scanf(" %[^\n]", e[i].name);
        printf(" Enter Gender: ");
        scanf(" %c", &e[i].gender);
        printf(" Enter Designation: ");
        scanf(" %[^\n]", e[i].post);
        printf(" Enter Basic Pay: ");
        scanf("%f", &e[i].bPay);
    }
    printf("\nEmployee details are as follows:-\n");
    for (i = 0; i < n; i++)
    {
        printf("\nFor employee-%d", i + 1);
        printf("\n Name: %s", e[i].name);
        printf("\n Gender: %c", e[i].gender);
        printf("\n Basic Pay: %.2f", e[i].bPay);
        e[i].hra = 0.25 * e[i].bPay;
        e[i].da = 0.75 * e[i].bPay;
        e[i].gPay = e[i].bPay + e[i].hra + e[i].da;
        printf("\n HRA: %.2f", e[i].hra);
        printf("\n DA: %.2f", e[i].da);
        printf("\n Gross Pay: %.2f", e[i].gPay);
    }
}