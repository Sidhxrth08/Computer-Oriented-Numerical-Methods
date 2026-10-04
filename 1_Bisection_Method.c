#include <stdio.h>
#include<math.h>
#define f(x) ((x*x*x)-(4*x)-9)
float main() {
    float a=2, b=3, E=0.0001;
    float p=f(a) , q=f(b);
    float r ,c;
    int i=0;

    if(p*q > 0){
        printf("Initial roots are not suitable");
        printf("%f %f",p,q);
    }
    else{
        do{
            i=i+1;
            c = (a+b)/2;
            r = f(c);

            if(r == 0){
                printf("Exact root of equation: %.4f \n",c);
                printf("Number of iterations: %d",i);
            }
            else if(p*r < 0){
                b = c;
                q = r;
            }
            else{
                a = c;
                p = r;
            }
        }while(b-a >= E);
    }

    printf("Approximate root of equation is: %.4f \n",(a + b)/2);
    printf("Number of iterations: %d",i);


    return 0;
}