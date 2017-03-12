#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int w[n],p=1,i,sm=0;
    for (i=0;i<n;i++) {
        scanf("%d",&w[i]);
        sm+=w[i];
        p*=2;
    }
    int k,kk,s,d,dm=sm;
    for (k=0;k<p;k++) {
        kk=k;
        s=0;
        for (i=0;i<n;i++) {
            s+=w[i]*(kk%2);
            kk/=2;
        }
        d=2*s-sm;
        if (d<0)
            d=-d;
        if (d<dm)
            dm=d;
    }
    printf("%d\n",dm);
    return 0;
}