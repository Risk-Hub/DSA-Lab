#include <stdio.h>
int main()
{
    int a = 4;
    int *p1 = &a;
    printf("\nSize of int pointer = %lu", sizeof(*p1));
    char b = 'X';
    char *p2 = &b;
    printf("\nSize of char pointer = %lu", sizeof(*p2));
    float c = 3.14;
    float *p3 = &c;
    printf("\nSize of float pointer = %lu", sizeof(*p3));
    double d = 3.14;
    double *p4 = &d;
    printf("\nSize of double pointer = %lu", sizeof(*p4));
    long int e = 10.01;
    long int *p5 = &e;
    printf("\nSize of long int pointer = %lu", sizeof(*p5));
}