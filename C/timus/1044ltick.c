#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    n/=2;
    long long v[9*n+1],i,ii,k=1;
    int s;
    for (i=0;i<=9*n;i++)
        v[i]=0;
    for (i=0;i<n;i++)
        k*=10;
    for (i=0;i<k;i++) {
        ii=i;
        s=0;
        while (ii>0) {
            s+=ii%10;
            ii/=10;
        }
        v[s]++;
    }
    k=0;
    for (i=0;i<=9*n;i++)
        k+=v[i]*v[i];
    printf("%Ld\n",k);
    return 0;
}