
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n;
    float a[50][50], temp, x[50], c;

    printf("Enter the number of equations\n");
    scanf("%d", &n);

    printf("Enter elements of the augmented matrix (rowwise)\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n + 1; j++)
            scanf("%f", &a[i][j]);

    for(k = 0; k < n; k++)
    {
        if(a[k][k] == 0)
        {
            printf("\nDivision by zero\n");
            return 0;
        }

        temp = a[k][k];

        for(j = k; j < n + 1; j++)
            a[k][j] = a[k][j] / temp;

        for(i = 0; i < n; i++)
        {
            if(i != k)
            {
                c = a[i][k];

                for(j = k; j < n + 1; j++)
                    a[i][j] = a[i][j] - c * a[k][j];
            }
        }
    }

    printf("\nThe solution is\n");

    for(i = 0; i < n; i++)
    {
        x[i] = a[i][n];
        printf("x[%d]=%f\n", i, x[i]);
    }

    return 0;
}
