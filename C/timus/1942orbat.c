#include <stdio.h>
#include <math.h>
int isqr(int a) {
    return a*a;
}
int imin(int a,int b) {
    if (a<b)
        return a;
    return b;
}
int main() {
    int n,i,j,k[1000][1000];
    for (i=0;i<1000;i++)
        for (j=0;j<1000;j++)
            k[i][j]=0;
    scanf("%d",&n);
    double x,y;
    for (i=0;i<n;i++) {
        scanf("%lf%lf",&x,&y);
        x+=200;
        y+=200;
        k[lrint(x*1000)%1000][lrint(y*1000)%1000]++;
    }
    int kmax=k[0][0],s2max=0,s2;
    for (i=0;i<1000;i++)
        for (j=0;j<1000;j++) {
            s2=isqr(imin(i,1000-i))+isqr(imin(j,1000-j));
            if (k[i][j]>kmax) {
                kmax=k[i][j];
                s2max=s2;
            }
            else
                if ((k[i][j]==kmax)&&(s2<s2max))
                    s2max=s2;
        }
    double s=sqrt(s2max)/1000;
    printf("%d %0.5lf\n",kmax,s);
    return 0;
}
            