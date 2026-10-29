#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)+7*(x)*(x)+24*(x)-15)

int main()
{
    int i, n;
    float a[20], b[20], c[20];
    float x0, x1, ep;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficients in descending order:\n");
    for(i = 0; i <= n; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("Enter initial value of x0: ");
    scanf("%f", &x0);

    printf("Enter allowed error (ep): ");
    scanf("%f", &ep);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        int j, degree;
        degree = sizeof(a) / sizeof(a[0]);

        b[0] = a[0];

        for(j = 1; j <= 3; j++)
        {
            b[j] = a[j] + x0 * b[j-1];
        }

        c[0] = b[0];

        for(j = 1; j < 3; j++)
        {
            c[j] = b[j] + x0 * c[j-1];
        }

        if(fabs(c[2]) < 0.000001)
        {
            printf("Denominator is too small.");
            return 0;
        }

        x1 = x0 - b[3] / c[2];

        printf("Iteration %d: x = %f\n", i, x1);

        if(fabs(x1 - x0) < ep)
        {
            printf("\nApproximate root = %f", x1);
            printf("\nNumber of iterations = %d", i);
            return 0;
        }

        x0 = x1;
    }

    printf("\nSolution does not converge in %d iterations.", n);

    return 0;
}