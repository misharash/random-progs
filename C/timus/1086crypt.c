#include <stdio.h>
int main() {
    long long p[16000];
    int i,k=0,ep,j;
    for (i=2;k<16000;i++) {
        ep=1;
        for (j=0;(p[j]*p[j]<=i)&&(j<k);j++)
            if (!(i%p[j])) {
                ep=0;
                break;
            }
        if (ep) {
            p[k]=i;
            k++;
        }
    }
    scanf("%d",&k);
    for (i=0;i<k;i++) {
        scanf("%d",&j);
        printf("%d\n",p[j-1]);
    }
    return 0;
}
