#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void input(int [][3]);
void output(int [][3]);
void add(int [][3], int [][3], int [][3]);
void main()
{
    int arr1[MAX][3], arr2[MAX][3], arr3[MAX][3];
    input(arr1);
    input(arr2);
    add(arr1, arr2, arr3);
    output(arr3);
}
void input(int arr[MAX][3])
{
    int i, t, m, n;
    printf("\nEnter no.of rows and columns: ");
    scanf("%d%d", &m, &n);
    printf("Enter the no.of non-zero triplets: ");
    scanf("%d", &t);
    arr[0][0] = m;
    arr[0][1] = n;
    arr[0][2] = t;
    for (i = 1; i <= t; i++)
    {
        printf("Enter the triplet-%d (row, column, value): ", i);
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
}
void add(int arr1[MAX][3], int arr2[MAX][3], int arr3[MAX][3])
{
    int t1, t2, i, j, k;
    if (arr1[0][0] != arr2[0][0] || arr1[0][1] != arr2[0][1])
    {
        printf("\nYou have entered invalid matrix !!Size must be equal");
        exit(0);
    }
    t1 = arr1[0][2];
    t2 = arr2[0][2];
    i = j = k = 0;
    arr3[0][0] = arr1[0][0];
    arr3[0][1] = arr1[0][1];
    while (i <= t1 && j <= t2)
    {
        if (arr1[i][0] < arr2[j][0])
        {
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k][2] = arr1[i][2];
            k++;
            i++;
        }
        else if (arr2[j][0] < arr1[i][0])
        {
            arr3[k][0] = arr2[j][0];
            arr3[k][1] = arr2[j][1];
            arr3[k][2] = arr2[j][2];
            k++;
            j++;
        }
        else if (arr1[i][1] < arr2[j][1])
        {
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k][2] = arr1[i][2];
            k++;
            i++;
        }
        else if (arr2[j][1] < arr1[i][1])
        {
            arr3[k][0] = arr2[j][0];
            arr3[k][1] = arr2[j][1];
            arr3[k][2] = arr2[j][2];
            k++;
            j++;
        }
        else
        {
            arr3[k][0] = arr1[i][0];
            arr3[k][1] = arr1[i][1];
            arr3[k][2] = arr1[i][2] + arr2[j][2];
            k++;
            i++;
            j++;
        }
    }
    while (i <= t1)
    {
        arr3[k][0] = arr1[i][0];
        arr3[k][1] = arr1[i][1];
        arr3[k][2] = arr1[i][2];
        i++;
        k++;
    }
    while (j <= t2)
    {
        arr3[k][0] = arr2[j][0];
        arr3[k][1] = arr1[j][1];
        arr3[k][2] = arr1[j][2];
        j++;
        k++;
    }
    arr3[0][2] = k - 1;
}
void output(int arr[MAX][3])
{
    int i, t;
    t = arr[0][2];
    printf("\nAfter triplet addition:-\n");
    printf("\nRow\tColumn\tValue");
    for (i = 1; i <= t; i++)
    {
        printf("\n%d\t %d\t %d", arr[i][0], arr[i][1], arr[i][2]);
    }
}