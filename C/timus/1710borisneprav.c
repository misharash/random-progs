#include <stdio.h>
#include <math.h>
typedef struct {
    double x,y;
} coords;
double csqr(coords a) {
    return a.x*a.x+a.y*a.y;
}
double cmod(coords a) {
    return hypot(a.x,a.y);
}
coords cxn(coords a,double x) {
    coords b;
    b.x=a.x*x;
    b.y=a.y*x;
    return b;
}
coords csum(coords a,coords b) {
    coords c;
    c.x=a.x+b.x;
    c.y=a.y+b.y;
    return c;
}
coords cdif(coords a,coords b) {
    coords c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}
int main() {
    coords a,b,c;
    scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    coords ab=cdif(b,a),bc=cdif(c,b),ac=cdif(c,a);
    double cosbac=(csqr(ab)+csqr(ac)-csqr(bc))/2/cmod(ab)/cmod(ac),k=2*cmod(ab)*cosbac/cmod(ac)-1;
    //printf("%lf %lf\n",cosbac,k);
    if ((k<0.0000001)||(fabs(k-1)<0.0000001))
        printf("YES\n");
    else {
        coords ac2=cxn(ac,k),c2=csum(a,ac2);
        printf("NO\n%0.10lf %0.10lf\n%0.10lf %0.10lf\n%0.10lf %0.10lf\n",a.x,a.y,b.x,b.y,c2.x,c2.y);
    }
    return 0;
}