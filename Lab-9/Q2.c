#include <stdio.h>
int small(int[], int, int);
void selectionSort(int[], int);
int main()
{
    int a[100], n, num, beg, end, mid, count = 0;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements in the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    printf("\nThe sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter the number to be searched: ");
    scanf("%d", &num);
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == num)
        {
            printf("\n%d is present in the array at position: %d", num, mid + 1);
            count++;
            break;
        }
        else if (a[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    if (beg > end && count == 0)
    {
        printf("\n%d is not found in the array", num);
    }
}
int small(int a[], int k, int n)
{
    int pos = k, small = a[k];
    for (int i = k + 1; i < n; i++)
    {
        if (a[i] < small)
        {
            small = a[i];
            pos = i;
        }
    }
    return pos;
}
void selectionSort(int a[], int n)
{
    int k, pos, temp;
    for (k = 0; k < n; k++)
    {
        pos = small(a, k, n);
        temp = a[k];
        a[k] = a[pos];
        a[pos] = temp;
    }
}