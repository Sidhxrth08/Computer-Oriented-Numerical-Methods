#include <stdio.h>

#define MAX_POINTS 100

int main(void)
{
    int n, i, j;
    double x[MAX_POINTS], y[MAX_POINTS];
    double diff[MAX_POINTS][MAX_POINTS] = {{0}};
    double xq, product, result;

    printf("Enter the number of points: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_POINTS) {
        printf("Invalid number of points.\n");
        return 1;
    }

    printf("Enter each x and y value:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%lf %lf", &x[i], &y[i]) != 2) {
            printf("Invalid input.\n");
            return 1;
        }

        diff[i][0] = y[i];

        for (j = 0; j < i; j++) {
            if (x[i] == x[j]) {
                printf("The x values must be distinct.\n");
                return 1;
            }
        }
    }

    printf("Enter the x value to interpolate: ");
    if (scanf("%lf", &xq) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Divided difference table */
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diff[i][j] =
                (diff[i + 1][j - 1] - diff[i][j - 1]) /
                (x[i + j] - x[i]);
        }
    }

    printf("\nDivided difference table:\n");
    printf("x\t\ty");
    for (j = 1; j < n; j++)
        printf("\tD%d", j);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%.2f\t%.4f", x[i], y[i]);
        for (j = 1; j < n - i; j++)
            printf("\t%.2f", diff[i][j]);
        printf("\n");
    }

    /* Evaluate the Newton polynomial */
    result = diff[0][0];
    product = 1.0;

    for (j = 1; j < n; j++) {
        product *= xq - x[j - 1];
        result += diff[0][j] * product;
    }

    printf("\nInterpolated value at %.3f is %.6f\n", xq, result);
    return 0;
}