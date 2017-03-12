#include <stdio.h>
int main() {
    long n,k;
    scanf("%ld%ld",&n,&k);
    long i,p=1,t=0;
    while ((p<n)&&(p<k)) {
        p*=2;
        t++;
    }
    n-=p;
    if (n>0) {
        t+=n/k;
        if (n%k)
            t++;
    }
    printf("%ld\n",t);
    return 0;
}