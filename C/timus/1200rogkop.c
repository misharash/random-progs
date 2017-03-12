#include <stdio.h>
#include <math.h>
int main() {
    double a,b;
    scanf("%lf%lf",&a,&b);
    int k;
    scanf("%d",&k);
    int i,j,x,y,xm=0,ym=0;
    double p,pm=0;
    for (i=0;i<=k;i++) {
        x=rint(round((a-b+2*i)/4)-1);
        for (j=0;j<3;j++) {
            y=i-x;
            if (x<0) {
                x=0;
                y=i;
            }
            else
                if (y<0) {
                    x=i;
                    y=0;
                }
            p=a*x-x*x+b*y-y*y;
            if (p>pm) {
                pm=p;
                xm=x;
                ym=y;
            }
            else
                if (fabs(p-pm)<0.001)
                    if (x<xm) {
                        xm=x;
                        ym=y;
                    }
                    else
                        if (x==xm)
                            if (y<ym)
                                ym=y;
            x++;
        }
    }
    printf("%0.2lf\n%d %d\n",pm,xm,ym);
    return 0;
}