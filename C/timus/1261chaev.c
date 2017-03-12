#include <stdio.h>
#define tridigits 20
int main() {
    long n;
    scanf("%ld",&n);
    int d[tridigits],k=0,i;
    for (i=0;i<tridigits;i++)
        d[i]=0;
    long nn=n;
    while (nn>0) {
        d[k]=nn%3;
        nn/=3;
        k++;
    }
    long p=1;
    for (i=0;i<=k+1;i++) {
        if (d[i]>1) {
            d[i+1]++;
            d[i]=0;
        }
        nn+=p*d[i];
        p*=3;
    }
    if (nn<=n)
        nn+=p;
    printf("%ld %ld\n",nn,nn-n);
    return 0;
}