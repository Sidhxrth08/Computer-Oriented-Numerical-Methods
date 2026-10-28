#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

int main(void)
{
    int n, i, j, k;
    double x[MAX_POINTS], y[MAX_POINTS];
    double diff[MAX_POINTS][MAX_POINTS] = {{0}};
    double xq, h, u, term, factorial, result, tolerance;

    printf("Enter the number of points: ");
    if (scanf("%d", &n) != 1 || n < 2 || n > MAX_POINTS) {
        printf("Invalid number of points.\n");
        return 1;
    }

    printf("Enter each x and y value:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%lf %lf", &x[i], &y[i]) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    h = x[1] - x[0];
    if (h <= 0) {
        printf("The x values must be in increasing order.\n");
        return 1;
    }

    tolerance = 1e-9 * fmax(1.0, fabs(h));
    for (i = 1; i < n; i++) {
        if (fabs((x[i] - x[i - 1]) - h) > tolerance) {
            printf("Newton forward difference requires equally spaced x values.\n");
            return 1;
        }
    }

    printf("Enter the x value to interpolate: ");
    if (scanf("%lf", &xq) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (xq < x[0] || xq > x[n - 1]) {
        printf("The value is outside the tabulated range.\n");
        return 1;
    }

    /* Forward difference table */
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            if (j == 1)
                diff[i][j] = y[i + 1] - y[i];
            else
                diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    /* Choose the interval at or just before xq */
    k = 0;
    while (k < n - 2 && xq > x[k + 1])
        k++;

    u = (xq - x[k]) / h;
    result = y[k];
    term = 1.0;
    factorial = 1.0;

    for (i = 1; i < n - k; i++) {
        term *= u - (i - 1);
        factorial *= i;
        result += (term / factorial) * diff[k][i];
    }

    printf("Interpolated value at %.3f is %.6f\n", xq, result);
    return 0;
}
