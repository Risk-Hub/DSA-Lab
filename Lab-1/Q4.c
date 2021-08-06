#include <stdio.h>
float add(float, float);
float sub(float, float);
float multi(float, float);
float div(float, float);
float main()
{
    float a, b;
    printf("\nEnter two numbers: ");
    scanf("%f%f", &a, &b);
    printf("\nAddition = %.2f", add(a, b));
    printf("\nSubtraction = %.2f", sub(a, b));
    printf("\nMultiplication = %.2f", multi(a, b));
    printf("\nDivision = %.2f", div(a, b));
}
float add(float a, float b)
{
    return a + b;
}
float sub(float a, float b)
{
    return a - b;
}
float multi(float a, float b)
{
    return a * b;
}
float div(float a, float b)
{
    return a / b;
}