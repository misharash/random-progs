#include <stdio.h>
#include <math.h>
int main() {
    double a,b;
    scanf("%lf%lf",&a,&b);
    double s=(a*a+b*b)/4+a*b/sqrt(2);
    printf("%0.9lf\n",s);
    return 0;
}