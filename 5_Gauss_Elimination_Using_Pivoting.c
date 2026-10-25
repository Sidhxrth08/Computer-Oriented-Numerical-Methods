
#include <math.h>
#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[50][50], x[50], u, q, temp, sum, max, p, m;

    printf("Enter the number of equations\n");
    scanf("%d", &n);

    printf("\nEnter elements of the augmented matrix (rowwise)\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);

    for(k = 0; k < n - 1; k++)
    {
        max = fabs(a[k][k]);
        p = k;

        for(m = k + 1; m < n; m++)
        {
            if(fabs(a[(int)m][k]) > max)
            {
                max = fabs(a[(int)m][k]);
                p = m;
            }
        }

        if(p != k)
        {
            for(q = k; q < n + 1; q++)
            {
                temp = a[k][(int)q];
                a[k][(int)q] = a[(int)p][(int)q];
                a[(int)p][(int)q] = temp;
            }
        }

        for(i = k + 1; i < n; i++)
        {
            u = a[i][k] / a[k][k];

            for(j = k; j < n + 1; j++)
                a[i][j] = a[i][j] - u * a[k][j];
        }
    }

    printf("\nUPPER TRIANGULAR MATRIX IS\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n + 1; j++)
            printf("%8.2f\t", a[i][j]);

        printf("\n");
    }

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--)
    {
        sum = 0;

        for(j = i + 1; j < n; j++)
            sum = sum + a[i][j] * x[j];

        x[i] = (a[i][n] - sum) / a[i][i];
    }

    printf("\nThe solution is\n");

    for(i = 0; i < n; i++)
        printf("x[%d] = %f\n", i, x[i]);

    return 0;
}
