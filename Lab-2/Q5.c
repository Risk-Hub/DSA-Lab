#include <stdio.h>
struct distance
{
    int km, m;
};
int main()
{
    struct distance d1, d2, d3;
    int temp;
    printf("\nEnter first distance(in km and m resp): ");
    scanf("%d%d", &d1.km, &d1.m);
    printf("\nEnter secoond distance(in km and m resp): ");
    scanf("%d%d", &d2.km, &d2.m);
    d3.m = d1.m + d2.m;
    temp = d3.m;
    d3.km = d1.km + d2.km;
    if (d3.m > 1000)
    {
        d3.m %= 1000;
        d3.km += temp / 1000;
    }
    printf("\nThe resultant distance is %d km %d m", d3.km, d3.m);
}