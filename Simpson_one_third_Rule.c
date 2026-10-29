
#include <stdio.h>

int main()
{
    int n, i;
    float h, x[50], y[50], sum, sum2 = 0,
          sum4 = 0, integral;

    printf("Enter n:\n");
    scanf("%d", &n);

    if (n <= 0 || n % 2 != 0 || n >= 50)
    {
        printf("n must be even and between 1 and 49.\n");
        return 0;
    }

    printf("Enter values of x and y:\n");

    for (i = 0; i <= n; i++)
        scanf("%f %f", &x[i], &y[i]);

    h = x[2] - x[1];
    sum = y[0] + y[n];

    for (i = 1; i < n; i += 2)
        sum4 = sum4 + y[i];

    for (i = 2; i < n; i += 2)
        sum2 = sum2 + y[i];

    integral = (h / 3) * (sum + 4 * sum4 + 2 * sum2);

    printf("Value of Integral by Simpson's one third Rule = %f",
           integral);

    return 0;
}
