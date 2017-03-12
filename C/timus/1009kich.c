#include <stdio.h>
int k;
long long kichr[30][2];
long long kich(int n,int nn) {
    if (kichr[n][nn])
        return kichr[n][nn];
    long long r=(k-1)*kich(n-1,1);
    if (nn)
        r+=kich(n-1,0);
    return kichr[n][nn]=r;
}
int main() {
    int n,i;
    scanf("%d%d",&n,&k);
    kichr[0][0]=1;
    kichr[0][1]=1;
    for (i=1;i<=n;i++) {
        kichr[i][0]=0;
        kichr[i][1]=0;
    }
    long long c=kich(n,0);
    printf("%Ld\n",c);
}