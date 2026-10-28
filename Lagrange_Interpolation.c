#include <stdio.h>

#define MAX_POINTS 100

int main(void)
{
    int n, i, j;
    double x[MAX_POINTS], y[MAX_POINTS];
    double xq, term, result = 0.0;

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

    for (i = 0; i < n; i++) {
        term = y[i];

        for (j = 0; j < n; j++) {
            if (j != i)
                term *= (xq - x[j]) / (x[i] - x[j]);
        }

        result += term;
    }

    printf("Interpolated value at %.3f is %.6f\n", xq, result);
    return 0;
}
