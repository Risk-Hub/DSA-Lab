#include <stdio.h>
void main()
{
    int a[10][10], b[10][3], m, n, s = 0, i, j;
    printf("\nEnter the order of the matrix(M x N): ");
    scanf("%d%d", &m, &n);
    printf("\nEnter the elements in the matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("The given matrix is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                b[s][0] = a[i][j];
                b[s][1] = i;
                b[s][2] = j;
                s++;
            }
        }
    }
    printf("\nThe sparse matrix is given by:-\n");
    printf("Value  Row   Column\n");
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
}