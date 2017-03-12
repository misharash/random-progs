#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    long long k,t;
    for (i=0;i<n-1;i++) {
        scanf("%Ld",&k);
        k--;
        t=llrint(sqrtl(2*(long double)k));
        if ((t*(t+1)/2==k)||(t*(t-1)/2==k))
            printf("1 ");
        else
            printf("0 ");
    }
    scanf("%Ld",&k);
    k--;
    t=llrint(sqrtl(2*(long double)k));
    if ((t*(t+1)/2==k)||(t*(t-1)/2==k))
        printf("1");
    else
        printf("0");
    return 0;
}