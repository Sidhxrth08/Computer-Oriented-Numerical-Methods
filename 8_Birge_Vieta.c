#include <stdio.h>
#include <math.h>

int main(void)
{
    float arr[] = {1, 7, 24, -15};
    float a;
    float approx, approx_old;
    int count = 0;

    printf("Enter Initial Approximation:\n");
    scanf("%f", &a);

    while (1)
    {
        float b[4] = {arr[0]};
        float fx = arr[0];
        float f_der = 0.0f;

        /* Calculate f(x) */
        for (int i = 0; i < 3; i++)
        {
            fx = fx * a + arr[i + 1];
            b[i + 1] = fx;
        }

        /* Calculate f'(x) */
        f_der = b[0];

        for (int i = 0; i < 2; i++)
        {
            f_der = f_der * a + b[i + 1];
        }

        if (fabsf(f_der) < 0.000001f)
        {
            printf("Derivative is too small.\n");
            return 0;
        }

        approx_old = a;
        approx = a - (fx / f_der);
        count++;

        printf("Iteration %d -> %f\n", count, approx);

        if (fabsf(approx - approx_old) < 0.0001f)
        {
            printf("Root -> %f\n", approx);
            printf("Total Iterations -> %d\n", count);
            break;
        }

        a = approx;
    }

    return 0;
}