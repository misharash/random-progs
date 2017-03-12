#include <stdio.h>
#include <math.h>
#define H_G 10
#define H_PI 3.1415926535
int main() {
    long v;
    int a;
    double k;
    scanf("%ld%d%lf",&v,&a,&k);
    double l=k/(k-1)*v*v/H_G*sin((double)H_PI/90*a);
    printf("%0.2lf\n",l);
    return 0;
}