
#include <math.h>
#include <stdio.h>

int main()
{
    int i, j, k, n, m;
    float a[50][50], x[50], bigerror, error, ep, sum, temp;

    printf("Enter the number of equations\n");
    scanf("%d", &n);

    printf("Enter the maximum number of iterations\n");
    scanf("%d", &m);

    printf("Enter the allowed error\n");
    scanf("%f", &ep);

    printf("\nEnter elements of the augmented matrix (rowwise)\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);

    for(i = 0; i < n; i++)
        x[i] = 0;

    for(k = 1; k <= m; k++)
    {
        bigerror = 0;

        for(i = 0; i < n; i++)
        {
            if(a[i][i] == 0)
            {
                printf("Division by zero. Rearrange the equations.");
                return 0;
            }

            sum = 0;

            for(j = 0; j < n; j++)
                if(i != j)
                    sum = sum + a[i][j] * x[j];

            temp = (a[i][n] - sum) / a[i][i];

            error = fabs((temp - x[i]) / temp);

            if(error > bigerror)
                bigerror = error;

            x[i] = temp;
        }

        if(bigerror <= ep)
        {
            printf("\nSolution converge in %d iterations\n", k);

            for(i = 0; i < n; i++)
                printf("x[%d]=%f\n", i, x[i]);

            return 0;
        }
    }

    printf("\nSolution does not converge in %d iterations", m);

    return 0;
}
