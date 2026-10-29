#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, degree, max_iter;
    float a[20], b[20], c[20];
    float x0, x1, ep;

    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficients in descending order:\n");
    for(i = 0; i <= degree; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("Enter initial value of x0: ");
    scanf("%f", &x0);

    printf("Enter allowed error (ep): ");
    scanf("%f", &ep);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    for(i = 1; i <= max_iter; i++)
    {
        b[0] = a[0];

        for(j = 1; j <= degree; j++)
        {
            b[j] = a[j] + x0 * b[j-1];
        }

        c[0] = b[0];

        for(j = 1; j < degree; j++)
        {
            c[j] = b[j] + x0 * c[j-1];
        }

        if(fabs(c[degree-1]) < 0.000001)
        {
            printf("Denominator is too small.");
            return 0;
        }

        x1 = x0 - b[degree] / c[degree-1];

        printf("Iteration %d: x = %f\n", i, x1);

        if(fabs(x1 - x0) < ep)
        {
            printf("\nApproximate root = %f", x1);
            printf("\nNumber of iterations = %d", i);
            return 0;
        }

        x0 = x1;
    }

    printf("\nSolution does not converge in %d iterations.",
           max_iter);

    return 0;
}
