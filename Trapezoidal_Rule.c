#include <stdio.h>

float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    int n, i;
    float a, b, h, sum1, sum2 = 0, integral;

    printf("Enter values of a, b and n:\n");
    scanf("%f %f %d", &a, &b, &n);

    h = (b - a) / n;
    sum1 = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        sum2 = sum2 + f(a + i * h);
    }

    integral = (h / 2) * (sum1 + 2 * sum2);

    printf("Value of Integral by Trapezoidal Rule = %f",
           integral);

    return 0;
}
