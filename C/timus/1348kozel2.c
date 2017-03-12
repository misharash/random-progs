#include <stdio.h>
#include <math.h>
typedef struct {
    double x,y;
} coords;
double dist(coords dot1,coords dot2) {
    return hypot(dot2.x-dot1.x,dot2.y-dot1.y);
}
int main() {
    coords a,b,c;
    double l;
    scanf("%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&l);
    double ab=dist(a,b),bc=dist(b,c),ac=dist(a,c),p=(ab+bc+ac)/2,s=sqrt(p*(p-ab)*(p-bc)*(p-ac)),dmax=fmax(fmax(ac,bc)-l,0),dcab=2*s/ab,gip=hypot(ab,dcab),dmin;
    if ((gip>bc-0.0001)&&(gip>ac-0.0001))
        dmin=dcab;
    else
        dmin=fmin(ac,bc);
    dmin=fmax(dmin-l,0);
    //printf("%lf %lf %lf %lf %lf\n",ab,bc,ac,p,s);
    printf("%0.2lf\n%0.2lf\n",dmin,dmax);
    return 0;
}