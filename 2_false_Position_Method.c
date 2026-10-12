#include <stdio.h>
#include<math.h>
#define f(x) (x*x*x - x - 4)

int main() {
    float x1,x2,x3,ep,temp,delta;
    float y1 , y2 , y3;
    int i=0;

    printf("Enter Initial Approximation for x1 and x2\n");
    scanf("%f %f",&x1,&x2);
    printf("\nEnter allowed error and delta\n");
    scanf("%f %f",&ep,&delta);
    
    y1=f(x1);
    y2=f(x2);

    if (y1*y2 > 0){
        printf("Initial values are unsuitable");
        return 0;
    }
    do{
        i++;
        x3 = (x1*y2 - x2*y1) / (y2-y1);
        y3 = f(x3);

        printf("x1 = %.4f  x2 = %.4f  x3 = %.4f  f(x3) = %.4f  Iteration no. = %d\n" , x1, x2, x3, y3, i);

        if(y1*y3 < 0){
            x2 = x3;
            y2 = y3;
        }
        else{
            x1 = x3;
            y1 = y3;
        }
    }while(fabs(y3) > ep);

    printf("\nRoot = %.4f",x3);
    return 0;
}