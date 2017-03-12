#include <stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int g[n];
    int i,k;
    for (i=0;i<n;i++)
        g[i]=0;
    for (i=0;i<m;i++) {
        scanf("%d",&k);
        g[k-1]++;
    }
    float p;
    for (i=0;i<n;i++) {
        p=100*((float) g[i])/m;
        printf("%0.2f%%\n",p);
    }
    return 0;
}