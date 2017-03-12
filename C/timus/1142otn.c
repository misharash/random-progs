#include <stdio.h>
int main() {
    long long fac[11];
    int i;
    fac[0]=1;
    for (i=1;i<11;i++)
        fac[i]=i*fac[i-1];
    int n;
    long long k;
    scanf("%d",&n);
    while (n!=-1) {
        k=fac[n]+1;
        for (i=2;i<n;i++)
            k+=fac[n]/fac[i]*(n-i+1); // C_n^k*P_{n-k+1}=n!/k!(n-k)!*(n-k+1)!
        printf("%Ld\n",k);
        scanf("%d",&n);
    }
    return 0;
}