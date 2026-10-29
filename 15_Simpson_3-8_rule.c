
#include <stdio.h>

int main()
{
    int n, i;
    float h, x[50], y[50], sum, sum2 = 0,
          sum3 = 0, integral;

    printf("Enter n:\n");
    scanf("%d", &n);

    if (n <= 0 || n % 3 != 0 || n >= 50)
    {
        printf("n must be a multiple of 3 and less than 50.\n");
        return 0;
    }

    printf("Enter values of x and y:\n");

    for (i = 0; i <= n; i++)
        scanf("%f %f", &x[i], &y[i]);

    h = x[1] - x[0];
    sum = y[0] + y[n];

    for (i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            sum2 = sum2 + y[i];
        else
            sum3 = sum3 + y[i];
    }

    integral = (3 * h / 8) * (sum + 2 * sum2 + 3 * sum3);

    printf("Value of Integral by Simpson's three eighth Rule = %f",
           integral);

    return 0;
}
