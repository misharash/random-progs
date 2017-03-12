#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
typedef struct {
    double x,y;
} coords;
double dist(coords dot1,coords dot2) {
    return hypot(dot1.x-dot2.x,dot1.y-dot2.y);
}
int main() {
    int n;
    double r;
    scanf("%d%lf",&n,&r);
    if (n==1) {
        printf("%0.2lf\n",2*M_PI*r);
        return 0;
    }
    int i;
    coords dots[n];
    for (i=0;i<n;i++)
        scanf("%lf%lf",&dots[i].x,&dots[i].y);
    double l=dist(dots[n-1],dots[0])+2*M_PI*r;
    for (i=1;i<n;i++)
        l+=dist(dots[i-1],dots[i]);
    printf("%0.2lf\n",l);
    return 0;
}