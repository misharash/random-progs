#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
typedef struct {
    double x,y;
} coords;
double dist(coords dot1,coords dot2) {
    return hypot(dot1.x-dot2.x,dot1.y-dot2.y);
}
double angle(coords dot1,coords dot2,coords dot3) {
    double l1=dist(dot1,dot2),l2=dist(dot2,dot3);
    double modp=l1*l2;
    double scalp=(dot2.x-dot1.x)*(dot3.x-dot2.x)+(dot2.y-dot1.y)*(dot3.y-dot2.y);
    return acos(scalp/modp);
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
    if (n==2) {
        printf("%0.2lf\n",2*M_PI*r+2*dist(dots[0],dots[1]));
        return 0;
    }
    double l=dist(dots[n-1],dots[0])+r*angle(dots[n-1],dots[0],dots[1]);
    l+=dist(dots[n-2],dots[n-1])+r*angle(dots[n-2],dots[n-1],dots[0]);
    for (i=1;i<n-1;i++)
        l+=dist(dots[i-1],dots[i])+r*angle(dots[i-1],dots[i],dots[i+1]);
    printf("%0.2lf\n",l);
    return 0;
}