#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,k,n;
    float a[50][50],x[50],u,sum;

    printf("Enter the number of equations\n");
    scanf("%d",&n);

    printf("\nEnter elements of the augmented matrix (rowwise)\n");

    for(i=0;i<n;i++)
        for(j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);

    for(k=0;k<n-1;k++)
        for(i=k+1;i<n;i++)
        {
            u=a[i][k]/a[k][k];

            for(j=0;j<n+1;j++)
                a[i][j]=a[i][j]-u*a[k][j];
        }

    printf("\nUPPER TRIANGULAR MATRIX IS\n");

    for(i=0;i<n;i++)
    {
        x[n]=a[n][n+1]/a[n][n];

        for(j=0;j<n+1;j++)
            printf("%8.2f\t",a[i][j]);

        printf("\n");
    }

    x[n-1]=a[n-1][n]/a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        sum=0;

        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*x[j];

        x[i]=(a[i][n]-sum)/(float)a[i][i];
    }

    printf("\nThe solution is\n");

    for(i=0;i<n;i++)
        printf("x[%d]=%f\n",i,x[i]);

    return 0;
}
