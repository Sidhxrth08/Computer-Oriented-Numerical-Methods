
#include <stdio.h>
#include <math.h>

#define f(x) ((x)*(x)*(x)-(x)-2)
#define td(x) (3*(x)*(x)-1)

int main()
{
    int i, n;
    float x0, x1, ep;

    printf("Enter initial value of x0: ");
    scanf("%f", &x0);

    printf("Enter allowed error (ep): ");
    scanf("%f", &ep);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        if(fabs(td(x0)) < 0.000001)
        {
            printf("Derivative is too small.");
            return 0;
        }

        x1 = x0 - f(x0) / td(x0);

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
