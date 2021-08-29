#include <stdio.h>
#define MAX 20
void input(int[][3]);
void output(int[][3]);
void transpose(int[][3], int[][3]);
int main()
{
    int arr1[MAX][3], arr2[MAX][3], m, n;
    printf("Enter the size of matrix (rows,columns):");
    scanf("%d%d", &m, &n);
    arr1[0][0] = m;
    arr1[0][1] = n;
    input(arr1);
    transpose(arr1, arr2);
    output(arr2);
}
void input(int arr[MAX][3])
{
    int i, t;
    printf("\nEnter no. of non-zero elements: ");
    scanf("%d", &t);
    arr[0][2] = t;
    for (i = 1; i <= t; i++)
    {
        printf("\nEnter the triplet-%d (row,column,value): ",i);
        scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
}
void output(int arr[MAX][3])
{
    int i, n;
    n = arr[0][2];
    printf("\nAfter Transpose:\n");
    printf("\nRow\t\tColumn\t\tValue\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}
void transpose(int arr1[MAX][3], int arr2[MAX][3])
{
    int i, j, k, n;
    arr2[0][0] = arr1[0][1];
    arr2[0][1] = arr1[0][0];
    arr2[0][2] = arr1[0][2];
    k = 1;
    n = arr1[0][2];
    for (i = 0; i < arr1[0][1]; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == arr1[j][1])
            {
                arr2[k][0] = i;
                arr2[k][1] = arr1[j][0];
                arr2[k][2] = arr1[j][2];
                k++;
            }
        }
    }
}