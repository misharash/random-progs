#include <stdio.h>
int sgn(int n) {
    if (n) {
        if (n>0)
            return 1;
        return -1;
    }
    return 0;
}
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int i,f[b-a+1];
    for (i=0;i<=b-a;i++)
        scanf("%d",&f[i]);
    int k=1,d=0,dp=sgn(f[1]-f[0]);
    for (i=2;i<=b-a;i++) {
        d=sgn(f[i]-f[i-1]);
        if (d!=0) {
            if ((d!=dp)&&(dp!=0)) {
                k++;
                d=0;
            }
            dp=d;
        }
    }
    printf("%d\n",k);
    return 0;
}