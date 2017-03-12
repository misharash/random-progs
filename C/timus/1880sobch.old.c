#include <stdio.h>
int main() {
    int n,j;
    scanf("%d",&n);
    int kk=n,k,i,ks[n];
    long s[n],sc;
    for (i=0;i<n;i++)
        ks[i]=0;
    for (j=0;j<n;j++)
        scanf("%ld",&s[j]);
    for (i=0;i<2;i++) {
        scanf("%d",&n);
        for (j=0;j<n;j++) {
            scanf("%ld",&sc);
            for (k=0;k<kk;k++)
                if (sc==s[k])
                    ks[k]++;
        }
    }
    k=0;
    for (i=0;i<n;i++)
        if (ks[i]>=2)
            k++;
    printf("%d\n",k);
    return 0;
}