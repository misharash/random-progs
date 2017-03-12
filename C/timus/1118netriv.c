#include <stdio.h>
long long int sdel(long int n) {
    long long int r=1;
    long int k;
    for (k=2;k*k<n;k++) {
        if (!(n%k))
            r+=k+n/k;
    }
    if (n==k*k)
        r+=k;
    return r;
}
int main() {
    long int i,j;
    scanf("%ld%ld",&i,&j);
    if (i==1) {
        printf("1\n");
        return 0;
    }
    long int n,nn=j;
    long long sd,sdo=sdel(j);
    for (n=j;n>=i;n--) {
        sd=sdel(n);
        if (sd==1) {
            nn=n;
            break;
        }
        if (sd*nn<sdo*n) {
            sdo=sd;
            nn=n;
        }
    }
    printf("%ld\n",nn);
    return 0;
}