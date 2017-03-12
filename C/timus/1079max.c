#include <stdio.h>
int main() {
    long int n,i;
    scanf("%ld",&n);
    while (n) {
        long long int a[n+1],max;
        a[0]=0;
        a[1]=1;
        max=1;
        for (i=2;i<=n;i++) {
            if (i%2)
                a[i]=a[i/2]+a[i/2+1];
            else
                a[i]=a[i/2];
            if (a[i]>max)
                max=a[i];
        }
        printf("%Ld\n",max);
        scanf("%ld",&n);
    }
    return 0;
}