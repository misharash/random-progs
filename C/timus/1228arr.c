#include <stdio.h>
int main() {
    int n,i;
    scanf("%d",&n);
    long long k,pk,v[n];
    scanf("%Ld",&k);
    for (i=0;i<n;i++) {
        pk=k;
        scanf("%Ld",&k);
        v[i]=pk/k-1;
    }
    for (i=0;i<n-1;i++)
        printf("%Ld ",v[i]);
     printf("%Ld\n",v[n-1]);
    return 0;
}